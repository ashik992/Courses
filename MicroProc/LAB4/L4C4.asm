CNT3 EQU 3FD6H
BPORT3 EQU 3FD2H
APORT3 EQU 3FD0H
CODE SEGMENT
ASSUME CS: CODE, DS: CODE
MOV AL, 90H
MOV DX, CNT3
OUT DX, AL
L1: MOV DX, APORT3
IN AL, DX
NOT AL
MOV DX, BPORT3
OUT DX, AL
JMP L1
HLT
CODE ENDS
END