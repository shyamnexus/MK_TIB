# CAN Project for ASF 3.52

This project provides a basic CAN communication implementation using ASF 3.52 for Microchip Studio.

## Features

- CAN communication with 500kbps baud rate
- 16MHz crystal configuration
- Basic CAN message transmission and reception
- Interrupt-driven CAN handling
- LED status indication
- Button input for testing

## Hardware Requirements

- ATSAM4S16C microcontroller
- 16MHz crystal oscillator
- CAN transceiver (e.g., MCP2551, TJA1050)
- CAN bus termination resistors (120Ω)
- LED for status indication
- Push button for testing

## Pin Configuration

- CAN_TX: PA24
- CAN_RX: PA25
- LED: PB27
- BUTTON: PA02

## Project Structure

```
CAN_Project/
├── main.c              # Main application code
├── conf_board.h        # Board configuration
├── conf_clock.h        # Clock configuration for 16MHz crystal
├── conf_can.h          # CAN configuration
├── Makefile           # Build configuration
├── CAN_Project.atsln  # Microchip Studio solution file
└── CAN_Project/       # Project directory
    └── CAN_Project.atsproj  # Project file
```

## Building the Project

1. Open the project in Microchip Studio
2. Select the target device (ATSAM4S16C)
3. Configure ASF 3.52 modules:
   - services/delay
   - drivers/can
   - drivers/gpio
   - drivers/pmc
   - drivers/pio
4. Build the project

## CAN Configuration

The project is configured for:
- Baud rate: 500kbps
- Standard CAN frames
- Normal mode operation
- Interrupt-driven communication

## Usage

1. Connect the CAN transceiver to the specified pins
2. Connect CAN_H and CAN_L to the CAN bus
3. Ensure proper bus termination (120Ω resistors)
4. Flash the firmware to the microcontroller
5. The device will send test messages every second
6. Monitor CAN traffic using a CAN analyzer

## Customization

To modify the CAN configuration:
1. Edit `conf_can.h` for CAN-specific settings
2. Edit `conf_clock.h` for clock configuration
3. Edit `conf_board.h` for pin assignments
4. Modify `main.c` for application logic

## Troubleshooting

- Ensure proper CAN bus termination
- Check crystal frequency (16MHz)
- Verify pin connections
- Monitor CAN bus with analyzer
- Check power supply stability

## License

This project is provided as-is for educational purposes.