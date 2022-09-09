#include "riscv.h"
#include "defs.h"

volatile static int start = 0;

__attribute__ ((aligned(4))) 
void main() {
    if(r_tp() == 0) {
        uartinit();
        consoleintit();
        printfinit();
        printf("hello world from %d", r_tp());
    } else {
        while (start == 0);
        printf("hello world from %d", r_tp());
    }

}