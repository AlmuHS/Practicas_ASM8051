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

ORG 0000h

JMP INICIO

ORG 003Fh

TABLA: DB 3h,3h,9h,0Ch

ORG 0100h

INICIO:
	MOV DPTR, #TABLA
	MOV A, #0h
	MOV B, #0h
	MOV R0, #4

	BUCLE:
		MOV A, #0
		MOVC A, @A+DPTR
		ADD A, B
		INC DPTR
		MOV B, A
	DJNZ R0, BUCLE

	MOV B, #4
	DIV AB

	MOV 43h, A
	MOV 44h, B

	

END
