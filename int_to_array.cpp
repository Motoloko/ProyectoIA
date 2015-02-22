#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{

	int array[6];
	int number = 123456;
	
	for (int i = 5; i >= 0; i--) 
	{
    array[i] = number % 10;
    number /= 10;
}

    for (int i = 0; i < 6; ++i)
    {
    	cout<<array[i]<<endl;
    }

    getch();
	
	
}