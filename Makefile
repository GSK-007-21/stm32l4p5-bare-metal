TARGET = build/week1
CC     = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -g3 -Wall -ffreestanding -DSTM32L4P5xx -ID:/embedded/cmsis_device_l4/Include -ID:/embedded/CMSIS_5/CMSIS/Core/Include
LDFLAGS = -T linker.ld -nostdlib -Wl,-Map=$(TARGET).map
SRCS   = src/startup.c src/main.c
all: $(TARGET).elf

$(TARGET).elf: $(SRCS) linker.ld
	$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) -o $@

clean:
	del /Q build\*