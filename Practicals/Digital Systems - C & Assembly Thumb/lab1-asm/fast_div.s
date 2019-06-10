@ lab1-asm/add.s
@ Copyright (c) 2018-19 J. M. Spivey

        .syntax unified
        .global foo

        .text
        .thumb_func
foo:
@ ----------------
@ Two parameters are in registers r0 and r1

        push {r3-r7}
        movs r3, #0
        cmp r0, r1
        blo done
        movs r2, #1
log:
        lsls r2, #1
        lsls r1, #1
        cmp r1, r0
        blo log 
        movs r4, #0
loop: 
        adds r5, r4, r1
        cmp r5, r0
        bhi resume
        adds r4, r1
        adds r3, r2
resume:
        lsrs r1, #1
        lsrs r2, #1
        bne loop

@ Result is now in register r0
@ ----------------
done: 
        movs r0, r3
        pop {r3-r7}
        bx lr                   @ Return to the caller

