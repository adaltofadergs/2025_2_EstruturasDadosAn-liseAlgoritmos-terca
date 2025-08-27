#include <stdio.h>

void trocar(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(){
	int x = 5;
	int y = 10;
	printf("\n Valor de X: %d", x);
	printf("\n Valor de Y: %d", y);
	trocar(&x, &y);
	printf("\n ------------------");
	printf("\n Valor de X: %d", x);
	printf("\n Valor de Y: %d", y);

	return 0;
}