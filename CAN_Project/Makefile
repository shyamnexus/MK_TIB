# Makefile for CAN Project with MPLAB Harmony 3.0
# Target: ATSAM4S16C
# Crystal: 16MHz

# Project name
PROJECT_NAME = CAN_Project

# Target device
TARGET = atsam4s16c

# Harmony version
HARMONY_VERSION = 3.0

# Harmony path (adjust as needed)
HARMONY_PATH = $(HOME)/harmony-$(HARMONY_VERSION)

# Source files
SRC_FILES = main.c system_init.c system_tasks.c system_interrupt.c

# Configuration files
CONF_FILES = conf_board.h conf_clock.h conf_can.h system_config.h system_definitions.h harmony_config.h

# Harmony modules to include
HARMONY_MODULES = \
	framework/system/clk \
	framework/system/tmr \
	framework/system/tasks \
	framework/driver/can \
	framework/driver/gpio \
	framework/driver/tmr \
	framework/system/common \
	framework/system/int \
	framework/system/ports

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c99 -O2 -g3
CFLAGS += -D__ATSAM4S16C__
CFLAGS += -D__SAM4S16C__
CFLAGS += -D__SAM4S__
CFLAGS += -D__SAM4S16C__
CFLAGS += -D__SAM4S16C__

# Include paths
INCLUDES = -I. -I$(HARMONY_PATH)/framework -I$(HARMONY_PATH)/bsp
INCLUDES += -I$(HARMONY_PATH)/framework/system/clk
INCLUDES += -I$(HARMONY_PATH)/framework/system/tmr
INCLUDES += -I$(HARMONY_PATH)/framework/system/tasks
INCLUDES += -I$(HARMONY_PATH)/framework/driver/can
INCLUDES += -I$(HARMONY_PATH)/framework/driver/gpio
INCLUDES += -I$(HARMONY_PATH)/framework/driver/tmr
INCLUDES += -I$(HARMONY_PATH)/framework/system/common
INCLUDES += -I$(HARMONY_PATH)/framework/system/int
INCLUDES += -I$(HARMONY_PATH)/framework/system/ports
INCLUDES += -I$(HARMONY_PATH)/bsp/ATSAM4S16C

# Linker flags
LDFLAGS = -Wl,--gc-sections -Wl,--relax

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Default target
all: $(PROJECT_NAME).elf

# Build the project
$(PROJECT_NAME).elf: $(OBJ_FILES)
	@echo "Linking $(PROJECT_NAME).elf..."
	@$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

# Compile source files
%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build files
clean:
	@echo "Cleaning build files..."
	@rm -f *.o *.elf *.hex *.bin *.map *.lst

# Flash the project
flash: $(PROJECT_NAME).elf
	@echo "Flashing $(PROJECT_NAME).elf..."
	@$(OBJCOPY) -O ihex $< $(PROJECT_NAME).hex
	@$(OBJCOPY) -O binary $< $(PROJECT_NAME).bin

# Generate disassembly
disasm: $(PROJECT_NAME).elf
	@echo "Generating disassembly..."
	@$(OBJDUMP) -d $< > $(PROJECT_NAME).lst

# Generate map file
map: $(PROJECT_NAME).elf
	@echo "Generating map file..."
	@$(OBJDUMP) -h $< > $(PROJECT_NAME).map

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Clean build files"
	@echo "  flash    - Flash the project"
	@echo "  disasm   - Generate disassembly"
	@echo "  map      - Generate map file"
	@echo "  help     - Show this help"

.PHONY: all clean flash disasm map help