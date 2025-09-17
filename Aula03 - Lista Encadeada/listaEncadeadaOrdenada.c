#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
	char dado[20];
	struct No *prox;	
}No;

No* gerarEnd(char valor[20]){
	No *novoNo = (No*) malloc( sizeof(No) );
	if( novoNo == NULL ){
		printf("Erro ao alicar Memória!");
		exit(1);
	}
	strcpy( novoNo->dado, valor);
	novoNo->prox = NULL;
	return novoNo;
}

int menu(){
	printf("\n  .-------------.");
	printf("\n /               \\ ");
	printf("\n|  1) Inserir     |");
	printf("\n|  2) Imprimir    |");
	printf("\n|  3) Excluir     |");
	printf("\n|  0) Sair        |");
	printf("\n \\               /");
	printf("\n  *-------------*");
	int op;
	printf("\n\nDigite a sua opcao: ");
	scanf("%d" , &op);
	return op;
}

int main(){
	No *inicio = NULL;
	char nome[20];
	int opcao;
	
	do{
		opcao = menu();
		switch( opcao ){
			case 1:
				system( "cls" );
				printf("\nDigite o nome: ");
				scanf(" %[^\n]", &nome);
				No *endGerado = gerarEnd(nome);
				if ( inicio == NULL) 
					// Se início é nulo, lista está vazia, endereçoGerado passa a ser o início
					inicio = gerarEnd( nome );
				else{
					// Se nome que acabou de chegar for menor que o dado do início, 
					//ele passa a ser o início e seu prox aponta para quem era o início
					if( strcmp( nome , inicio->dado ) < 0 ){ 
						endGerado->prox = inicio;
						inicio = endGerado;
					}else{
						//Percorre a lista para encontrar a respectiva posição na ordem
						No *ant = inicio;
						No *aux = inicio->prox;
						 
						while( aux != NULL){
							if( strcmp( nome , aux->dado ) < 0 ){
								ant->prox = endGerado;
								endGerado->prox = aux;
								break;
							}
							ant = aux;
							aux = aux->prox;
						}
						if( aux == NULL ){
							ant->prox = endGerado;
						}
					}
					
				}
				system( "cls" );
				break;
			case 2:
				system( "cls" );
				if( inicio == NULL){
					printf( "\nLista Vazia");
					printf( "\n---------------------\n");
				}
				else{
					No *aux = inicio;
					while( aux != NULL){
						printf( "\n%s", aux->dado);
						aux = aux->prox;
					}
					printf( "\n\n");
				}
				break;
			case 3:
				system( "cls" );
				printf("\nDigite o nome a ser removido: ");
				scanf(" %[^\n]", &nome);
				system( "cls" );
				if(  inicio == NULL ){
					printf("\n%s nao encontrado, pois a lista esta vazia!\n", nome);
				}else{
					bool removido = false;
					if( strcmp( inicio->dado , nome ) == 0){
						No *aux = inicio;
						inicio = inicio->prox;
						free( aux );
						removido = true;
					}else{
						No *ant = inicio;
						No *aux = inicio->prox;
						while( aux != NULL ){
							if( strcmp( aux->dado , nome ) == 0 ){
								ant->prox = aux->prox;
								free( aux );
								removido = true;
								break;
							}else{
								aux = aux->prox;	
							}
						}
					}
					if( removido )
						printf("%s removido!\n", nome);
					else
						printf("%s nao encontrado na lista!\n", nome);
				}
				
				break;
			case 0:
				break;
			default:
				system( "cls" );
				printf( "\nEscolha inexistente\n");	
		}
		
	}while( opcao != 0 );
	system( "cls" );
	printf( "\n\nBye-bye!!!");
	
}



