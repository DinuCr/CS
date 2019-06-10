#include "lib.h"
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
    UART_PSELTXD = USB_TX;               // choose pins
    UART_PSELRXD = USB_RX;
    UART_ENABLE = UART_Enabled;
    UART_STARTTX = 1;
    UART_STARTRX = 1;
    UART_RXDRDY = 0;
    txinit = 1;
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

void serial_printf(char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    do_print(serial_putc, fmt, va);
    va_end(va);
}

#define MARK '\177'

static const char script[];

/* getline -- copy a line of input into buf and return its length */
void getline(char *buf) {
    // Note failure to check the length of buf
    static const char *p = script;
    char *q = buf;

    while (*p != MARK) *q++ = *p++;
    p++; *q = '\0';
}


/* getnum -- read a line of input and convert to a number */
int getnum(void) {
    char buf[32];
    getline(buf);
    return atoi(buf);
}

void init(void) {
    int milk[10], total;

    serial_init();

    for (int i = 0; i < 10; i++) {
        int x = getnum();
        milk[i] = x;
        serial_printf("Input %d = %d\r\n", i, x);
    }

    total = 0;

    for (int i = 0; i < 10; i++)
        total += milk[i];
    
    serial_printf("Total = %d\r\n", total);    
}   

static const char script [] = {
    '1', MARK,
    '1', '2', '3', MARK,
    '-', '1', '0', MARK,
    '0', MARK,

/* Paste attack string here: */
#include "attack"
    MARK
};
