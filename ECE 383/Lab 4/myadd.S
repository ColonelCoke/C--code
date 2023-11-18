; Orion Gregory	12160343
; Caleb Thompson 12145922
; Just check out MPLAB

		.include "p33EP128GP502.inc"

       .global __reset          ;The label for the first line of code. 

         .bss            ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
lsp:       .space 2        ;Allocating space (in bytes) to variable.
msp:       .space 2        ;Allocating space (in bytes) to variable.
sum:       .space 2        ;Allocating space (in bytes) to variable.


;..............................................................................
;Code Section in Program Memory
;..............................................................................

         .text           ;Start of Code section
__reset:                 ; first instruction located at __reset label
        mov #__SP_init, w15       ;Initalize the Stack Pointer
        mov #__SPLIM_init,W0   
        mov W0, SPLIM             ;Initialize the stack limit register
;__SP_init set by linker to be after allocated data      

;User Code starts here.
; C Program equivalent
;  #define avalue 2047
;  uint16_t i,j,k;
;
;     i = avalue;   /* myvalue = 2047 (0x7FF) */
;     i = i + 1;   /* i++, i = 2048 (0x800)  */
;     j = i;       /* j is 2048 (0x0800) */
;     j = j - 1;   /* j--, j is 2047   */
;     k = j + i;    /* k = 4095 (0x0FFF) */
;
		;.equ avalue, 0343 ;Orion Gregory 12160343
		.equ aa, 100 ;given
		.equ bb, 22 ;given
		
		mov #0x0343, W1
		mov W1, lsp ;lsp = 0x0343
		mov #0x1216, W2
		mov W2, msp ;msp = 0x1216
		add W1, W2, W3 ; lsp + msp = sum
		mov #aa, W4
		mov #bb, W5
		add W4, W3, W3 ;sum = sum + aa
		add W5, W3, W3 ;sum = sum + bb
		mov W3, sum

done:
    goto     done    ;Place holder for last line of executed code

.end       ;End of program code in this file
