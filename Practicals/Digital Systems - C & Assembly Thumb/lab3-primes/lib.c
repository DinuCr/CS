// lib.c
// Copyright (c) 2018 J. M. Spivey

#include "lib.h"

#define NMAX 16

static char *utoa(unsigned x, unsigned base, char *nbuf) {
     char *p = &nbuf[NMAX];
     const char *hex = "0123456789abcdef";

     *--p = '\0';
     do {
          *--p = hex[x % base];
          x = x / base;
     } while (x != 0);
     
     return p;
}

static char *itoa(int v, char *nbuf) {
     if (v >= 0)
          return utoa(v, 10, nbuf);
     else {
          char *p = utoa(-v, 10, nbuf);
          *--p = '-';
          return p;
     }
}

int atoi(char *p) {
     unsigned x = 0;
     int minus = 0;

     if (*p == '-') {
         minus = 1; p++;
     }

     while (*p >= '0' && *p <= '9')
          x = 10 * x + (*p++ - '0');

     if (minus)
         return -x;
     else
         return x;
}

unsigned xtou(char *p) {
    unsigned x = 0;

    for (;;) {
        if (*p >= '0' && *p <= '9')
            x = (x << 4) + (*p++ - '0');
        else if (*p >= 'a' && *p <= 'f')
            x = (x << 4) + (*p++ - 'a' + 10);
        else if (*p >= 'A' && *p <= 'F')
            x = (x << 4) + (*p++ - 'A' + 10);
        else
            break;
    }

    return x;
}


/* We need sprintf to be thread-safe, so a trick is needed. */

/* file -- type of mini-files for printf output */
typedef struct {
     void (*f_putc)(char);  // Function to output each char
     char *f_ptr;           // Char pointer to use if function is null
} file;

/* fputch -- output a character or add it to buffer */
static void fputch(file *fp, char ch) {
     if (fp->f_putc != NULL)
          fp->f_putc(ch);
     else
          *fp->f_ptr++ = ch;
}

/* fputstr -- output or buffer each character of a string */
static void fputstr(file *fp, char *str) {
     for (char *p = str; *p != '\0'; p++)
          fputch(fp, *p);
}

/* _do_print -- the guts of printf */
static void _do_print(file *fp, const char *fmt, va_list va) {
     int x;
     char nbuf[NMAX];

     for (const char *p = fmt; *p != 0; p++) {
          if (*p == '%' && *(p+1) != '\0') {
               switch (*++p) {
               case 'c':
                    fputch(fp, va_arg(va, int));
                    break;
               case 'd':
                    fputstr(fp, itoa(va_arg(va, int), nbuf));
                    break;
               case 's':
                    fputstr(fp, va_arg(va, char *));
                    break;
               case 'u':
                    fputstr(fp, utoa(va_arg(va, unsigned), 10, nbuf));
                    break;
               case 'x':
                    x = va_arg(va, unsigned);
                    if (x == 0)
                         fputch(fp, '0');
                    else {
                        fputstr(fp, "0x");
                        fputstr(fp, utoa(x, 16, nbuf));
                    }
                    break;
               default:
                    fputch(fp, *p);
                    break;
               }
          } else {
               fputch(fp, *p);
          }
     }
}     

/* do_print -- public skeleton for printf */
void do_print(void (*putch)(char), const char *fmt, va_list va) {
     file f;
     f.f_putc = putch;
     f.f_ptr = NULL;
     _do_print(&f, fmt, va);
}

/* sprintf -- print to a character array */
int sprintf(char *buf, const char *fmt, ...) {
     file f;
     va_list va;
     f.f_putc = NULL;
     f.f_ptr = buf;
     va_start(va, fmt);
     _do_print(&f, fmt, va);
     va_end(va);
     *f.f_ptr++ = '\0';
     return (f.f_ptr - buf);
}
