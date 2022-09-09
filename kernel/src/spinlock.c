#include "type.h"
#include "defs.h"

void initlock(struct spinlock *lock, char *name) {
    lock->name = name;
    lock->locked = 0;
    lock->cpu = 0;
}

void acquire(struct spinlock *lock) {

}

int holding(struct spinlock *lock) {

}

void release(struct spinlock* lock) {

}

void push_off(void) {

}

void pop_off(void) {

}