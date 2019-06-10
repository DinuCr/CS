// phos.c
// Copyright (c) 2018 J. M. Spivey

#include "phos.h"
#include "lib.h"
#include "hardware.h"
#include <string.h>

/* STORAGE ALLOCATION */

/* Stack space for processes is allocated from the space between the
   static data and the main stack. */

extern unsigned char __stack_limit[], __end[];

static unsigned char *__break = __end;

#define ROUNDUP(x, n)  (((x)+(n)-1) & ~((n)-1))

static void *sbrk(int inc) {
    inc = ROUNDUP(inc, 4);
    __break = (unsigned char *) ROUNDUP((unsigned) __break, 8);
    if (inc > __stack_limit - __break)
        panic("Can't allocate storage");
    void *result = __break;
    __break += inc;
    return result;
}


/* PROCESS TABLE */

#define NPROCS 16

static struct proc {
    int p_pid;                  /* Process ID (equal to index) */
    char p_name[16];            /* Name for debugging */
    unsigned p_state;           /* SENDING, RECEIVING, etc. */
    unsigned *p_sp;             /* Saved stack pointer */
    void *p_stack;              /* Stack area */
    unsigned p_stksize;         /* Stack size (bytes) */
    int p_priority;             /* Priority: 0 is highest */

    struct proc *p_waiting;     /* Processes waiting to send */
    int p_pending;              /* Whether HARDWARE message pending */
    int p_accept;               /* Processes who may send: ANY or pid */
    message *p_message;         /* Pointer to message buffer */

    struct proc *p_next;        /* Next process in ready or send queue */
} ptable[NPROCS];

/* Possible p_state values */
#define DEAD 0
#define READY 1
#define SENDING 2
#define RECEIVING 3
#define BOTH 4
#define IDLING 5

static struct proc *current;
static struct proc *idle_proc;

#define BLANK 0xdeadbeef        /* Filler for initial stack */

static void kprintf_setup(void);
static void kprintf_internal(char *fmt, ...);

/* phos_dump -- display process states */
static void phos_dump(void) {
    char *status = "ZASRBI";
    char buf1[16], buf2[16];

    kprintf_setup();
    kprintf_internal("\r\nPROCESS DUMP\r\n");

    // Our version of printf is a bit feeble, so the following is
    // rather painful.

    for (int pid = 0; pid < NPROCS; pid++) {
        struct proc *p = &ptable[pid];

        if (*p->p_name != '\0') {
            unsigned *z = (unsigned *) p->p_stack;
            while (*z == BLANK) z++;
            unsigned free = (char *) z - (char *) p->p_stack;

            if (pid < 10)
                sprintf(buf1, " %d", pid);
            else
                sprintf(buf1, "%d", pid);

            sprintf(buf2, "%u/%u", p->p_stksize-free, p->p_stksize);
            int w = strlen(buf2);
            if (w < 9) {
                memset(buf2+w, ' ', 9-w);
                buf2[9] = '\0';
            }

            kprintf_internal("%s: [%c] %x stk=%s %s\r\n",
                             buf1, status[p->p_state],
                             (unsigned) p->p_stack,
                             buf2, p->p_name);
        }
    }
}


/* PROCESS QUEUES */

/* ready_q -- one queue for each priority */
static struct queue {
    struct proc *q_head, *q_tail;
} ready_q[3];

/* make_ready -- add process to end of appropriate queue */
static void make_ready(struct proc *p) {
    if (p == idle_proc) return;

    p->p_state = READY;
    p->p_next = NULL;

    struct queue *q = &ready_q[p->p_priority];

    if (q->q_head == NULL)
        q->q_head = p;
    else
        q->q_tail->p_next = p;
     
    q->q_tail = p;
}

/* choose_proc -- pick a new process as current */
static void choose_proc(void) {
    for (int p = 0; p < 3; p++) {
        struct queue *q = &ready_q[p];
        if (q->q_head != NULL) {
            current = q->q_head;
            q->q_head = current->p_next;
            return;
        }
    }

    current = idle_proc;
}


/* SEND AND RECEIVE */

/* These versions of send and receive are invoked indirectly from user
   processes via the system calls send() and receive(). */

