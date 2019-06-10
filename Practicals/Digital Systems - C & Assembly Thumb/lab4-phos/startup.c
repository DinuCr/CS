// startup.c
// Copyright (c) 2018 J. M. Spivey

#include "hardware.h"

void null(void) { }

/* phos_init -- hook to set up scheduler data structures */
void phos_init(void);
#pragma weak phos_init = null

/* init -- main program, creates application processes */
void init(void);

/* phos_start -- hook to start process execution */
void phos_start(void);
#pragma weak phos_start = null

/* Addresses set by the linker */
extern unsigned __data_start[], __data_end[],
     __bss_start[], __bss_end[], __etext[], __stack[];

/* __reset -- the system starts here */
void __reset(void) {
     unsigned *p, *q;

     /* Make sure all RAM banks are powered on */
     POWER_RAMON |= BIT(0) | BIT(1);

     /* Copy data segment and zero out bss */
     p = __data_start; q = __etext;
     while (p < __data_end) *p++ = *q++;
     p = __bss_start;
     while (p < __bss_end) *p++ = 0;

     /* Initialise the scheduler */
     phos_init();

     /* Let the program initialise itself */
     init();

     /* Start the scheduler */
     phos_start();

     /* If there is no scheduler, spin */
     while (1) pause();
}


/* NVIC SETUP FUNCTIONS */

/* On Cortex-M0, only the top two bits of each interrupt priority are
   implemented, so setting the priority to 0xff has the same effect as
   setting it to 0xc0.  Smaller numbers correspond to more urgency. */

/* set_priority -- set priority for an IRQ to a value [0..0xff] */
void set_priority(int irq, unsigned prio) {
     if (irq < 0)
          SET_BYTE(SCB_SHPR[(irq+8) >> 2], irq & 0x3, prio);
     else
          SET_BYTE(NVIC_IPR[irq >> 2], irq & 0x3, prio);
}
     
void enable_irq(int irq) {
     NVIC_ISER[0] = BIT(irq);
}

void disable_irq(int irq) {
     NVIC_ICER[0] = BIT(irq);
}

void clear_pending(int irq) {
     NVIC_ICPR[0] = BIT(irq);
}


/*  INTERRUPT VECTORS */

/* We use GCC features to define each handler name as an alias for the
   spin() function if it is not defined elsewhere.  Applications can
   subsitute their own definitions for individual handler names 
   like uart_handler(); or if HANDLER is defined as a function name,
   all interrupts except HardFault and SVC use that handler. */

void spin(void) {
     int n;

     intr_disable();

     /* Flash the seven stars of death */
     GPIO_DIR = 0xfff0;
     while (1) {
          GPIO_OUT = 0x4000;
          for (n = 1000000; n > 0; n--) {
               nop(); nop(); nop();
          }
          GPIO_OUT = 0;
          for (n = 200000; n > 0; n--) {
               nop(); nop(); nop();
          }
     }          
}

void hardfault_handler(void);
#pragma weak hardfault_handler = spin

void svc_handler(void);
#pragma weak svc_handler = spin

void default_handler(void);
#pragma weak default_handler = spin

#ifdef HANDLER

#define handler(irq) HANDLER

void HANDLER(void);

#else

#define handler(irq) irq##_handler

void nmi_handler(void);
#pragma weak nmi_handler = spin

void pendsv_handler(void);
#pragma weak pendsv_handler = spin

void systick_handler(void);
#pragma weak systick_handler = spin

void uart_handler(void);
#pragma weak uart_handler = spin

void timer0_handler(void);
#pragma weak timer0_handler = spin

void timer1_handler(void);
#pragma weak timer1_handler = spin

void timer2_handler(void);
#pragma weak timer2_handler = spin

void power_clock_handler(void);
#pragma weak power_clock_handler = spin

void radio_handler(void);
#pragma weak radio_handler = spin

void spi0_twi0_handler(void);
#pragma weak spi0_twi0_handler = spin

void spi1_twi1_handler(void);
#pragma weak spi1_twi1_handler = spin

void gpiote_handler(void);
#pragma weak gpiote_handler = spin

void adc_handler(void);
#pragma weak adc_handler = spin

void rtc0_handler(void);
#pragma weak rtc0_handler = spin

void temp_handler(void);
#pragma weak temp_handler = spin

void rng_handler(void);
#pragma weak rng_handler = spin

void ecb_handler(void);
#pragma weak ecb_handler = spin

void ccm_aar_handler(void);
#pragma weak ccm_aar_handler = spin

void wdt_handler(void);
#pragma weak wdt_handler = spin

void rtc1_handler(void);
#pragma weak rtc1_handler = spin

void qdec_handler(void);
#pragma weak qdec_handler = spin

void lpcomp_handler(void);
#pragma weak lpcomp_handler = spin

void swi0_handler(void);
#pragma weak swi0_handler = spin

void swi1_handler(void);
#pragma weak swi1_handler = spin

void swi2_handler(void);
#pragma weak swi2_handler = spin

void swi3_handler(void);
#pragma weak swi3_handler = spin

void swi4_handler(void);
#pragma weak swi4_handler = spin

void swi5_handler(void);
#pragma weak swi5_handler = spin

#endif

// Entries filled with default are unused by the hardware.  Getting
// such an interrupt would be a real surprise!

void *__vectors[] __attribute((section(".vectors"))) = {
    __stack,                    // -16
    __reset,
    handler(nmi),
    hardfault_handler,
    handler(default),           // -12
    handler(default),
    handler(default),
    handler(default),
    handler(default),           //  -8
    handler(default),
    handler(default),
    svc_handler,
    handler(default),           // -4
    handler(default),
    handler(pendsv),
    handler(systick),
    
    /* external interrupts */
    handler(power_clock),       //  0
    handler(radio),
    handler(uart),
    handler(spi0_twi0),
    handler(spi1_twi1),         //  4
    handler(default),
    handler(gpiote),
    handler(adc),
    handler(timer0),            //  8
    handler(timer1),
    handler(timer2),
    handler(rtc0),
    handler(temp),              // 12
    handler(rng),
    handler(ecb),
    handler(ccm_aar),
    handler(wdt),               // 16
    handler(rtc1),
    handler(qdec),
    handler(lpcomp),
    handler(swi0),              // 20
    handler(swi1),
    handler(swi2),
    handler(swi3),
    handler(swi4),              // 24
    handler(swi5),
    handler(default),
    handler(default),
    handler(default),           // 28
    handler(default),
    handler(default),
    handler(default)
};
