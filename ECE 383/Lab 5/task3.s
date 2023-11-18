/*
Caleb Thompson
CWID: 12145922
Orion Gregory
CWID: 12160343
*/

.include "p24Hxxxx.inc"
.global __reset


	.bss
	
check_val:	.space 2	;initialize check_val
ones_count:	.space 1	;initialize ones_count
constant:	.space 1	;constant so first_one isnt stored at an odd address
first_one:	.space 1	;initialize first_one

	.text
__reset:                 
        mov #__SP_init, w15
        mov #__SPLIM_init,W0   
        mov W0, SPLIM   


	mov.b ones_count, WREG
	mov.b W0, W1					;store ones_count in W1
	mov.b first_one, WREG
	mov.b W0, W2					;store first_one in W2
	mov #0xF508, W0
	mov W0, check_val				;check_val = 0xF508

	countOneBits:
	clr W1							;ones_count = 0
	countOneBits_loop:
	cp0 W0							;while check_val > 0
	bra LEU, countOneBits_loop_end	;branch if less than or equal
	countOneBits_if:
	and W0, #1, W3					;if check_val & 1
	bra Z, countOneBits_end_if		;branch if check_val & 1 = 0
	inc.b W1, W1					;increment ones_count
	countOneBits_end_if:
	lsr W0, W0						;shift right check_val by 1
	bra countOneBits_loop			;branch to top of loop
	countOneBits_loop_end:
	countOneBits_end:

	mov.b W1, W0					
	mov.b WREG, ones_count			;store W1 in ones_count
	mov check_val, W0

	findFirstOne:
	clr W2							;first_one = 0
	findFirstOne_loop:
	and W0, #1, W3					;while check_val & 1
	cp0 W3							;compare result to 0
	bra NZ, findFirstOne_loop_end	;branch if not zero
	inc.b W2, W2					;increment first_one
	lsr W0, W0						;shift check_val right by 1
	bra findFirstOne_loop			;branch to top of loop
	findFirstOne_loop_end:
	findFirstOne_end:

	mov.b W2, W0
	mov.b WREG, first_one			;store W2 in first_one

done: goto	done
.end
