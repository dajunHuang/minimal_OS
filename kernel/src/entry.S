.section .text
_entry:
    la sp, mstack
    li a0, 4096
    csrr a1, mhartid
    mul a0, a1, a0
    add sp, sp, a0
    call start
