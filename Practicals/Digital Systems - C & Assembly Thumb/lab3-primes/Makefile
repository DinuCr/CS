# lab3-primes/Makefile
# Copyright (c) 2018 J. M. Spivey

all: primes-poll.hex primes-intr.hex

CPU = -mcpu=cortex-m0 -mthumb
CFLAGS = -O -g -Wall $(DEFINES)
CC = arm-none-eabi-gcc

primes-intr.o: DEFINES += -DINTERRUPT

primes-poll.o primes-intr.o: primes.c
	$(CC) $(CPU) $(CFLAGS) -c $< -o $@

%.elf: %.o lib.o startup.o
	$(CC) $(CPU) $(CFLAGS) -TNRF51822.ld -nostdlib \
	    $^ -lgcc -o $@ -Wl,-Map,$*.map 
	arm-none-eabi-size $@

%.o: %.c
	$(CC) $(CPU) $(CFLAGS) -c $< -o $@ 

%.hex: %.elf
	arm-none-eabi-objcopy -O ihex $< $@

clean:
	rm -f *.hex *.elf *.map *.o 

# Don't delete intermediate files
.SECONDARY:

