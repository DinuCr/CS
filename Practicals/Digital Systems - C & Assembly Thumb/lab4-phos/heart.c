// lab4-phos/heart.c
// Copyright (c) 2018 J. M. Spivey

#include "hardware.h"
#include "phos.h"

#define HEART (USER+0)
#define PRIME (USER+1)

static void setup_timer(void) {
    message m;
    m.m_type = REGISTER;
    m.m_i1 = 5;                 // 5 msec per tick
    m.m_i2 = 1;                 // repeating
    send(TIMER, &m);
}

static void tick(void) {
    message m;
    receive(TIMER, &m);
    assert(m.m_type == PING);
}

static const unsigned heart[] = {
    0x28f0, 0x5e00, 0x8060
};

static const unsigned small[] = {
    0x2df0, 0x5fb0, 0x8af0
};

/* show -- display three rows of a picture n times */
static void show(const unsigned *img, int n) {
    while (n-- > 0) {
        // Takes 15msec per iteration
        for (int p = 0; p < 3; p++) {
            GPIO_OUT = img[p];
            tick();
        }
    }
}

static void heart_task(int n) {
    GPIO_DIRSET = 0xfff0;
    GPIO_PINCNF[BUTTON_A] = 0;
    GPIO_PINCNF[BUTTON_B] = 0;

    //setprio(P_HIGH);
    setup_timer();

    while (1) {
        show(heart, 70);
        show(small, 10);
        show(heart, 10);
        show(small, 10);
    }
}

/* This is a bit lighter than the lab3 example, because we use GCC's
builtin modulo operation, rather than repeated subtraction.  That
leaves some CPU time over to look after the blinking lights. */

int prime(int n) {
    for (int k = 2; k * k <= n; k++) {
        if (n % k == 0)
            return 0;
    }

    return 1;
}

void prime_task(int arg) {
    int n = 10000000, count = 0;

    while (1) {
        if (prime(n)) {
            count++;
            serial_printf("prime(%d) = %d\n", count, n);
        }
        n++;
    }
}

void init(void) {
    serial_init();
    timer_init();
    start(HEART, "Heart", heart_task, 0, STACK);
    start(PRIME, "Prime", prime_task, 0, STACK);
}
