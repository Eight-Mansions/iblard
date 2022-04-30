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


;------------  VWF Code -----------
.org 0x80039140
	j ResetWidthVar
	lui at, 0x800a

.org 0x80039bdc
	j GetLetWidth

.org 0x80039c9c
	j AddCurLetWidth
	
;.org 0x80039230 ; Don't set s4 to s0... we're setting it ourselves
;	nop

;.org 0x80039c60 ; Don't shift the width over... (i.e. x 10)
;	nop
;----------------------------------

	
; .org 0x8003929c
	; addiu s4, s4, 0x10 ; hard code width test
	
; .org 0x80039c48
	; addu a0, r0, v1

; .org 0x80039c58
	; subiu a0, a0, 0x1000
	; nop
	; nop
	
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
	.importobj "code\iblard\obj\font.obj"
	
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

GetLetWidth:
	addiu sp, sp, -16
	sw ra, 0(sp)
	sw a0, 4(sp)
	sw s1, 8(sp)
	sw v0, 12(sp)
	la s1, vars
	addu a0, r0, fp
	jal GetSentenceWidth
	addu a1, r0, s2

	sw v0, 0(s1) ; Update current width with next	
	lw ra, 0(sp)
	lw a0, 4(sp)
	lw s1, 8(sp)
	lw v0, 12(sp)
	jr ra
	addiu sp, sp, 16
	
AddCurLetWidth:
	la v1, vars
	lw v1, 0(v1)
	nop
	addu v1, v1, a0
	addu v1, v1, v0
	sh v1, 0x7900(at)
	j 0x80039d1c
	addiu v1, t6, 0x00ae ; replace clobbered v1

ResetWidthVar:
	la a0, vars
	sb r0, 0x8279(at)
	sw r0, 4(a0)
	j 0x80039148
	sw r0, 0(a0)


vars:
	.dw 0	; cur total width
	.dw 0	; next width
	
.close