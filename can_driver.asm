; CAN Driver for ASM3.52
; 16MHz crystal, 80MHz system clock
; Supports CAN 2.0A/B standard

    .text
    .global can_init
    .global can_send_message
    .global can_receive_message
    .global can_is_initialized
    .global can_is_tx_pending
    .global can_is_rx_available

; CAN Initialization
; Input: None
; Output: W0 = 1 if success, 0 if failure
can_init:
    ; Save registers
    push    W1
    push    W2
    push    W3
    
    ; Check if already initialized
    mov     #can_initialized, W0
    mov     [W0], W1
    cp0     W1
    bra     nz, can_init_success
    
    ; Enable CAN module clock
    bset    C1CON, #C1ON      ; Enable CAN module
    
    ; Configure CAN control register
    mov     #0x0000, W0        ; Clear C1CON
    mov     W0, C1CON
    
    ; Configure bit timing for 500kbps
    mov     #CAN_BRP, W0
    mov     W0, C1CFG1        ; Set BRP
    
    mov     #((CAN_TSEG1 << 8) | (CAN_TSEG2 << 4) | CAN_SJW), W0
    mov     W0, C1CFG2        ; Set timing segments
    
    ; Configure CAN control register
    mov     #0x8000, W0        ; Set C1ON bit
    mov     W0, C1CON
    
    ; Wait for CAN module to be ready
    mov     #1000, W2          ; Timeout counter
can_init_wait:
    mov     C1CON, W0
    btst    W0, #C1ON
    bra     nz, can_init_ready
    dec     W2, W2
    bra     nz, can_init_wait
    bra     can_init_fail      ; Timeout
    
can_init_ready:
    ; Configure message buffers
    ; TX Buffer 0
    mov     #0x0000, W0
    mov     W0, C1TX0CON      ; Clear TX buffer 0 control
    
    ; RX Buffer 1
    mov     #0x0000, W0
    mov     W0, C1RX0CON      ; Clear RX buffer 0 control
    
    ; Set acceptance filter for RX
    mov     #CAN_RX_ID, W0
    mov     W0, C1RX0SID      ; Set receive ID
    
    ; Configure interrupt (optional)
    bset    IEC1, #C1IE        ; Enable CAN interrupt
    
    ; Mark as initialized
    mov     #can_initialized, W0
    mov     #1, W1
    mov     W1, [W0]
    
    ; Clear status flags
    mov     #can_tx_pending, W0
    clr     [W0]
    mov     #can_rx_available, W0
    clr     [W0]
    
can_init_success:
    mov     #1, W0
    bra     can_init_exit
    
can_init_fail:
    mov     #0, W0
    
can_init_exit:
    pop     W3
    pop     W2
    pop     W1
    return

; Send CAN Message
; Input: W0 = Message ID, W1 = Data length (0-8), W2 = Pointer to data
; Output: W0 = 1 if success, 0 if failure
can_send_message:
    ; Save registers
    push    W1
    push    W2
    push    W3
    push    W4
    
    ; Check if CAN is initialized
    mov     #can_initialized, W3
    mov     [W3], W3
    cp0     W3
    bra     z, can_send_fail
    
    ; Check if TX buffer is available
    mov     C1TX0CON, W3
    btst    W3, #TXREQ
    bra     nz, can_send_fail  ; Buffer busy
    
    ; Set message ID
    mov     W0, C1TX0SID
    
    ; Set data length
    mov     W1, W3
    mov     W3, C1TX0DLC
    
    ; Copy data to TX buffer
    mov     #C1TX0D0, W3       ; Start of data buffer
    mov     W2, W4             ; Source data pointer
    cp0     W1
    bra     z, can_send_start  ; No data to copy
    
can_send_copy:
    mov     [W4++], [W3++]     ; Copy byte
    dec     W1, W1
    bra     nz, can_send_copy
    
can_send_start:
    ; Start transmission
    bset    C1TX0CON, #TXREQ
    
    ; Mark as pending
    mov     #can_tx_pending, W3
    mov     #1, W4
    mov     W4, [W3]
    
    mov     #1, W0
    bra     can_send_exit
    
can_send_fail:
    mov     #0, W0
    
can_send_exit:
    pop     W4
    pop     W3
    pop     W2
    pop     W1
    return

; Receive CAN Message
; Input: W0 = Pointer to receive buffer
; Output: W0 = 1 if message received, 0 if no message
can_receive_message:
    ; Save registers
    push    W1
    push    W2
    push    W3
    
    ; Check if CAN is initialized
    mov     #can_initialized, W1
    mov     [W1], W1
    cp0     W1
    bra     z, can_rx_fail
    
    ; Check if RX buffer has message
    mov     C1RX0CON, W1
    btst    W1, #RXFUL
    bra     z, can_rx_fail     ; No message
    
    ; Get message ID
    mov     C1RX0SID, W1
    mov     W1, [W0++]         ; Store ID
    
    ; Get data length
    mov     C1RX0DLC, W1
    mov     W1, [W0++]         ; Store length
    
    ; Copy data
    mov     #C1RX0D0, W2       ; Source buffer
    mov     C1RX0DLC, W3       ; Data length
    cp0     W3
    bra     z, can_rx_clear    ; No data
    
can_rx_copy:
    mov     [W2++], [W0++]     ; Copy byte
    dec     W3, W3
    bra     nz, can_rx_copy
    
can_rx_clear:
    ; Clear RX buffer
    bclr    C1RX0CON, #RXFUL
    
    ; Clear status
    mov     #can_rx_available, W1
    clr     [W1]
    
    mov     #1, W0
    bra     can_rx_exit
    
can_rx_fail:
    mov     #0, W0
    
can_rx_exit:
    pop     W3
    pop     W2
    pop     W1
    return

; Check if CAN is initialized
; Output: W0 = 1 if initialized, 0 if not
can_is_initialized:
    mov     #can_initialized, W0
    mov     [W0], W0
    return

; Check if TX is pending
; Output: W0 = 1 if pending, 0 if not
can_is_tx_pending:
    mov     #can_tx_pending, W0
    mov     [W0], W0
    return

; Check if RX is available
; Output: W0 = 1 if available, 0 if not
can_is_rx_available:
    mov     C1RX0CON, W0
    btst    W0, #RXFUL
    bra     nz, can_rx_avail
    mov     #0, W0
    return
can_rx_avail:
    mov     #1, W0
    return