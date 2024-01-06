#@CopyRight at Ahmed Elsayed Sabra
#@Description : This is the generic makefile for arm projects

CC=arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
StdFlag = -std=c99 
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsObj = $(As:.s=.o)
Project_Name=Lab4_CortexM4
LINKER =$(wildcard *.ld)
all: $(Project_Name).bin
	@echo "======= Build Is Done ========"
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $(StdFlag) $< -o $@
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 
$(Project_Name).elf: $(OBJ) $(AsObj)
	$(CC)ld.exe -T  $(LINKER) $(LIBS) $(OBJ) $(AsObj) -o $@ -Map=map_file.map
	$(CC)objdump.exe -D main.o > log.txt
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $<  $@
	cp $(Project_Name).elf $(Project_Name).axf
clean_all:
	rm *.o *.elf *.bin *.map
	@echo "======= Every thing Is Deleted ========"
clean:
	rm *elf *.bin
	@echo "======= .elf & .bin Is Deleted Only ========"