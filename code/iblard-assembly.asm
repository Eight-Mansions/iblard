.psx
.open "exe\SLPS_010.27",0x8000F800

.definelabel GetLetterImage, 0x800394e0
.definelabel LoadImage, 0x8003e65c
.definelabel DrawSync, 0x8003e434
.definelabel DisplayText, 0x80038ff0
.definelabel printf, 0x8003bcb8

.org 0x80058e30
	nop			; No wiping the good stuff

.org 0x80038104
	j trytosub
	
 .org 0x800383cc
	jal ClearSubs
	
; 0x8002cf2c  main game loop

.org 0x8002d020
	jal DisplaySubtitle
	
.org 0x80038a60
	addiu at, at, 0xbe28
	j UpgradeText
	nop

.org 0x80096900
	.importobj "code\iblard\obj\subtitle.obj"
	.importobj "code\iblard\obj\text.obj"
	
trytosub:
	jal printf
	nop
	jal DisplayLetter
	nop
	j 0x8003810c
	nop

DisplaySubs:
	addiu sp, sp, -4
	sw ra, 0(sp)
	jal DisplaySubtitle
	nop
	lw ra, 0(sp)
	j 0x80038240
	addiu sp, sp, 4
	
ClearSubs:
	jal printf
	nop
	jal ClearText
	nop
	j 0x800383d4
	nop
	
UpgradeText:
	addu a0, r0, at	; src text
	addu a1, r0, s0	; src idx
	jal ConvertTextToTwoBytes
	addu a2, r0, v1	; dest
	
	j 0x80038a94
	nop
	
.close