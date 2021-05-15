#include <stdio.h>
#include <stdlib.h>

/* 
Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e retorne um 
ponteiro. Crie uma função que receba um ponteiro para um vetor e um valor n e imprima os n elementos 
desse vetor. Construa também uma função que receba um ponteiro para um vetor e libere esta área de 
memória. Ao final, crie uma função principal que leia um valor n e chame a função criada acima. Depois, 
a função principal deve ler os n elementos desse vetor. Então, a função principal deve chamar a função de 
impressão dos n elementos do vetor criado e, finalmente, liberar a memória alocada através da função criada 
para liberação.
*/

// Função para ler os elementos do vetor.
void leitura_e_impressao_dos_elementos(int *vetor, int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("Insira o valor %d: ", i+1);
		scanf("%d", &vetor[i]);
	}
	
	printf("Impressao dos valores do vetor:\n");
	
	for(i=0; i<n; i++){
		printf("%d\t", vetor[i]);
	}
}

// Função que recebe o valor de n.
int recebe_valor_n(){
	int n;
	
	printf("Insira a quantidade maxima de elementos do vetor: ");
	scanf("%d", &n);

	return n;
}

// Função que recebe o valor de n.
int *alocar_vetor(int n){
	int *vetor;
	
	// Aloca dinamicamente a memória do vetor.
	vetor = (int*)malloc(sizeof(int)*n);

	// Se o vetor for nulo, mostra uma mensagem de erro.
	if(vetor==NULL){
		printf("Falha na alocacao de memoria!\n");
		
		exit(1);
	}
	
	return vetor;
}

// Função que libera a memória.
void libera(int *vetor){
	free(vetor);	
}

// Função principal.
int main() {
	// Recebe o valor de n da função "recebe_valor_n()".
	int n = recebe_valor_n();
	
	// Recebe o valor do ponteiro vetor da função "alocar_vetor(n)".
	// "alocar_vetor(n)" recebe n como parâmetro para reservar tamanho da memória a ser alocada.
	int *vetor = alocar_vetor(n);
	
	// Realizar a leitura dos elementos do vetor e imprimir em seguida.
	leitura_e_impressao_dos_elementos(vetor, n);
	
	// Função que libera a memória alocada.
	libera(vetor);
	
	return 0;
}
