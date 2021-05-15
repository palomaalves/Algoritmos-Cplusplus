#include <stdio.h>
#include <stdlib.h>

/* 
Elabore um algoritmo que preencha duas matrizes 8×8 com valores aleatórios 0 e 1 e em seguida, 
determine se as matrizes são iguais (possuem os mesmos valores em cada posição). 
*/

int main() {
	// Matrizes principais.
	int mat_a[8][8];
	int mat_b[8][8];
	// Matriz de comparação.
	int mat_c[8][8];
	
	int i;
	int j;
	
	// Preenchimento da matriz A
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			// A matriz recebe um número aleatória limitado de [0, 1].
			mat_a[i][j] = (rand() % 2); 
		}
	}

	// Preenchimento da matriz B
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			// A matriz recebe um número aleatória limitado de [0, 1].
			mat_b[i][j] = (rand() % 2);
		}
	}
	
	printf("Matriz A:\n");
	// Impressão da matriz A
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			printf("%d\t", mat_a[i][j]);
		}
		printf("\n");
	}

	printf("\nMatriz B:\n");
	// Impressão da matriz B	
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			printf("%d\t", mat_b[i][j]);
		}
		printf("\n");
	}

	printf("\nMatriz Comparacao:\n");
	// Comparação de elementos iguais de cada matriz
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(mat_a[i][j]==mat_b[i][j]){
				printf("=\t");
			}else{
				printf("!=\t");
			}
		}
		printf("\n");
	}	
	
	
	return 0;
}
