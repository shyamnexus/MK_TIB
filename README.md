# ASM3.52 CAN Project

This Microchip Studio project is configured for the ASM3.52 development board with CAN functionality only.

## Hardware Configuration
- **Crystal**: 16MHz
- **System Clock**: 80MHz (PLL: 16MHz / 2 * 20 / 2)
- **Peripheral Clock**: 80MHz
- **CAN Bit Rate**: 500kbps (configurable)

## Project Files
- `main.asm` - Main program with CAN initialization and message handling
- `can_driver.asm` - CAN driver functions (init, send, receive)
- `config.asm` - Configuration settings and constants
- `ASM3.52_CAN_Project.atsproj` - Microchip Studio project file
- `ASM3.52_CAN_Project.atsln` - Solution file

## CAN Configuration
- **Bit Rate**: 500kbps (BRP=10, TSEG1=13, TSEG2=2)
- **Message IDs**: TX=0x123, RX=0x456 (configurable)
- **Buffer**: 8-byte data payload
- **Interrupts**: Enabled for TX/RX completion

## Features
- CAN 2.0A/B standard support
- Interrupt-driven message handling
- Configurable bit rates (125k, 250k, 500k, 1M)
- Simple send/receive API
- No other peripherals used (as requested)

## Usage
1. Open `ASM3.52_CAN_Project.atsln` in Microchip Studio
2. Build the project
3. Program the ASM3.52 board
4. Connect CAN transceiver to CANH/CANL pins
5. Monitor CAN traffic with CAN analyzer

## CAN Pin Configuration
- CANRX: Pin configured in device header
- CANTX: Pin configured in device header
- Ensure proper CAN transceiver connection

## Notes
- Project uses only CAN peripheral as requested
- 16MHz crystal configuration included
- No other peripherals initialized
- Simple test message transmission every ~5ms