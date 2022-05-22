.psx

;  Note, FNT.FNT is regeenerated from scratch each build
.open "font\FNT.FNT",0x8013EDAC
.org 0x80145144
	.importobj "code\iblard\obj\subtitle.obj"
.close

.open "exe\SLPS_010.27",0x8000F800

.definelabel GetLetterImage, 0x800394e0
.definelabel LoadImage, 0x8003e65c
.definelabel DrawSync, 0x8003e434
.definelabel DisplayText, 0x80038ff0
.definelabel printf, 0x8003bcb8

; 0x8002cf2c  main game loop

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

.org 0x80039c9c ; Text and subtitles
	j AddCurLetWidthText
	
.org 0x80039d14	; Items
	j AddCurLetWidthItems
	
; .org 0x80039c6c
	; j StoreXProperlyForText ; For text and subtitles
	; nop

; .org 0x80039d64
	; nop	; stores second half of orgin x here.. not sure why...
	
;----------------------------------
.org 0x8003927c
	jal WrapVRAM

.org 0x80039d94
	j SetTextSrcXY

.org 0x8002d020
	jal DisplaySubtitle
	
.org 0x80038a60
	addiu at, at, 0xbe28
	j UpgradeText
	nop
	
.org 0x80038f00
	addiu at, at, 0xbe28
	j UpgradeItems
	nop 
	
.org 0x80096900
;	.importobj "code\iblard\obj\subtitle.obj"
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
	
UpgradeItems:
	addu a0, r0, at	; src text
	addu a1, r0, s0	; src idx
	jal ConvertTextToTwoBytes
	addu a2, r0, v1	; dest
	
	j 0x80038f34
	nop

GetLetWidth:
	addiu sp, sp, -20
	sw ra, 0(sp)
	sw a0, 4(sp)
	sw s1, 8(sp)
	sw v0, 12(sp)
	sw a2, 16(sp)
	la s1, vars
	addu a0, r0, fp	
	jal GetSentenceWidth
	addu a1, r0, s2

	;addiu a2, s1, 0x04

	sw v0, 0(s1) ; Update current width with next

    lw ra, 0(sp)
	lw a0, 4(sp)
	lw s1, 8(sp)
	lw v0, 12(sp)
	lw a2, 16(sp)
	jr ra
	addiu sp, sp, 20
	
AddCurLetWidthText:
	la v1, vars
	lw v1, 0(v1)
	nop
	addu v1, v1, a0
	addu v1, v1, v0
	sh v1, 0x7900(at)
	j 0x80039d1c
	addiu v1, t6, 0x00ae ; replace clobbered v1
	
AddCurLetWidthItems:
	la v1, vars
	lw v1, 0(v1)
	nop
	addu v1, v1, a0
	addu v1, v1, v0
	sh v1, 0x7900(at)
	j 0x80039d1c
	addiu v1, t6, 0x0056 ; replace clobbered v1

ResetWidthVar:
	;addiu s5, r0, 1
	la a0, vars
	sb r0, 0x8279(at)
	sw r0, 4(a0)
	j 0x80039148
	sw r0, 0(a0)
	
StoreXProperlyForText:
	andi a0, a0, 0x0FFF
	sh a0, 0x790a(at)
	j 0x80039c74
	addiu a0, a3, 0x003a
	
WrapVRAM:
	addu t0, r0, sp ; save off current stack pointer for our x y
	addiu sp, sp, -16
	sw ra, 0(sp)
	sw a0, 4(sp)
	sw a1, 8(sp)
	sw a2, 12(sp)
	
	;la a0, vars	
	;lw a0, 4(a0)
	addiu a0, t0, 0x0420
	jal SetVRAMUploadXY
	addiu a1, t0, 0x0422
	
	lw ra, 0(sp)
	lw a0, 4(sp)
	lw a1, 8(sp)
	lw a2, 12(sp)
	
	j 0x8003e65c
	addiu sp, sp, 16
	
SetTextSrcXY:
	addiu sp, sp, -4
	sw ra, 0(sp)
	
	jal SetLetSrcXY
	addiu a0, at, 0x790a
	
	lw ra, 0(sp)
	nop
	jr ra
	addiu sp, sp, 4
	


vars:
	.dw 0	; current total width
	.dw 0	; current letter idx
	
.close