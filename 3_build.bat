del /q cd\iblard.bin

del cd\iblard\EKI\EKI.TXT
copy trans\EKI.TXT cd\iblard\EKI\EKI.TXT

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

del cd\iblard\SLPS_010.27
copy exe\SLPS_010.27 cd\iblard\SLPS_010.27

tools\psximager\psxbuild.exe -v cd\iblard >> cd\build.log