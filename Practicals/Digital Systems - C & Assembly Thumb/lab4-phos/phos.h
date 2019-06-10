// phos.h
// Copyright (c) 2018 J. M. Spivey

/* Standard pids and message types */
#define HARDWARE -1
#define ANY 999

#define IDLE 0
#define SERIAL 1
#define TIMER 2
#define I2C 3
#define USER 8                  // 8..15 are for user processes

#define INTERRUPT 1
#define OK 2
#define REGISTER 3
#define PING 4
#define REPLY 5

/* Possible priorities */
#define P_HANDLER 0           /* Interrupt handler */
#define P_HIGH 1              /* Responsive */
#define P_LOW 2               /* Normal */
#define P_IDLE 3              /* The idle process */

// For i2c READ/WRITE, we want byte addr, byte reg, char *buf, int n

typedef struct {                // 16 bytes
    unsigned short m_type;
    short m_sender;
    union {
        int m_i;
        char *m_p;
        struct {
            unsigned char m_bw, m_bx, m_by, m_bz;
        } m_b;
    } m_x1, m_x2, m_x3;
} message;

#define m_i1 m_x1.m_i
#define m_i2 m_x2.m_i
#define m_i3 m_x3.m_i
#define m_p1 m_x1.m_p
#define m_p2 m_x2.m_p
#define m_p3 m_x3.m_p
#define m_b1 m_x1.m_b.m_bw
#define m_b2 m_x1.m_b.m_bx


/* phos.c */

/* start -- create process that will run when init returns */
void start(int pid, char *name, void (*body)(int), int arg, int stksize);

#define STACK 1024              // Default stack size


/* mpx.s */

/* System calls */
void yield(void);
void send(int dst, message *msg);
void receive(int src, message *msg);
void sendrec(int dst, message *msg);
void connect(int irq);
void setprio(int p);
void exit(void);
void dump(void);

/* interrupt -- send INTERRUPT message from handler */
void interrupt(int pid);

/* lock -- disable all interrupts */
void lock(void);

/* unlock -- enable interrupts again */
void unlock(void);

/* restore -- restore previous interrupt setting (used by kprintf) */
void restore(void);

/* reschedule -- request context switch */
void reschedule(void);


/* kprintf -- print message on console without using serial task */
void kprintf(char *fmt, ...);

/* panic -- crash with message [and show seven stars] */
void panic(char *fmt, ...);

#define assert(p) \
    do { if (!(p)) panic("File %s, line %d: assertion %s failed", \
                         __FILE__, __LINE__, #p); } while (0)



/* serial.c */

/* serial_init -- start serial task */
void serial_init(void);

void serial_putc(char ch);

void serial_puts(char *s);

char serial_getc(void);

void serial_printf(char *fmt, ...);


/* timer.c */
unsigned get_time(void);

void timer_init(void);

void delay(int usec);


/* spin -- flash the seven stars of death forever */
void spin(void);
