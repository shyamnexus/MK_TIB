; Main program for ASM3.52 CAN Project
; 16MHz crystal, CAN peripheral only
; No other peripherals used

    .include "config.asm"
    .include "can_driver.asm"
    
    .text
    .global _start
    .global main
    .global can_interrupt_handler

; Program entry point
_start:
    goto    main

; Main program
main:
    ; Initialize stack pointer
    mov     #0x2000, W15      ; Set stack pointer
    
    ; Initialize CAN
    call    can_init
    cp0     W0
    bra     z, main_error     ; CAN init failed
    
    ; Main loop
main_loop:
    ; Send a test message every 1 second
    call    send_test_message
    
    ; Check for received messages
    call    check_received_message
    
    ; Simple delay (adjust for your timing needs)
    call    delay_1ms
    call    delay_1ms
    call    delay_1ms
    call    delay_1ms
    call    delay_1ms
    
    bra     main_loop

; Send test message
send_test_message:
    push    W0
    push    W1
    push    W2
    
    ; Check if TX is not pending
    call    can_is_tx_pending
    cp0     W0
    bra     nz, send_test_exit ; TX still pending
    
    ; Prepare test message
    mov     #CAN_TX_ID, W0     ; Message ID
    mov     #8, W1             ; Data length
    mov     #test_data, W2     ; Data pointer
    
    ; Send message
    call    can_send_message
    cp0     W0
    bra     z, send_test_exit  ; Send failed
    
send_test_exit:
    pop     W2
    pop     W1
    pop     W0
    return

; Check for received messages
check_received_message:
    push    W0
    push    W1
    push    W2
    
    ; Check if message available
    call    can_is_rx_available
    cp0     W0
    bra     z, check_rx_exit   ; No message
    
    ; Receive message
    mov     #rx_buffer, W0
    call    can_receive_message
    cp0     W0
    bra     z, check_rx_exit   ; Receive failed
    
    ; Process received message (add your logic here)
    ; For now, just acknowledge receipt
    
check_rx_exit:
    pop     W2
    pop     W1
    pop     W0
    return

; CAN Interrupt Handler
can_interrupt_handler:
    ; Save context
    push    W0
    push    W1
    push    W2
    push    W3
    
    ; Check interrupt source
    mov     C1INTF, W0
    btst    W0, #TX0IF
    bra     nz, can_tx_interrupt
    
    mov     C1INTF, W0
    btst    W0, #RX0IF
    bra     nz, can_rx_interrupt
    
    bra     can_int_exit

can_tx_interrupt:
    ; TX complete - clear pending flag
    mov     #can_tx_pending, W0
    clr     [W0]
    
    ; Clear interrupt flag
    bclr    C1INTF, #TX0IF
    bra     can_int_exit

can_rx_interrupt:
    ; RX complete - set available flag
    mov     #can_rx_available, W0
    mov     #1, W1
    mov     W1, [W0]
    
    ; Clear interrupt flag
    bclr    C1INTF, #RX0IF

can_int_exit:
    ; Restore context
    pop     W3
    pop     W2
    pop     W1
    pop     W0
    retfie

; Simple 1ms delay (approximate for 80MHz)
delay_1ms:
    push    W0
    mov     #20000, W0         ; Adjust for 80MHz clock
delay_loop:
    dec     W0, W0
    bra     nz, delay_loop
    pop     W0
    return

; Error handler
main_error:
    ; Error LED or other indication
    ; For now, just loop
    bra     main_error

; Data section
    .section .data
test_data:      .byte   0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
rx_buffer:      .space  16     ; Receive buffer (ID + length + 8 data bytes)

; Interrupt vector table
    .section .vector, code
    .org    0x0000
    goto    _start
    
    .org    0x0008
    goto    can_interrupt_handler
    
    .org    0x0018
    goto    can_interrupt_handler