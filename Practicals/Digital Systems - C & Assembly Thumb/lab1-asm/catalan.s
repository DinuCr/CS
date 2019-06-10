@ lab1-asm/catalan.s
@ Copyright (c) 2018-19 J. M. Spivey

        .syntax unified
        .text

        .global foo
        .thumb_func
foo:
@ Compute Catalan(n) from the defining recurrence
@ ... using a static array and loops

        push {r4-r7, lr}        @ Save registers
        
@@ r0 = n, r3 = t, r4 = row, r5 = k, r6 = j

        movs r5, 0              @ k = 0
        ldr r4, =row
        movs r1, 1
        str r1, [r4]            @ row[0] = 1

outer:
        cmp r5, r0              @ while (k < n)
        bge done

        movs r6, #0             @ j = 0
        movs r3, #0             @ t = 0

inner:
        cmp r6, r5              @ while (j <= k)
        bgt indone

        lsls r1, r6, #2         @ put row[j] in r2
        ldr r2, [r4, r1]
        subs r1, r5, r6         @ put row[k-j] in r1
        lsls r1, r1, #2         
        ldr r1, [r4, r1]
        muls r2, r2, r1         @ multiply
        adds r3, r3, r2         @ add to t
        adds r6, r6, #1         @ j++
        b inner

indone:
        adds r5, r5, #1         @ k++
        lsls r1, r5, #2         @ row[k] = t
        str r3, [r4, r1]
        b outer
        
done:   
        lsls r1, r0, 2          @ return row[n]
        ldr r0, [r4, r1]

        pop {r4-r7, pc}         @ Restore and return

@ Statically allocate 256 words of storage for the array
        .bss
        .align 2
row:
        .space 1024

