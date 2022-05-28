del /q cd\iblard.bin

del cd\iblard\EKI\EKI.TXT
copy trans\EKI.TXT cd\iblard\EKI\EKI.TXT

del cd\iblard\HIKOU\HIKOU.TXT
copy trans\HIKOU.TXT cd\iblard\HIKOU\HIKOU.TXT

del cd\iblard\LAPUTA01\LAPUTA01.TXT
copy trans\LAPUTA01.TXT cd\iblard\LAPUTA01\LAPUTA01.TXT

del cd\iblard\LAPUTA02\LAPUTA02.TXT
copy trans\LAPUTA02.TXT cd\iblard\LAPUTA02\LAPUTA02.TXT

del cd\iblard\MEKIN\MEKIN.TXT
copy trans\MEKIN.TXT cd\iblard\MEKIN\MEKIN.TXT

del cd\iblard\MORI01\MORI01.TXT
copy trans\MORI01.TXT cd\iblard\MORI01\MORI01.TXT

del cd\iblard\MORI02\MORI02.TXT
copy trans\MORI02.TXT cd\iblard\MORI02\MORI02.TXT

del cd\iblard\NINYA2\NINYA2.TXT
copy trans\NINYA2.TXT cd\iblard\NINYA2\NINYA2.TXT

del cd\iblard\NONA\NONA.TXT
copy trans\NONA.TXT cd\iblard\NONA\NONA.TXT

del cd\iblard\TEIEN\TEIEN.TXT
copy trans\TEIEN.TXT cd\iblard\TEIEN\TEIEN.TXT

del cd\iblard\TOMO\TOMO.TXT
copy trans\TOMO.TXT cd\iblard\TOMO\TOMO.TXT

del cd\iblard\YOZORA\YOZORA.TXT
copy trans\YOZORA.TXT cd\iblard\YOZORA\YOZORA.TXT



del font\FNT.COD
copy font\orig\EKI.COD font\FNT.COD
tools\iblard_cod_update.exe font\FNT.COD font\letters.txt

del font\FNT.FNT
tools\iblard_font_in.exe font\EKI.FNT.bmp font\FNT.FNT

copy exe\orig\SLPS_010.27 exe\SLPS_010.27
tools\armips.exe code\iblard-assembly.asm

del cd\iblard\EKI\EKI.COD
copy font\FNT.COD cd\iblard\EKI\EKI.COD
del cd\iblard\EKI\EKI.FNT
copy font\FNT.FNT cd\iblard\EKI\EKI.FNT

del cd\iblard\HIKOU\HIKOU.COD
copy font\FNT.COD cd\iblard\HIKOU\HIKOU.COD
del cd\iblard\HIKOU\HIKOU.FNT
copy font\FNT.FNT cd\iblard\HIKOU\HIKOU.FNT

del cd\iblard\LAPUTA01\LAPUTA01.COD
copy font\FNT.COD cd\iblard\LAPUTA01\LAPUTA01.COD
del cd\iblard\LAPUTA01\LAPUTA01.FNT
copy font\FNT.FNT cd\iblard\LAPUTA01\LAPUTA01.FNT

del cd\iblard\LAPUTA02\LAPUTA02.COD
copy font\FNT.COD cd\iblard\LAPUTA02\LAPUTA02.COD
del cd\iblard\LAPUTA02\LAPUTA02.FNT
copy font\FNT.FNT cd\iblard\LAPUTA02\LAPUTA02.FNT

del cd\iblard\MEKIN\MEKIN.COD
copy font\FNT.COD cd\iblard\MEKIN\MEKIN.COD
del cd\iblard\MEKIN\MEKIN.FNT
copy font\FNT.FNT cd\iblard\MEKIN\MEKIN.FNT

del cd\iblard\MORI01\MORI01.COD
copy font\FNT.COD cd\iblard\MORI01\MORI01.COD
del cd\iblard\MORI01\MORI01.FNT
copy font\FNT.FNT cd\iblard\MORI01\MORI01.FNT

del cd\iblard\MORI02\MORI02.COD
copy font\FNT.COD cd\iblard\MORI02\MORI02.COD
del cd\iblard\MORI02\MORI02.FNT
copy font\FNT.FNT cd\iblard\MORI02\MORI02.FNT

del cd\iblard\NINYA2\NINYA2.COD
copy font\FNT.COD cd\iblard\NINYA2\NINYA2.COD
del cd\iblard\NINYA2\NINYA2.FNT
copy font\FNT.FNT cd\iblard\NINYA2\NINYA2.FNT

del cd\iblard\NONA\NONA.COD
copy font\FNT.COD cd\iblard\NONA\NONA.COD
del cd\iblard\NONA\NONA.FNT
copy font\FNT.FNT cd\iblard\NONA\NONA.FNT

del cd\iblard\TEIEN\TEIEN.COD
copy font\FNT.COD cd\iblard\TEIEN\TEIEN.COD
del cd\iblard\TEIEN\TEIEN.FNT
copy font\FNT.FNT cd\iblard\TEIEN\TEIEN.FNT

del cd\iblard\TOMO\TOMO.COD
copy font\FNT.COD cd\iblard\TOMO\TOMO.COD
del cd\iblard\TOMO\TOMO.FNT
copy font\FNT.FNT cd\iblard\TOMO\TOMO.FNT

del cd\iblard\YOZORA\YOZORA.COD
copy font\FNT.COD cd\iblard\YOZORA\YOZORA.COD
del cd\iblard\YOZORA\YOZORA.FNT
copy font\FNT.FNT cd\iblard\YOZORA\YOZORA.FNT

del cd\iblard\SLPS_010.27
copy exe\SLPS_010.27 cd\iblard\SLPS_010.27

tools\psximager\psxbuild.exe -v cd\iblard >> cd\build.log