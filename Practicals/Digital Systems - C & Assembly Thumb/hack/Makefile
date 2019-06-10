# hack/Makefile
# Copyright (c) 2018 J. M. Spivey

all: hack.hex attack

CPU = -mcpu=cortex-m0 -mthumb
CFLAGS = -O -g -Wall
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as

hack.o: attack

attack: attack.o
	arm-none-eabi-objcopy -O binary attack.o attack.bin
	hexdump -v -e '4/1 "0x%02x, " "\n"' attack.bin >$@

%.elf: %.o lib.o startup.o
	$(CC) $(CPU) $(CFLAGS) -T NRF51822.ld -nostdlib \
	    $^ -lgcc -o $@ -Wl,-Map,$*.map
	arm-none-eabi-size $@

%.o: %.c
	$(CC) $(CPU) $(CFLAGS) -c $< -o $@ 

%.o: %.s
	$(AS) $(CPU) $< -o $@

%.hex: %.elf
	arm-none-eabi-objcopy -O ihex $< $@

clean:
	rm -f *.hex *.elf *.map *.o attack attack.bin

# Don't delete intermediate files
.SECONDARY:
