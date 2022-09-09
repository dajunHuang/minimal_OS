typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef uint pde_t;

struct spinlock {
    uint locked;
    char *name;
    struct cpu *cpu;
};

