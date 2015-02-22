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

using namespace std;

// Vector para la poblacion inicial
int individuo[100][16], convertido[16],indDec[100], conjuntosOp = 0;

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

		printf("Individuo %d:\t [",i+1);

		for(int j=0 ; j<16 ; j++){
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

void reproducir(int i, int j){
	int hijo1[16], hijo2[16];
	
	int punto = rand()%14+2;
	printf("%d\n", punto);

}

int main(){	
	poblacionInicial();
	mostrarIndividuos();
	system("pause");
	limpiarconvertido();
	funAdaptacion();
	system("pause");
}
