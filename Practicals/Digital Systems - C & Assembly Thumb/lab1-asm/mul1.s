@ lab1-asm/mul1.s
@ Copyright (c) 2018-19 J. M. Spivey

        .syntax unified
        .global foo

        .text
        .thumb_func
foo:
@ ----------------
@ Multiplication by repeated addition
@ Variables x = r0, y = r1, z = r2
@ Invariant a * b = x * y + z

        movs r2, #0             @ z = 0;
loop:
        cmp r0, #0              @ while (x != 0) {
        beq done
        subs r0, r0, #1         @   x = x-1;
        adds r2, r2, r1         @   z = z+y;
        b loop                  @ }
done:
        movs r0, r2             @ return z;
@ ----------------
        bx lr
