	TITLE "Parpadeo"

	LIST r=HEX p=18F4520

;DECLARACIONES INICIALES
	W EQU 0
	F EQU 1
	us_contador EQU 0
	ms_contador EQU 1
	LED_R EQU 1
	LED_off_time EQU 0xF1
	LED_on_time EQU 0xED

;INICIALIZACION DE REGISTROS
	Port_B EQU 0xF81
	Tris_B EQU 0xF93
	ADCON1 EQU 0xFC1

	ORG 0x00
	GOTO Main

	ORG 0x20

	Wait_ms MOVWF ms_contador
	MOVLW 0xFE
	MOVWF us_contador
	W_bucle_ms MOVLW 0xF9; un bucle es X ms
	ADDWF us_contador, F
	W_bucle_us NOP; un bucle son X us
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	DECFSZ us_contador, F
	GOTO W_bucle_us
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	DECFSZ ms_contador, F
	GOTO W_bucle_ms
	NOP
	RETLW 0
	NOP
	Main
	MOVLW 0x0F
	MOVWF ADCON1
	MOVLW 0x00
	MOVWF Tris_B
	Bucle1
	MOVLW LED_off_time
	CALL Wait_ms
	BCF Port_B, LED_R
	MOVLW	LED_on_time
	CALL Wait_ms
	GOTO Bucle1
END
	





	

	
	


