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

.org 0x80096900
	.importobj "code\iblard\obj\subtitle.obj"
	
trytosub:
	jal printf
	nop
	jal DisplayLetter
	nop
	j 0x8003810c
	nop
	
ClearSubs:
	jal printf
	nop
	jal ClearText
	nop
	j 0x800383d4
	nop
	
.close