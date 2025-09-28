# CAN Project - Microchip Studio V 7.0 Conversion

This project has been converted from ASF 3.52 to work with Microchip Studio V 7.0 and MPLAB Harmony 3.0.

## Conversion Summary

### What Changed

1. **Framework Migration**: 
   - From ASF 3.52 to MPLAB Harmony 3.0
   - Updated all API calls to use Harmony framework

2. **Project Structure**:
   - Added Harmony configuration files
   - Updated project files for Microchip Studio V 7.0
   - Modified Makefile for Harmony build system

3. **Code Updates**:
   - Replaced ASF includes with Harmony includes
   - Updated CAN driver calls to use Harmony API
   - Modified interrupt handling to use Harmony callbacks
   - Updated system initialization and task management

### Key Files

- `main.c` - Updated to use MPLAB Harmony framework
- `system_init.c` - System initialization using Harmony
- `system_tasks.c` - System task management
- `system_interrupt.c` - Interrupt handling
- `system_config.h` - Harmony configuration
- `system_definitions.h` - System definitions
- `harmony_config.h` - Harmony-specific configuration

### Build Requirements

- Microchip Studio V 7.0
- MPLAB Harmony 3.0
- ATSAM4S16C target device

### Configuration

The project is configured for:
- Target: ATSAM4S16C
- Crystal: 16MHz
- System Clock: 48MHz
- CAN Baudrate: 500kbps
- CAN Pins: PA24 (TX), PA25 (RX)

### Usage

1. Open the project in Microchip Studio V 7.0
2. Configure Harmony settings as needed
3. Build and program the target device
4. The project will send CAN messages every 1 second

### Notes

- All ASF 3.52 specific code has been replaced with Harmony equivalents
- The project maintains the same functionality as the original
- Interrupt handling now uses Harmony callback system
- System initialization follows Harmony patterns