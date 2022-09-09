#include "param.h"
#include "memory.h"
#include "riscv.h"
#include "type.h"

__attribute__ ((aligned (16))) 
char mstack[PGSIZE * NCPU];

extern void main();
void timerinit();

void start() {
    w_satp(0);
    w_mepc((uint)main);

    uint x = r_mstatus();
    x &= ~MSTATUS_MPP_MASK;
    x |= MSTATUS_MPP_S;
    w_mstatus(x);

    w_medeleg(0xffff);
    w_mideleg(0xffff);

    timerinit();
    
    uint id = r_mhartid();
    w_tp(id);
  
    asm("mret");
}

void timerinit() {

}