org 00h

CLEAR equ P0.0
PRESET equ P0.1
CK equ P0.2
S equ P0.3
R equ P0.4

X equ P1.5
Y equ P1.6

Q equ P0.6
notQ equ P0.7


inicio:

	NOP
	;X <- R and CK
	MOV C, R
	ANL C, CK
	MOV X, C
		
	;Y <- S and CK
	MOV C, S
	ANL C, CK
	MOV Y, C

	;Q <- not (X or CLEAR or Q')
	MOV C, X
	ORL C, CLEAR
	ORL C, notQ
	CPL C
	MOV Q, C
	
	;Q' <- not (Y or PRESET or Q)
	MOV C, Y
	ORL C, PRESET
	ORL C, Q
	CPL C
	MOV notQ, C

jmp inicio









