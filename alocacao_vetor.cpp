#include <stdio.h>
#include <stdlib.h>

/* 
Fa�a um programa que leia um valor n e crie dinamicamente um vetor de n elementos e passe esse vetor 
para uma fun��o que vai ler os elementos desse vetor. Depois, no programa principal, o vetor preenchido 
deve ser impresso. Al�m disso, antes de finalizar o programa, deve-se liberar a �rea de mem�ria alocada. 
*/

// Fun��o para ler os elementos do vetor.
void ler_elementos(int *vetor, int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("Insira o valor %d: ", i+1);
		scanf("%d", &vetor[i]);
	}
}

// Fun��o principal.
int main() {
	int n;
	int *vetor;
	int i;
	
	printf("Insira a quantidade maxima de elementos do vetor: ");
	scanf("%d", &n);
	
	// Aloca dinamicamente a mem�ria do vetor.
	vetor = (int*)malloc(sizeof(int)*n);
	
	// Se o vetor for nulo, mostra uma mensagem de erro.
	if(vetor==NULL){
		printf("Falha na alocacao de memoria!\n");
		
		exit(1);
	}
	
	ler_elementos(vetor, n);
	
	printf("Impressao dos valores do vetor:\n");
	
	for(i=0; i<n; i++){
		printf("%d\t", vetor[i]);
	}

	// Libera a mem�ria.
	free(vetor);
	
	return 0;
}
