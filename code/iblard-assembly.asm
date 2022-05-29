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

; Move stuff interfering with vram to further in ram
.org 0x80016b84
	lui v0, 0x8020

.org 0x80016ba4
	lui v0, 0x8020
	
.org 0x80016bc0
	lui v0, 0x8020
;-----------------------------------------------------------

; Move GTE related variables before our vram linked list
; 0x801dad24 - > 0x801cad24

;FUN_8005e3d4:8005e424(R),
;FUN_8005e3d4:8005e440(R),
;FUN_8005e3d4:8005e45c(R),
;FUN_8005e3d4:8005e478(R),
;FUN_8005e3d4:8005e494(R),
;FUN_8005e3d4:8005e4b0(R), 

.org 0x8005e420
	lui v0, 0x801d
	
.org 0x8005e43c
	lui v0, 0x801d

.org 0x8005e458
	lui v0, 0x801d
	
.org 0x8005e474
	lui v0, 0x801d
	
.org 0x8005e490
	lui v0, 0x801d
	
.org 0x8005e4ac
	lui v0, 0x801d
	
;FUN_8005e4e0:8005e598(W), 
.org 0x8005e594
	lui at, 0x801d

;FUN_8005f358:8005f428(R),
;FUN_8005f358:8005f460(R), 
.org 0x8005f424
	lui v1, 0x801d
	
.org 0x8005f45c
	lui v1, 0x801d
	
;FUN_80061778:80061828(R),
.org 0x80061824
	lui v1, 0x801d

;FUN_800624a4:800624dc(R),
;FUN_800624a4:800624f0(R),
.org 0x800624d8
	lui v0, 0x801d

.org 0x800624ec
	lui v0, 0x801d

;80062548(R),
.org 0x80062544
	lui v1, 0x801d

;800625a4(R),
.org 0x800625a0
	lui v0, 0x801d
	
;800625b8(R),
.org 0x800625b4
	lui v0, 0x801d

;80062610(R),
.org 0x8006260c
	lui v1, 0x801d

;FUN_80062634:800627f0(R),
;FUN_80062634:80062994(R),
.org 0x800627ec
	lui a1, 0x801d

.org 0x80062990
	lui v1, 0x801d

;80062cc0(R),
.org 0x80062cbc
	lui v1, 0x801d

; FUN_80063150:800632dc(R)  
.org 0x800632d8
	lui v1, 0x801d
	
; Move others...
.org 0x80042a10
; 80042a24 00 00 e4 ac     sw         a0,0x0(a3)=>DAT_801dad04                         = ??
; 80042a28 04 00 e5 ac     sw         a1,0x4(a3)=>DAT_801dad08                         = ??
; 80042a2c 08 00 e6 ac     sw         a2,0x8(a3)=>DAT_801dad0c                         = ??
; 80042a3c 0c 00 e4 ac     sw         a0,0xc(a3)=>DAT_801dad10                         = ??
; 80042a40 10 00 e5 ac     sw         a1,0x10(a3)=>DAT_801dad14                        = ??
; 80042a44 14 00 e6 ac     sw         a2,0x14(a3)=>DAT_801dad18                        = ??
; 80042a50 18 00 e4 ac     sw         a0,0x18(a3)=>DAT_801dad1c                        = ??
; 80042a54 1c 00 e5 ac     sw         a1,0x1c(a3)=>DAT_801dad20                        = ??
	lui a3, 0x801d

.org 0x80043bb8
; 80043bbc 04 ad c6 24     addiu      a2=>DAT_801dad04,a2,-0x52fc                      = ??
; 80043bcc 00 00 c2 ac     sw         v0,0x0(a2)=>DAT_801dad04                         = ??
; 80043bd0 04 00 c3 ac     sw         v1,0x4(a2)=>DAT_801dad08                         = ??
; 80043bd4 08 00 c5 ac     sw         a1,0x8(a2)=>DAT_801dad0c                         = ??
; 80043be4 0c 00 c2 ac     sw         v0,0xc(a2)=>DAT_801dad10                         = ??
; 80043be8 10 00 c3 ac     sw         v1,0x10(a2)=>DAT_801dad14                        = ??
; 80043bec 14 00 c5 ac     sw         a1,0x14(a2)=>DAT_801dad18                        = ??
; 80043bf8 18 00 c2 ac     sw         v0,0x18(a2)=>DAT_801dad1c                        = ??
; 80043bfc 1c 00 c3 ac     sw         v1,0x1c(a2)=>DAT_801dad20                        = ??
	lui a2, 0x801d

.org 0x80043c18
; 80043c1c 04 ad c6 24     addiu      a2,a2,-0x52fc
; 80043c20 00 00 c2 8c     lw         v0,0x0(a2)=>DAT_801dad04                         = ??
; 80043c24 04 00 c3 8c     lw         v1,0x4(a2)=>DAT_801dad08                         = ??
; 80043c28 08 00 c5 8c     lw         a1,0x8(a2)=>DAT_801dad0c                         = ??
; 80043c38 0c 00 c2 8c     lw         v0,0xc(a2)=>DAT_801dad10                         = ??
; 80043c3c 10 00 c3 8c     lw         v1,0x10(a2)=>DAT_801dad14                        = ??
; 80043c40 14 00 c5 8c     lw         a1,0x14(a2)=>DAT_801dad18                        = ??
; 80043c50 18 00 c2 8c     lw         v0,0x18(a2)=>DAT_801dad1c                        = ??
; 80043c54 1c 00 c3 8c     lw         v1,0x1c(a2)=>DAT_801dad20                        = ??
	lui a2, 0x801d

;----------------------------------------------------------

; Increase draw call linked list size

.org 0x80039920
	;slti v0, a2, 0x172
	slti v0, a2, 0x1B0

;----------------------------------------------------------
	
;.org 0x80016c00
;	lui v0, 0x8020
	
;.org 0x80016c1c
;	lui v0, 0x8020

.org 0x80058e30
	nop			; No wiping the good stuff

.org 0x80038104
	j InitSubs
	
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
	
InitSubs:
	jal printf
	nop
	addu a0, r0, s3
	jal InitSubtitle
	addu a1, r0, s5
	
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