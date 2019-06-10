// lab0-echo/echo.c
// Copyright (c) 2018 J. M. Spivey

#include "hardware.h"

static int txinit;              // UART ready to transmit first char

/* serial_init -- set up UART connection to host */
void serial_init(void) {
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

/* serial_getc -- wait for input character and return it */
int serial_getc(void) {
    while (! UART_RXDRDY) { }
    char ch = UART_RXD;
    UART_RXDRDY = 0;
    return ch;
}

/* serial_putc -- send output character */
void serial_putc(char ch) {
    if (! txinit) {
        while (! UART_TXDRDY) { }
    }
    txinit = 0;
    UART_TXDRDY = 0;
    UART_TXD = ch;
}

/* serial_puts -- send string character by character */
void serial_puts(char *s) {
    while (*s != '\0')
        serial_putc(*s++);
}

#define BUF 80
char buf[BUF];

/* accept -- input a line of text into buf with line editing */
void accept() {
    char *p = buf;

    serial_puts("> ");

    while (1) {
        char x = serial_getc();

        switch (x) {
        case '\b':
        case 0177:
            if (p > buf) {
                p--;
                serial_puts("\b \b");
            }
            break;

        case '\r':
            *p = '\0';
            serial_puts("\r\n");
            return;

        default:
            /* Ignore other non-printing characters */
            if (x >= 040 && x < 0177 && p < &buf[BUF]) {
                *p++ = x;
                serial_putc(x);
            }
        }
    }
}

/* init -- main program */
void init(void) {
    serial_init();
    serial_puts("\r\nHello micro:world!\r\n");

    while (1) {
        accept();
        serial_puts("-> ");
        serial_puts(buf);
        serial_puts("\r\n");
    }
}
