// lab4-phos/race.c
// Copyright (c) 2018 J. M. Spivey

#include "phos.h"
#include "hardware.h"

static volatile int r = 0;

void proc1(int n) {
    for (int i = 0; i < 10; i++)
        serial_printf("r = %d\n", r);
}

void proc2(int n) {
    while (r < 100000)
        r++;

    for (int i = 0; i < 2000000; i++) {
        nop(); nop(); nop();
    }

    dump();
}

void init(void) {
    serial_init();
    start(USER+0, "Proc1", proc1, 0, STACK);
    start(USER+1, "Proc2", proc2, 0, STACK);
}
