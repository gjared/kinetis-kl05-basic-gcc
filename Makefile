#
# Freescale Kinetis KL05 makefile
#
# Jared G
#

#
# Set up parameters
#
CC = arm-none-eabi-gcc
CFLAGS = -g -fmessage-length=0 -mcpu=cortex-m0 -mabi=aapcs -mthumb -msoft-float -IPDD

LD = arm-none-eabi-ld
LDFLAGS = -nostartfiles -T ProcessorExpert.ld

SIZE = arm-none-eabi-size
OBJCOPY = arm-none-eabi-objcopy

#
# Core make target
#
.PHONY: all
all: firmware.bin

#
# Linking here
#
firmware.elf: Cpu.o Events.o PE_LDD.o Vectors.o startup.o main.o
	$(LD) $(LDFLAGS) -o $@ $^
	$(SIZE) $@

#
# Converting here
#
firmware.bin: firmware.elf
	$(OBJCOPY) -O binary $< $@
	ls -al $@

#
# Clean target
#
.PHONY: clean
clean:
	rm -rf *.o *~ *.bin *.elf