/* mini_send -- send a message */
static void mini_send(int dst, message *msg) {
    int src = current->p_pid;
    struct proc *pdst = &ptable[dst];

    if (pdst->p_state == RECEIVING
        && (pdst->p_accept == ANY || pdst->p_accept == src)) {
        // Receiver is waiting for us
        *(pdst->p_message) = *msg;
        pdst->p_message->m_sender = src;
        make_ready(pdst);
    } else {
        // Sender must wait by joining the receiver's queue
        current->p_state = SENDING;
        current->p_message = msg;
        current->p_next = NULL;

        if (pdst->p_waiting == NULL)
            pdst->p_waiting = current;
        else {
            struct proc *r = pdst->p_waiting;
            while (r->p_next != NULL)
                r = r->p_next;
            r->p_next = current;
        }

        choose_proc();
    }
}

/* mini_receive -- receive a message */
static void mini_receive(int accept, message *msg) {
    // First see if an interrupt is pending
    if (current->p_pending && (accept == ANY || accept == HARDWARE)) {
        current->p_pending = 0;
        msg->m_sender = HARDWARE;
        msg->m_type = INTERRUPT;
        return;
    }

    if (accept != HARDWARE) {
        // Now look to see if an acceptable process is waiting
        struct proc *prev = NULL;

        for (struct proc *psrc = current->p_waiting; psrc != NULL;
             psrc = psrc->p_next) {
            if (accept == ANY || accept == psrc->p_pid) {
                if (prev == NULL)
                    current->p_waiting = psrc->p_next;
                else
                    prev->p_next = psrc->p_next;

                *msg = *(psrc->p_message);
                msg->m_sender = psrc->p_pid;

                if (psrc->p_state == BOTH)
                    psrc->p_state = RECEIVING;
                else {
                    /* Non-preemptive: the receiver continues to run
                       even if the sender has less priority */
                    make_ready(psrc);
                }
                
                return;
            }
            prev = psrc;
        }
    }
     
    // No luck: we must wait.
    current->p_state = RECEIVING;
    current->p_accept = accept;
    current->p_message = msg;

    choose_proc();
}

static void mini_sendrec(int dst, message *msg) {
    int src = current->p_pid;
    struct proc *pdst = &ptable[dst];

    msg->m_sender = src;
    current->p_accept = dst;
    current->p_message = msg;

    if (pdst->p_state == RECEIVING
        && (pdst->p_accept == ANY || pdst->p_accept == src)) {
        // Receiver is waiting for us
        *(pdst->p_message) = *msg;
        pdst->p_message->m_sender = src;
        current->p_state = RECEIVING;
        make_ready(pdst);
    } else {
        // Sender must wait by joining the receiver's queue
        current->p_state = BOTH;
        current->p_next = NULL;
        if (pdst->p_waiting == NULL)
            pdst->p_waiting = current;
        else {
            struct proc *r = pdst->p_waiting;
            while (r->p_next != NULL)
                r = r->p_next;
            r->p_next = current;
        }
    }

    choose_proc();
}    



/* INTERRUPT HANDLING */

/* Interrupts send an INTERRUPT message (from HARDWARE) to a
   registered handler process.  The default beheviour is to disable
   the relevant IRQ in the interrupt handler, so that it can be
   re-enabled in the handler once it has reacted to the interrupt.

   We only deal with the 32 interrupts >= 0, not the 16 exceptions
   that are < 0 this way. */

static int handler[32];

/* mini_connect -- connect the current process to an IRQ */
static void mini_connect(int irq) {
    if (irq < 0) panic("Can't connect to CPU exceptions");
    current->p_priority = 0;
    handler[irq] = current->p_pid;
}

/* mini_setprio -- set process priority */
static void mini_setprio(unsigned p) {
    if (p > 2) panic("Bad priority %u\n", p);
    current->p_priority = p;
}

/* interrupt -- send interrupt message */
void interrupt(int dst) {
    struct proc *pdst = &ptable[dst];

    if (pdst->p_state == RECEIVING
        && (pdst->p_accept == ANY || pdst->p_accept == HARDWARE)) {
        // Receiver is waiting for an interrupt
        pdst->p_message->m_sender = HARDWARE;
        pdst->p_message->m_type = INTERRUPT;
        make_ready(pdst);
    } else {
        // Let's hope it's not urgent!
        pdst->p_pending = 1;
    }
}

