CC = riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32
K_OUTPUT = build/kernel
U_OUTPUT = build/user
K_INCLUDE = kernel/include
K_SRC = kernel/src
U_SRC = user
KSRCS = $(wildcard $(K_SRC)/*)
USRCS = $(wildcard $(U_SRC)/*)
KOBJS = $(patsubst $(K_SRC)/%,%.o,$(basename $(KSRCS)))
UOBJS = $(patsubst $(U_SRC)/%,%.o,$(basename $(USRCS)))

CFLAGS = -Wall -Werror -O -fno-omit-frame-pointer -ggdb -mcmodel=medany -ffreestanding \
	-fno-common -nostdlib -mno-relax -fno-stack-protector -fno-pie -no-pie -I.

all: kernel

kernel: $(KOBJS)
$(KOBJS): $(KSRCS)
	$(CC) -o $(K_OUTPUT)/$@ -c $< $(CFLAGS) -I$(K_INCLUDE)

.PHONY: clean
clean:
	rm -rf $(K_OUTPUT)/* $(U_OUTPUT)/*