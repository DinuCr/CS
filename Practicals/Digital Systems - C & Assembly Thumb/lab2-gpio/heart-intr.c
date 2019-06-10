// lab2-gpio/heart-intr.c
// Copyright (c) 2018 J. M. Spivey

#include "hardware.h"

#define TICK 5               /* One timer interrupt per 5 millisec */

static const unsigned heart[] = {
    0x28f0, 0x5e00, 0x8060
};

static unsigned row = 0;

void advance(void) {
    row++;
    if (row == 3) row = 0;

    GPIO_OUT = heart[row];
}

void timer1_handler(void) {
    if (TIMER1_COMPARE[0]) {
        advance();
        TIMER1_COMPARE[0] = 0;
    }
}

void init_timer(void) {
    TIMER1_STOP = 1;
    TIMER1_MODE = TIMER_Timer_Mode;
    TIMER1_BITMODE = TIMER_16Bit;
    TIMER1_PRESCALER = 4;      // 1MHz = 16MHz / 2^4
    TIMER1_CLEAR = 1;
    TIMER1_CC[0] = 1000 * TICK;
    TIMER1_SHORTS = BIT(TIMER_COMPARE0_CLEAR);
    TIMER1_INTENSET = BIT(TIMER_INTEN_COMPARE0);
    TIMER1_START = 1;

    set_priority(TIMER1_IRQ, 3);
    enable_irq(TIMER1_IRQ);
}

void init(void) {
    GPIO_DIR = 0xfff0;
    GPIO_PINCNF[BUTTON_A] = 0;
    GPIO_PINCNF[BUTTON_B] = 0;
    GPIO_OUT = heart[0];
    
    init_timer();

    while (1) {
        pause();
    }
}
