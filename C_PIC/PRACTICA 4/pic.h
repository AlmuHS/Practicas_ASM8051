#include <p18f4520.h>

#define RA0 PORTAbits.RA0
#define RA1 PORTAbits.RA1
#define RA2 PORTAbits.RA2
#define RA3 PORTAbits.RA3
#define RA4 PORTAbits.RA4
#define RA5 PORTAbits.RA5

#define TRISA0 TRISAbits.TRISA0
#define TRISA1 TRISAbits.TRISA1
#define TRISA2 TRISAbits.TRISA2
#define TRISA3 TRISAbits.TRISA3
#define TRISA4 TRISAbits.TRISA4
#define TRISA5 TRISAbits.TRISA5

#define RB0 PORTBbits.RB0
#define RB1 PORTBbits.RB1
#define RB2 PORTBbits.RB2
#define RB3 PORTBbits.RB3
#define RB4 PORTBbits.RB4
#define RB5 PORTBbits.RB5
#define RB6 PORTBbits.RB6
#define RB7 PORTBbits.RB7

#define TRISB0 TRISBbits.TRISB0
#define TRISB1 TRISBbits.TRISB1
#define TRISB2 TRISBbits.TRISB2
#define TRISB3 TRISBbits.TRISB3
#define TRISB4 TRISBbits.TRISB4
#define TRISB5 TRISBbits.TRISB5
#define TRISB6 TRISBbits.TRISB6
#define TRISB7 TRISBbits.TRISB7

#define RC0 PORTCbits.RC0
#define RC1 PORTCbits.RC1
#define RC2 PORTCbits.RC2
#define RC3 PORTCbits.RC3
#define RC4 PORTCbits.RC4
#define RC5 PORTCbits.RC5
#define RC6 PORTCbits.RC6
#define RC7 PORTCbits.RC7

#define TRISC0 TRISCbits.TRISC0
#define TRISC1 TRISCbits.TRISC1
#define TRISC2 TRISCbits.TRISC2
#define TRISC3 TRISCbits.TRISC3
#define TRISC4 TRISCbits.TRISC4
#define TRISC5 TRISCbits.TRISC5
#define TRISC6 TRISCbits.TRISC6
#define TRISC7 TRISCbits.TRISC7

#define RD0 PORTDbits.RD0
#define RD1 PORTDbits.RD1
#define RD2 PORTDbits.RD2
#define RD3 PORTDbits.RD3
#define RD4 PORTDbits.RD4
#define RD5 PORTDbits.RD5
#define RD6 PORTDbits.RD6
#define RD7 PORTDbits.RD7

#define TRISD0 TRISDbits.TRISD0
#define TRISD1 TRISDbits.TRISD1
#define TRISD2 TRISDbits.TRISD2
#define TRISD3 TRISDbits.TRISD3
#define TRISD4 TRISDbits.TRISD4
#define TRISD5 TRISDbits.TRISD5
#define TRISD6 TRISDbits.TRISD6
#define TRISD7 TRISDbits.TRISD7

#define RE0 PORTEbits.RE0
#define RE1 PORTEbits.RE1
#define RE2 PORTEbits.RE2
#define RE3 PORTEbits.RE3

#define TRISE0 TRISEbits.TRISE0
#define TRISE1 TRISEbits.TRISE1
#define TRISE2 TRISEbits.TRISE2
#define TRISE3 TRISEbits.TRISE3

#define RBPU INTCON2bits.RBPU

#define TMR1IF	PIR1bits.TMR1IF
#define TMR1ON	T1CONbits.TMR1ON
#define T1CKPS0	T1CONbits.T1CKPS0
#define T1CKPS1	T1CONbits.T1CKPS1
#define TMR1CS	T1CONbits.TMR1CS
#define TMR1IE	PIE1bits.TMR1IE
#define T1RD16  T1CONbits.RD16
#define T1OSCEN	T1CONbits.T1OSCEN
#define T0IE	INTCONbits.T0IE
#define T0IF	INTCONbits.T0IF

#define PEIE	INTCONbits.PEIE
#define GIE	INTCONbits.GIE


#define TMR0ON	T0CONbits.TMR0ON
#define T0CS	T0CONbits.T0CS
#define T0SE	T0CONbits.T0SE
#define PSA	T0CONbits.PSA
#define T0PS0	T0CONbits.T0PS0
#define T0PS1	T0CONbits.T0PS1
#define T0PS2	T0CONbits.T0PS2
#define T08BIT  T0CONbits.T08BIT

#define ADIE	PIE1bits.ADIE
#define ADIF	PIR1bits.ADIF
#define ADON	ADCON0bits.ADON
#define ADGO	ADCON0bits.GO

#define RBIF	INTCONbits.RBIF
#define RBIE	INTCONbits.RBIE

#define TMR2IF	PIR1bits.TMR2IF
#define TMR2IE	PIE1bits.TMR2IE
#define TMR2ON	T2CONbits.TMR2ON

#define T3RD16	T3CONbits.RD16	
#define TMR3CS	T3CONbits.TMR3CS
#define T3CKPS0	T3CONbits.T3CKPS0
#define T3CKPS1	T3CONbits.T3CKPS1
#define TMR3ON	T3CONbits.TMR3ON
#define TMR3IF	PIR2bits.TMR3IF

#define INT0IF	INTCONbits.INT0IF
#define INT0IE	INTCONbits.INT0IE

#define	EEPROM_WRITE(addr, value) \
do{ \
	while(EECON1bits.WR)continue;EEADR=(addr);EEDATA=(value); \
	EECON1bits.EEPGD=0;EECON1bits.CFGS=0; \
	STATUSbits.C=0;if(GIE)STATUSbits.C=1;GIE=0; \
	EECON1bits.WREN=1;EECON2=0x55;EECON2=0xAA;EECON1bits.WR=1;EECON1bits.WREN=0; \
	if(STATUSbits.C) GIE=1; \
}while(0)

#define	EEPROM_READ(addr) ((EEADR=(addr)),(EECON1bits.EEPGD=0),(EECON1bits.CFGS=0),(EECON1bits.RD=1),EEDATA)


