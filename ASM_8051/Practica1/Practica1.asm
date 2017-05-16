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

ORG 0003h

INICIO:

	;Seleccionar banco 2
	SETB RS1
	
	;Cargar datos
	MOV R2,#09h
	MOV R1,#01h
	
	;Copiamos datos a A y B
	MOV A, R2
	MOV B, R1
	
	;Realizamos la division
	DIV AB
	
	;Insertamos B en el acumulador
	MOV A, B

	;Si B=0, saltamos a EXACTO
	JZ EXACTO

	;Si B != 0, saltamos a NO_EXACTO
	JNZ NO_EXACTO
	
	EXACTO:
		;Cargamos datos en memoria
		MOV 0D1h, #00010011b

		;Rotamos el valor 00010011 y almacenamos el resultado en la direccion C8h
		MOV A, #00010011b
		RL A
		RL A
		MOV 0C8h, A

		;Intercambiamos 4 bits bajos y altos de la direccion D1h
		MOV A, 0D1h
		SWAP A
		MOV 0D1h, A

		;Multiplicamos los valores de ambas posiciones de memoria
		MOV A, 0D1h
		MOV B, 0C8h
		MUL AB
		
		;Guardamos los resultados
		MOV 0D8h, A
		MOV 0D9h, B

		JMP SALIR


	NO_EXACTO:

		;Cargamos datos en memoria
		MOV 5Fh, #11d
		MOV 60h, #10d

		;Realizamos la suma de los valores
		MOV A, 5Fh
		ADDC A, 60h

		;Repetimos el proceso con los valores 127 y 1
		MOV 5Fh, #127d
		MOV 60h, #1d
		MOV A, 5Fh
		ADDC A, 60h

		;Volvemos a repetir con 255 y 1
		MOV 5Fh, #255d
		MOV 60h, #1d
		MOV A, 5Fh
		ADDC A, 60h

		;Incrementamos en dos unidades el valor de la posicion 6Bh
		MOV A, 6Bh
		ADD A, #2d
		MOV 6Bh, A

	SALIR:

END
