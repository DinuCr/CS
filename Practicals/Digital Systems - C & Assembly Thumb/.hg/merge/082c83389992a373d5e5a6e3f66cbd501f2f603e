// lab2-gpio/heart.c
// Copyright (c) 2018 J. M. Spivey

#include "hardware.h"

/* delay -- pause for n microseconds */
void delay(unsigned n) {
    unsigned t = n << 1;
    while (t > 0) {
        // 500nsec per iteration at 16MHz
        nop(); nop(); nop();
        t--;
    }
}

static const unsigned v[6][3] = {
    {0x3ff0, 0x5ff0, 0x9fb0},
    {0x3bf0, 0x5bf0, 0x9fb0},
    {0x39f0, 0x5bb0, 0x9fa0},
    {0x38f0, 0x59b0, 0x8ba0},
    {0x3830, 0x59a0, 0x8380}
};


static const unsigned heart[] = {
    0x28f0, 0x5e00, 0x8060
};

static const unsigned banana[] = {
    0x3dd0, 0x49b0, 0x9de0
};

static const unsigned small[] = {
    0x2df0, 0x5fb0, 0x8af0
};


#define JIFFY 5000 /* Delay in microsecs */

/* show -- display three rows of a picture n times */
void show(const unsigned *img, int n) {
    while (n-- > 0) {
        // Takes 15msec per iteration
        for (int p = 0; p < 3; p++) {
            GPIO_OUT = img[p];
            delay(JIFFY);
        }
    }
}

void init(void)
{
    GPIO_DIR = 0xfff0;
    GPIO_PINCNF[BUTTON_A] = 0;
    GPIO_PINCNF[BUTTON_B] = 0;
    int i=0;
    int lastA = GPIO_IN & BIT(BUTTON_A);
    int lastB = GPIO_IN & BIT(BUTTON_B);

    while (1)
    {
        if((GPIO_IN & BIT(BUTTON_A)) < lastA)
            i--;
        if((GPIO_IN & BIT(BUTTON_B)) < lastB)
            i++;
        lastA = GPIO_IN & BIT(BUTTON_A);
        lastB = GPIO_IN & BIT(BUTTON_B);
        if(i<0)
        i=4;
        if(i==5)
        i=0;
        show(v[i],1);
            //show(banana, 70);
            //show(small, 10);
            //show(banana, 10);
            //show(small, 10);
    }
}
