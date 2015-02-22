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
int individuo[100][16], convertido[16],indDec[100];

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

void convabin(int n)
{
	int inicio = 32768, i = 0;

	while(i < 16){
		if(n / inicio > 1){
	    	convertido[i] = 1;
	    	n = n - inicio;
	    }
	    i++;
	    inicio = inicio / 2;
	}

    



}

void funAdaptacion(){
	int funcion = 0;
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
	printf("\n");
}

int main(){	
	poblacionInicial();
	mostrarIndividuos();
	limpiarconvertido();
	funAdaptacion();
	system("pause");
}
