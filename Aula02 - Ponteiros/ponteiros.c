#include <stdio.h>

int main(){
	int x = 5;
	int *y = &x;
	
	printf(" Valor de x: %d", x);
	printf("\n Endereco de x: %p", &x);
	printf("\n Endereco de y: %p", &y);
	printf("\n Valor de y: %p", y);
	printf("\n Valor de y: %d", y);
	printf("\n Valor apontado de y: %d", *y);
	(*y)++;
	printf("\n Valor de x: %d", x);
	return 0;
}