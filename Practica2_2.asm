org 00h

CLEAR equ P0.0
PRESET equ P0.1
CK equ P0.2
D equ P0.4
Q equ P0.6
notQ equ P0.7

X equ P1.5
Y equ P1.6

inicio:
	NOP

	;X <- (not D and CK)
	MOV C, D
	CPL C
	ANL C, CK
	MOV X, C

	;Y <- (D and CK)
	MOV C, D
	ANL C, CK
	MOV Y, C

	;Q <- not (CLEAR or X or notQ)
	MOV C, X
	ORL C, CLEAR
	ORL C, notQ
	CPL C
	MOV Q, C

	;notQ <- not (PRESET or Y or Q)
	MOV C, Y
	ORL C, PRESET
	ORL C, Q
	CPL C
	MOV notQ, C

JMP inicio
	
	
	
