#include "pic.h"

//Pulsadores 
#define N1 RB0
#define N2 RA4

//Electrovalvulas
#define XV1 RB1
#define XV2 RB2

void main(void){
	//Entradas
	TRISA4 = 0; //N2 
	TRISB0 = 0; //N1

	//Salidas
	TRISB1 = 1; //XV1
	TRISB2 = 1; //XV2

	//Condicion inicial
	while(!N1 && !N2){
		XV1 = 0;
		XV2 = 0;
	};

	//Nivel llega a N1
	while(N1 && !N2){
		XV1 = 1;
	};

	//Nivel llega a N2
	while(N1 && N2){
		XV1 = 1;
		XV2 = 1;
	}

	//Situacion error
	while(!N1 && N2){
		XV1 = 0;
		XV2 = 0;
	}

	

} 
