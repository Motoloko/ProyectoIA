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
int individuo[100][16], convertido[16];

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

int convabin(int n,int vuelta)
{
    if (n / 2 != 0) {
        convabin(n / 2, vuelta+1);
    }
    n=n%2;
    // printf("%d\n",n );
    convertido[vuelta] = n;
    return n;
}

int main(){
	

	printf("original: 15 || Convertido: %d\n",convabin(15,0) );

	for (int i = 0; i < 16; ++i)
	{
		printf("%d",convertido[i] );
	}
	printf("\n");
	//poblacionInicial();
	//mostrarIndividuos();
	system("pause");
}
