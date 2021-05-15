#include <stdio.h>
#include <stdlib.h>

/* 
Fa�a uma fun��o que receba um valor n e crie dinamicamente um vetor de n elementos e retorne um 
ponteiro. Crie uma fun��o que receba um ponteiro para um vetor e um valor n e imprima os n elementos 
desse vetor. Construa tamb�m uma fun��o que receba um ponteiro para um vetor e libere esta �rea de 
mem�ria. Ao final, crie uma fun��o principal que leia um valor n e chame a fun��o criada acima. Depois, 
a fun��o principal deve ler os n elementos desse vetor. Ent�o, a fun��o principal deve chamar a fun��o de 
impress�o dos n elementos do vetor criado e, finalmente, liberar a mem�ria alocada atrav�s da fun��o criada 
para libera��o.
*/

// Fun��o para ler os elementos do vetor.
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

// Fun��o que recebe o valor de n.
int recebe_valor_n(){
	int n;
	
	printf("Insira a quantidade maxima de elementos do vetor: ");
	scanf("%d", &n);

	return n;
}

// Fun��o que recebe o valor de n.
int *alocar_vetor(int n){
	int *vetor;
	
	// Aloca dinamicamente a mem�ria do vetor.
	vetor = (int*)malloc(sizeof(int)*n);

	// Se o vetor for nulo, mostra uma mensagem de erro.
	if(vetor==NULL){
		printf("Falha na alocacao de memoria!\n");
		
		exit(1);
	}
	
	return vetor;
}

// Fun��o que libera a mem�ria.
void libera(int *vetor){
	free(vetor);	
}

// Fun��o principal.
int main() {
	// Recebe o valor de n da fun��o "recebe_valor_n()".
	int n = recebe_valor_n();
	
	// Recebe o valor do ponteiro vetor da fun��o "alocar_vetor(n)".
	// "alocar_vetor(n)" recebe n como par�metro para reservar tamanho da mem�ria a ser alocada.
	int *vetor = alocar_vetor(n);
	
	// Realizar a leitura dos elementos do vetor e imprimir em seguida.
	leitura_e_impressao_dos_elementos(vetor, n);
	
	// Fun��o que libera a mem�ria alocada.
	libera(vetor);
	
	return 0;
}
