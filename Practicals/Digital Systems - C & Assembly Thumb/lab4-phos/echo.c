// echo.c
// Copyright (c) 2018 J. M. Spivey

#include "phos.h"
#include "lib.h"
#include <string.h>

void read_line(char *buf) {
    char *p = buf;
    
    for (;;) {
        char ch = serial_getc();
        if (ch == '\n') break;
        *p++ = ch;
    }

    *p = '\0';
}

void echo_task(int n) {
    char line[128];

    serial_printf("Hello\n");

    while (1) {
        read_line(line);
        serial_printf("--> %s (%d)\n", line, strlen(line));
    }
}

void init(void) {
    serial_init();
    start(USER+0, "Echo", echo_task, 0, STACK);
}
