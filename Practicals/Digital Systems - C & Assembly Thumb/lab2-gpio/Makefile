# lab2-gpio/Makefile
# Copyright (c) 2018 J. M. Spivey

all: heart.hex

CPU = -mcpu=cortex-m0 -mthumb
CFLAGS = -O -g -Wall
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as

%.elf: %.o startup.o
	$(CC) $(CPU) $(CFLAGS) -T NRF51822.ld -nostdlib \
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
