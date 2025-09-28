; Configuration file for ASM3.52 with 16MHz crystal
; CAN peripheral configuration

    .include "p32mx795f512h.inc"  ; Include device-specific definitions

; Configuration bits for ASM3.52
    .config __CONFIG1, FNOSC_FRCPLL & POSCMOD_HS & FSOSCEN_OFF & IESO_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FECCCON_OFF & FPLLIDIV_DIV_2 & FPLLMUL_MUL_20 & FPLLODIV_DIV_2 & FPBDIV_DIV_1 & FWDTEN_OFF & FPLLICLK_PLLI & FCANIO_ON & FUSBIDIO_ON & FVBUSONIO_ON

; Clock configuration for 16MHz crystal
; PLL: 16MHz / 2 * 20 / 2 = 80MHz system clock
; Peripheral bus: 80MHz / 1 = 80MHz

; CAN Configuration
; For 16MHz crystal with 80MHz system clock
; CAN bit rate = 80MHz / (BRP * (1 + TSEG1 + TSEG2))
; For 500kbps: BRP = 10, TSEG1 = 13, TSEG2 = 2
; For 250kbps: BRP = 20, TSEG1 = 13, TSEG2 = 2
; For 125kbps: BRP = 40, TSEG1 = 13, TSEG2 = 2

; CAN Bit Rate Configuration (500kbps)
CAN_BRP         .equ    10      ; Baud Rate Prescaler
CAN_TSEG1       .equ    13      ; Time Segment 1
CAN_TSEG2       .equ    2       ; Time Segment 2
CAN_SJW         .equ    1       ; Synchronization Jump Width

; CAN Message Buffer Configuration
CAN_TX_BUFFER   .equ    0       ; Transmit buffer
CAN_RX_BUFFER   .equ    1       ; Receive buffer

; CAN Message IDs
CAN_TX_ID       .equ    0x123   ; Transmit message ID
CAN_RX_ID       .equ    0x456   ; Receive message ID

; Memory allocation for CAN buffers
    .section .data
can_tx_buffer:  .space  16      ; 16 bytes for TX buffer
can_rx_buffer:  .space  16      ; 16 bytes for RX buffer

; Global variables
can_initialized:    .word   0
can_tx_pending:     .word   0
can_rx_available:   .word   0