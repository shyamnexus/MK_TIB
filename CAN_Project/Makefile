# Makefile for CAN Project with ASF 3.52
# Target: ATSAM4S16C
# Crystal: 16MHz

# Project name
PROJECT_NAME = CAN_Project

# Target device
TARGET = atsam4s16c

# ASF version
ASF_VERSION = 3.52.0

# ASF path (adjust as needed)
ASF_PATH = $(HOME)/asf-$(ASF_VERSION)

# Source files
SRC_FILES = main.c

# Configuration files
CONF_FILES = conf_board.h conf_clock.h conf_can.h

# ASF modules to include
ASF_MODULES = \
	services/delay \
	drivers/can \
	drivers/gpio \
	drivers/pmc \
	drivers/pio \
	drivers/tc \
	common/services/clock \
	common/services/delay \
	common/services/gpio \
	common/services/ioport \
	common/services/serial \
	common/services/sleepmgr \
	common/services/usb \
	common/services/usb/class/cdc \
	common/services/usb/class/cdc/device \
	common/services/usb/udc \
	common/utils \
	common/utils/stdio/stdio_serial \
	common/utils/stdio/stdio_usb \
	common/utils/stdio/stdio_usb/stdio_usb_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc \
	common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c99 -O2 -g3
CFLAGS += -D__ATSAM4S16C__
CFLAGS += -D__SAM4S16C__
CFLAGS += -D__SAM4S__
CFLAGS += -D__SAM4S16C__
CFLAGS += -D__SAM4S16C__

# Include paths
INCLUDES = -I. -I$(ASF_PATH)/common/boards -I$(ASF_PATH)/common/utils
INCLUDES += -I$(ASF_PATH)/common/services/clock
INCLUDES += -I$(ASF_PATH)/common/services/delay
INCLUDES += -I$(ASF_PATH)/common/services/gpio
INCLUDES += -I$(ASF_PATH)/common/services/ioport
INCLUDES += -I$(ASF_PATH)/common/services/serial
INCLUDES += -I$(ASF_PATH)/common/services/sleepmgr
INCLUDES += -I$(ASF_PATH)/common/services/usb
INCLUDES += -I$(ASF_PATH)/common/services/usb/class/cdc
INCLUDES += -I$(ASF_PATH)/common/services/usb/class/cdc/device
INCLUDES += -I$(ASF_PATH)/common/services/usb/udc
INCLUDES += -I$(ASF_PATH)/common/utils
INCLUDES += -I$(ASF_PATH)/common/utils/stdio
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_serial
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/common/utils/stdio/stdio_usb/stdio_usb_cdc/stdio_usb_cdc_cdc/stdio_usb_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc/stdio_usb_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc_cdc
INCLUDES += -I$(ASF_PATH)/drivers/can
INCLUDES += -I$(ASF_PATH)/drivers/gpio
INCLUDES += -I$(ASF_PATH)/drivers/pmc
INCLUDES += -I$(ASF_PATH)/drivers/pio
INCLUDES += -I$(ASF_PATH)/drivers/tc
INCLUDES += -I$(ASF_PATH)/services/delay

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