#include <stdarg.h>
#include "defs.h"
#include "type.h"

char digits[] = "0123456789abcdef";

void printint(int num, int base, int sign) {
    char buf[16];
    
}

void printptr(uint ptr) {
    uartputc_sync('0');
    uartputc_sync('x');
    for(int i = 0; i < sizeof(uint) * 2; ++i) {
        uartputc_sync(digits[ptr & 0xf0000000]);
        ptr <<= 4;
    }  
}

void printf(char *fmt, ...) {
    va_list ap;

    if(fmt == 0) {
        printf("null fmt");
        return;
    }

    va_start(ap, fmt);
    for(int i = 0; fmt[i] != 0; ++ i) {
        char c = fmt[i];
        if(c != '%') {
            putc(c);
            continue;
        }
        c = fmt[++i];
        switch (c) {
        case 'd':
            printint(va_arg(ap, int), 10, 1);
            break;
        case 'x':
            printint(va_arg(ap, int), 16, 1);
            break;
        case 'p':
            printptr(va_arg(ap, uint));
            break;
        case 's':
            char *s = va_arg(ap, char*);
            if(s == 0)
                s = "(null)";
            for(; *s; s++)
                uartputc_sync(*s);
            break;
        case '%':
            uartputc_sync('%');
            break;
        default:
            break;
        }
    }

}