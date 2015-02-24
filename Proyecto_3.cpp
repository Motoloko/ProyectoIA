/* 
	Proyecto No. 3
	Algoritmos Genéticos
	Equipo:
		Erick Jafett Hernandez
		Juan Jose Tovar
		Luis Gerardo Hurtado
*/
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define generaciones 5 // cantidad de generaciones a generar

using namespace std;

// Vector para la poblacion inicial
int individuo[100][16], convertido[16],indDec[100], conjuntosOp = 0, hijos[20][2][16], padresUsados[2][20];

void limpiarconvertido(){
	for(int i=0 ; i < 16 ; i++){
		convertido[i] = 0;
	}
}

void poblacionInicial(){
	srand(time(NULL));

	for(int i=0 ; i<100 ; i++){
		for(int j = 0; j < 16 ; j++){
			individuo[i][j] = rand() % 2;
			//cout << individuo[i][j];
		}
	}
}

void mostrarIndividuos(){
	printf("=============INDIVIDUOS=============\n");
	for(int i=0 ; i<100 ; i++){
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);

		printf("Individuo %d:\t [",i+1);

		for(int j=0 ; j<16 ; j++){
			if(individuo[i][j]==1)
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);
			else
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
			printf("%d,",individuo[i][j]);
		}
		printf("]\n");
	}
}

int convadec(int n[16])
{
	int decimal = 0 ;
	
	for(int i = 0 ; i < 16 ; i++)
	{
		decimal = decimal * 2 + n[i];
	}
	
	return decimal;
}

void convabin(float n)
{
	float inicio = 32768, i = 0;
	float residuo;
	n++;
	n = n / inicio;

	while(i < 16){
		if(n > 1){
			convertido[(int)i] = 1;
			n = n - 1;
		}
		else{
			convertido[(int)i] = 0;
		}
		n = n * 2;	
		i++;
	}
	
}

void funAdaptacion(){
	int funcion = 0;
	printf("\n=============INDIVIDUOS TRADUCIDOS=============\n");
	for(int i=0 ; i<100 ; i++){
		indDec[i] = convadec(individuo[i]);
		printf("Individuo decimal [%i]: %d\n",i+1,indDec[i]);
		funcion = funcion + indDec[i];		
	}

	funcion = funcion / 100;
	printf("La funcion de adaptacion es: %d\n",funcion );

	convabin(funcion);

	for (int i = 0; i < 16; i++)
	{
		printf("%d",convertido[i]);
	}
	printf(" en decimal es: %d\n",convadec(convertido));

	for(int i = 1 ; i<16 ; i++)
	{
		if(convertido[i-1] == convertido[i] && convertido[i+1] != convertido[i])
			conjuntosOp++;
	}

	printf("El conjunto optimo debera tener %d conjuntos\n",conjuntosOp);

}

void reproducir(int i, int j, int c){
	int hijo1[16], hijo2[16];
	

	printf("Padre 1: ");

	for(int o=0 ; o<16 ; o++)
	{
		printf("%d",individuo[i][o]);
	}

	printf("\nPadre 2: ");

	for(int o=0 ; o<16 ; o++)
	{
		printf("%d",individuo[j][o]);
	}

	int punto = rand()%14+2;
	printf("\n==================================\n"
			"El punto de combinacion sera %d\n", punto);

	for(int o=0 ; o<16 ; o++){

		// menor de punto de cambio
		if(o <= punto){
			hijo1[o] = individuo[i][o];
			hijo2[o] = individuo[j][o];
		}
		else{
			hijo2[o] = individuo[i][o];
			hijo1[o] = individuo[j][o];
		}
	}
	printf("Resultado: \n");
	printf("Hijo1 : ");
	for (int o = 0; o < 16; o++)
	{
		printf("%d",hijo1[o]);
	}

	printf("\nHijo2 : ");
	for (int o = 0; o < 16; o++)
	{
		printf("%d",hijo2[o]);
	}
	printf("\n==================================\n");

	for(int o=0 ; o<16 ; o++){
		hijos[c][0][o] = hijo1[o];
		hijos[c][1][o] = hijo2[o];
	}
}


void remplazarPadres(){
	for(int i=0 ; i<20 ; i++){
		printf("Padre[%d] a: %d\n",i+1,padresUsados[0][i]);
		printf("Padre[%d] b: %d\n",i+1,padresUsados[1][i]);
	}	

	for(int i=0 ; i<20; i++){
		for(int j=0 ; j<16 ; j++){
			individuo[padresUsados[0][i]][j] = hijos[i][0][j];
			individuo[padresUsados[1][i]][j] = hijos[i][1][j];
		}
	}
	printf("Padres remplazados...\n");
}

void cruzaAzar(){
	int a[20],b[20];
	for(int i=0 ; i<20 ; i++){
		a[i] = rand()%100;
		b[i] = rand()%100;
		printf("\n======= Reproduccion No %d ======= \n",i+1 );
		reproducir(a[i],b[i],i);
		printf("\n");
	}


	for(int i=0 ; i<20 ; i++){
		padresUsados[0][i] = a[i];
		padresUsados[1][i] = b[i];
	}

	remplazarPadres();

}

int main(){	
	poblacionInicial();
	mostrarIndividuos();
	system("pause");

	limpiarconvertido();
	funAdaptacion();
	system("pause");
	

	for(int i=0 ; i<generaciones; i++){
		printf("\nGeneracion %d\n", i+1);
		cruzaAzar();
	}
	system("pause");

	mostrarIndividuos();
	system("pause");
}