/* schedule -- context switch */
static void schedule(void) {
    make_ready(current);
    choose_proc();
}

/* All interrupts are handled by this common handler, which disables the
   interrupt temporarily, then sends or queues a message to the registered
   handler task.  Normally the handler task will deal with the cause of the
   interrupt, then re-enable it. */

/* intr_handler -- handle an interrupt */
unsigned *intr_handler(unsigned *psp, int irq) {
    int hdlr;

    current->p_sp = psp;

    if (irq < 0 || (hdlr = handler[irq]) == 0)
        panic("Unexpected interrupt %d", irq);
    disable_irq(irq);
    interrupt(hdlr);
    if (current->p_priority > 0 && ptable[hdlr].p_state == READY) {
        schedule();
    }

    return current->p_sp;
}

/* hardfault_handler -- substitutes for the definition in startup.c */
void hardfault_handler(void) {
    panic("HardFault");
}


/* INITIALISATION */

#define IDLE_STACK 128

static void init_ptable(struct proc *p, int pid, char *name, unsigned stksize) {
    unsigned char *stack = sbrk(stksize);
    unsigned *sp = (unsigned *) &stack[stksize];

    /* Blank out the stack space to help detect overflow */
    for (unsigned *p = (unsigned *) stack; p < sp; p++) *p = BLANK;

    p->p_pid = pid;
    strncpy(p->p_name, name, 15);
    p->p_name[15] = '\0';
    p->p_sp = sp;
    p->p_stack = stack;
    p->p_stksize = stksize;
    p->p_state = READY;
    p->p_priority = P_LOW;
    p->p_waiting = 0;
    p->p_pending = 0;
    p->p_accept = ANY;
    p->p_message = NULL;
    p->p_next = NULL;
}

/* phos_init -- set up initial values */
void phos_init(void) {
    // Create idle task as process 0
    idle_proc = &ptable[IDLE];
    init_ptable(idle_proc, IDLE, "IDLE", IDLE_STACK);
    idle_proc->p_state = IDLING;
    idle_proc->p_priority = 3;
}

#define INIT_PSR 0x01000000     /* Thumb bit is set */

// These match the frame layout in mpx.s, and the hardware
#define R0_SAVE 8
#define R1_SAVE 9
#define LR_SAVE 13
#define PC_SAVE 14
#define PSR_SAVE 15

#define roundup(x, n) (((x) + ((n)-1)) & ~((n)-1))

void start(int pid, char *name, void (*body)(int), int arg, int stksize) {
    struct proc *p = &ptable[pid];
    init_ptable(p, pid, name, roundup(stksize, 4));

    /* Fake an exception frame */
    unsigned *sp = p->p_sp - 16;
    memset(sp, 0, 64);
    sp[PSR_SAVE] = INIT_PSR;
    sp[PC_SAVE] = (unsigned) body & ~0x1; // Activate the process body
    sp[LR_SAVE] = (unsigned) exit; // Make it return to exit()
    sp[R0_SAVE] = (unsigned) arg;  // Pass the supplied argument in R0
    p->p_sp = sp;

    make_ready(p);
}

void setstack(unsigned *sp);

void phos_start(void) {
    current = idle_proc;
    setstack(current->p_sp);
    yield();                    // Pick a real process to run

    // Idle only runs again when there's nothing to do.
    while (1) {
        pause();                // Wait for an interrupt
    }
}


/* SYSTEM CALL INTERFACE */

// System call numbers
#define YIELD 0
#define SEND 1
#define RECEIVE 2
#define SENDREC 3
#define EXIT 4
#define CONNECT 5
#define SETPRIO 6
#define DUMP 7

