del /q cd\iblard.bin

del cd\iblard\EKI\EKI.TXT
copy trans\EKI.TXT cd\iblard\EKI\EKI.TXT

copy exe\orig\SLPS_010.27 exe\SLPS_010.27
tools\armips.exe code\iblard-assembly.asm

del cd\iblard\SLPS_010.27
copy exe\SLPS_010.27 cd\iblard\SLPS_010.27

tools\psximager\psxbuild.exe -v cd\iblard >> cd\build.log