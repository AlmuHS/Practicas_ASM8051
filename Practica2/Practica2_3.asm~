;Copyright 2017 Almudena Garcia Jurado-Centurion

;This program is free software: you can redistribute it and/or modify
;it under the terms of the GNU General Public License as published by
;the Free Software Foundation, either version 3 of the License, or
;(at your option) any later version.

;This program is distributed in the hope that it will be useful,
;but WITHOUT ANY WARRANTY; without even the implied warranty of
;MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;GNU General Public License for more details.

;You should have received a copy of the GNU General Public License
;along with this program.  If not, see <http://www.gnu.org/licenses/>.

org 00h

CLEAR equ P0.0
PRESET equ P0.1
CK equ P0.2
notQD equ P0.3
QD equ P0.4
QC equ P0.5
QB equ P0.6
QA equ P0.7

X equ P1.5
Y equ P1.6
notQA equ P1.4
notQB equ P1.3
notQC equ P1.2



inicio:
	NOP

	;Biestable A

	;X <- (not (notQD) and CK)
	MOV C, notQD
	CPL C
	ANL C, CK
	MOV X, C

	;Y <- (notQD and CK)
	MOV C, notQD
	ANL C, CK
	MOV Y, C

	;QA <- not (CLEAR or X or notQ)
	MOV C, X
	ORL C, CLEAR
	ORL C, notQA
	CPL C
	MOV QA, C

	;notQA <- not (PRESET or Y or Q)
	MOV C, Y
	ORL C, PRESET
	ORL C, QA
	CPL C
	MOV notQA, C

	;QA <- not (CLEAR or X or notQ)
	MOV C, X
	ORL C, CLEAR
	ORL C, notQA
	CPL C
	MOV QA, C

	;Biestable B

	MOV C, QA
	CPL C
	ANL C, CK
	MOV X, C

	MOV C, QA
	ANL C, CK
	MOV Y, C

	MOV C, X
	ORL C, CLEAR
	ORL C, notQB
	CPL C
	MOV QB, C

	MOV C, Y
	ORL C, PRESET
	ORL C, QB
	CPL C
	MOV notQB, C

	MOV C, X
	ORL C, CLEAR
	ORL C, notQB
	CPL C
	MOV QB, C

	
	;Biestable C
	
	MOV C, QB
	CPL C
	ANL C, CK
	MOV X, C

	MOV C, QB
	ANL C, CK
	MOV Y, C

	MOV C, X
	ORL C, CLEAR
	ORL C, notQC
	CPL C
	MOV QC, C

	MOV C, Y
	ORL C, PRESET
	ORL C, QC
	CPL C
	MOV notQC, C

	MOV C, X
	ORL C, CLEAR
	ORL C, notQC
	CPL C
	MOV QC, C

	;Biestable D

	;X <- (not D and CK)
	MOV C, QC
	CPL C
	ANL C, CK
	MOV X, C

	;Y <- (D and CK)
	MOV C, QC
	ANL C, CK
	MOV Y, C

	;Q <- not (CLEAR or X or notQ)
	MOV C, X
	ORL C, CLEAR
	ORL C, notQD
	CPL C
	MOV QD, C

	;notQ <- not (PRESET or Y or Q)
	MOV C, Y
	ORL C, PRESET
	ORL C, QD
	CPL C
	MOV notQD, C

	;Q <- not (CLEAR or X or notQ)
	MOV C, X
	ORL C, CLEAR
	ORL C, notQD
	CPL C
	MOV QD, C

	
JMP inicio
	
	
	