unsigned *system_call(unsigned *psp) {
    short *pc = (short *) psp[PC_SAVE]; // Program counter
    int op = pc[-1] & 0xff;     // Syscall number from svc instruction
    int x = psp[R0_SAVE];       // PID or IRQ or prio from r0
    message *m = (message *) psp[R1_SAVE];  // Message pointer from r1

    current->p_sp = psp;

    switch (op) {
    case YIELD:
        schedule();
        break;

    case SEND:
        mini_send(x, m);
        break;

    case RECEIVE:
        mini_receive(x, m);
        break;

    case SENDREC:
        mini_sendrec(x, m);
        break;

    case EXIT:
        current->p_state = DEAD;
        choose_proc();
        break;

    case CONNECT:
        mini_connect(x);
        break;

    case SETPRIO:
        mini_setprio(x);
        break;

    case DUMP:
        /* Invoking phos_dump as a system call means that its own
           stack space is taken from the system stack rather than the
           stack of the current process. */
        phos_dump();
        break;

    default:
        panic("Unknown syscall %d", op);
    }

    return current->p_sp;
}


/* SYSTEM CALL STUBS */

/* Each function defined here leaves its arguments in r0 and r1 and
   executes an svc instruction with operand equal to the system call
   number.  After state has been saved, system_call() is invoked and
   retrieves the call number and arguments from the exception frame.
   Calls to these functions must not be inlined, or the arguments will
   not be found in the right places. */

#define NOINLINE __attribute((noinline))

void NOINLINE yield(void) {
    syscall(YIELD);
}

void NOINLINE send(int dst, message *msg) {
    syscall(SEND);
}

void NOINLINE receive(int src, message *msg) {
    syscall(RECEIVE);
}

void NOINLINE sendrec(int dst, message *msg) {
    syscall(SENDREC);
}

void NOINLINE exit(void) {
    syscall(EXIT);
}

void NOINLINE connect(int irq) {
    syscall(CONNECT);
}

void NOINLINE setprio(int prio) {
    syscall(SETPRIO);
}

void NOINLINE dump(void) {
    syscall(DUMP);
}


/* DEBUG PRINTING */

/* The routines here work by disabling interrupts and then polling: they
   should be used only for debugging. */

static int txinit;                     // UART not transmitting

static void delay_usec(int usec) {
    int t = usec<<1;
    while (t > 0) {
        // 500nsec per iteration
        nop(); nop(); nop();
        t--;
    }
}
        
/* kprintf_setup -- set up UART connection to host */
static void kprintf_setup(void) {
    // Delay so any UART activity can cease
    delay_usec(2000);

    UART_ENABLE = 0;

    GPIO_DIRSET = BIT(USB_TX);
    GPIO_DIRCLR = BIT(USB_RX);
    SET_FIELD(GPIO_PINCNF[USB_TX], GPIO_PINCNF_PULL, GPIO_Pullup);
    SET_FIELD(GPIO_PINCNF[USB_RX], GPIO_PINCNF_PULL, GPIO_Pullup);

    UART_BAUDRATE = UART_BAUD_9600;     // 9600 baud
    UART_CONFIG = 0;                    // format 8N1
    UART_PSELTXD = USB_TX;              // choose pins
    UART_PSELRXD = USB_RX;
    UART_ENABLE = UART_Enabled;
    UART_STARTTX = 1;
    UART_STARTRX = 1;
    UART_RXDRDY = 0;

    txinit = 1;
}

/* kputc -- send output character */
static void kputc(char ch) {
    if (! txinit) {
        while (! UART_TXDRDY) { }
    }
    UART_TXD = ch;
    UART_TXDRDY = 0;
    txinit = 0;
}

/* kprintf_internal -- internal version of kprintf */
static void kprintf_internal(char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    do_print(kputc, fmt, va);
    va_end(va);
}

/* kprintf -- printf variant for debugging (disables interrupts) */
void kprintf(char *fmt, ...) {
    va_list va;

    lock();
    kprintf_setup();

    va_start(va, fmt);
    do_print(kputc, fmt, va);
    va_end(va);

    restore();
    // Caller gets a UART interrupt if enabled.
}

void panic(char *fmt, ...) {
    va_list va;
     
    lock();
    kprintf_setup();     

    kprintf_internal("\r\nPanic: ");
    va_start(va, fmt);
    do_print(kputc, fmt, va);
    va_end(va);
    kprintf_internal("\r\n");

    spin();
}
