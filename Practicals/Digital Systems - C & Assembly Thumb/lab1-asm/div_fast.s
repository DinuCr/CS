@ lab1-asm/add.s
@ Copyright (c) 2018-19 J. M. Spivey

        .syntax unified
        .global foo

        .text
        .thumb_func
foo:
@ ----------------
@ Two parameters are in registers r0 and r1
        movs r2, #0    @z = 0
        cmp r0, #0
        beq done
loop:
        lsrs r0, r0, #1
        bcc even
odd:
        adds r2, r2, r1
even:
        lsls r1, r1, #1
        cmp r0, #0
        bne loop

@ Result is now in register r0
@ ----------------
done:
        movs r0, r2
        bx lr                   @ Return to the caller
