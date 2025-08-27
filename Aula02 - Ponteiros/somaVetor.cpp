

// FUAQ leia 5 valores inteiros do teclado.
// construa uma função que recebe o endereço deste vetor e soma os valores.
// Esta função deverá receber um ponteiro para a variável soma que foi
// declarada no Main.
// A função não tem retorno.
// O Main deve apresentar a soma dos valores, mas quem de fato realiza
// o somatório é a função
#include <stdio.h>
void somar( int *vetor, int *tam, int *soma){
	*soma = 0;
	for( int i = 0; i < *tam; i++){
		*soma += vetor[i];
	}
}

int main(){
	int tamanho = 5;
	int numeros[ tamanho ];
	int sum = 0;
	
	for( int i = 0; i < 5; i++){
		printf("Digite o %do valor: ", (i+1) );
		scanf("%d" , &numeros[i] );
	}
	somar( numeros , &tamanho , &sum );
	printf( "Soma: %d", sum );
	return 0;
}