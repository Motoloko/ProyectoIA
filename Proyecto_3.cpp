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
int individuo[100][16];

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

void convabin(int n)
{
    if (n / 2 != 0) {
        convabin(n / 2);
    }
    printf("%d", n % 2);
}

int main(){
	int x;

	cout<<"\n\t\tDame un numero:  ";
	cin >> x;
	convabin(x);
	
	getch();
	
	poblacionInicial();
	mostrarIndividuos();
	system("pause");
}
