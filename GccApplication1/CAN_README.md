# CAN Communication for SAM4E8C at 16MHz

This project demonstrates CAN (Controller Area Network) communication on the SAM4E8C microcontroller running at 16MHz using ASF3.52.

## Features

- **Clock Configuration**: System configured for 16MHz operation
- **CAN Communication**: Full-duplex CAN communication using CAN0
- **Baud Rate**: 500kbps (suitable for 16MHz clock)
- **Mailbox Configuration**: 
  - Mailbox 0: Transmission
  - Mailbox 1: Reception with interrupt
- **Message Handling**: Interrupt-driven reception with message parsing

## Hardware Requirements

- SAM4E8C microcontroller
- CAN transceiver (e.g., MCP2551, TJA1050)
- 16MHz crystal oscillator
- CAN bus termination resistors (120Ω at each end)

## Pin Configuration

The CAN peripheral uses the following pins (check your board schematic):
- CAN0_RX: PA0 (Pin 2)
- CAN0_TX: PA1 (Pin 3)

## Clock Configuration

The system is configured for 16MHz operation:
- PLL multiplier: 1 (for 12MHz crystal)
- Prescaler: 1
- Final frequency: 16MHz

## CAN Baud Rate Calculation

For 16MHz system clock and 500kbps:
- BRP (Baud Rate Prescaler): 1
- SJW (Synchronization Jump Width): 1
- TSEG1 (Time Segment 1): 13
- TSEG2 (Time Segment 2): 2
- Total bit time: 16 clock cycles = 1μs at 16MHz = 1Mbps
- With prescaler of 2: 500kbps

## Usage

### Initialization
```c
// Initialize CAN communication
can_init_application();
```

### Sending Messages
```c
uint8_t data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
can_send_message(0x123, data, 8);
```

### Receiving Messages
```c
if (can_message_received()) {
    can_message_t msg;
    can_get_received_message(&msg);
    
    // Process received message
    // msg.id contains the CAN ID
    // msg.data[] contains the data
    // msg.length contains the data length
    
    can_clear_rx_flag();
}
```

## Message Format

- **CAN ID**: 0x123 (configurable)
- **Data Length**: 8 bytes maximum
- **Frame Type**: Standard CAN frame (11-bit ID)
- **Baud Rate**: 500kbps

## Interrupt Handling

The CAN receive interrupt is automatically handled by `CAN0_Handler()`. When a message is received:
1. The interrupt is triggered
2. Message data is copied to global variables
3. A receive flag is set
4. The main loop can check and process the message

## Project Structure

- `main.c`: Main application with CAN communication example
- `can_app.h`: CAN application header file
- `system_sam4e.c`: System clock configuration for 16MHz
- ASF3.52 CAN driver files in `src/ASF/sam/drivers/can/`

## Building and Programming

1. Open the project in Microchip Studio
2. Build the project (F7)
3. Program the device using your preferred debugger/programmer
4. Connect CAN transceiver and termination resistors
5. Monitor CAN traffic using a CAN analyzer or another CAN device

## Testing

The application sends periodic CAN messages with a counter value. To test:
1. Connect a CAN analyzer to the bus
2. Set the analyzer to 500kbps
3. Observe transmitted messages with ID 0x123
4. Send messages from the analyzer to test reception

## Troubleshooting

### Common Issues

1. **No CAN communication**: Check transceiver connections and termination resistors
2. **Wrong baud rate**: Verify system clock is 16MHz and baud rate calculation
3. **No interrupts**: Ensure NVIC is enabled and interrupt vectors are correct
4. **Message not received**: Check CAN ID filtering and mailbox configuration

### Debug Tips

- Use oscilloscope to verify CAN signals
- Check system clock frequency
- Verify CAN transceiver power and connections
- Use CAN analyzer to monitor bus traffic

## References

- SAM4E8C Datasheet
- ASF3.52 Documentation
- CAN 2.0 Specification
- Microchip Application Notes for CAN