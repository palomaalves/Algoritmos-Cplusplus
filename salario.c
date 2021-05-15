#include <stdio.h>
#include <stdlib.h>

/* 
Fazer um algoritmo que calcule e imprima o sal�rio reajustado de um funcion�rio de acordo com as 
seguintes regras:
� Sal�rio de at� R$ 500,00 reajuste de 50%;
� Sal�rio maiores que R$ 200,00 reajuste de 30%;
*/

int main() {
	float salario;
	float reajuste;
	
	printf("Digite o salario: ");
	scanf("%f", &salario);
	
	if(salario>500){
		printf("Salario n/ sofrera reajuste.\n");
		printf("Salario = %.2f", salario);
	}else if(salario<=500){
		reajuste = salario*0.5;
		salario+=reajuste;
		printf("Salario com reajuste de 50%% = %.2f", salario);		
	}else if(salario>200){
		reajuste = salario*0.3;
		salario += reajuste;
		printf("Salario com reajuste de 30%% = %.2f", salario);				
	}else if(salario<=200){
		printf("Salario n/ sofrera reajuste.\n");
		printf("Salario = %.2f", salario);		
	}
	
	return 0;
}
