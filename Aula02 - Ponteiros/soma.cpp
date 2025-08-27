#include <stdio.h>

int soma(int *a, int *b){
	return *a + *b;
}

int main(){
	int x = 5;
	int y = 10;
	printf("Soma: %d", soma(&x, &y) );

	return 0;
}