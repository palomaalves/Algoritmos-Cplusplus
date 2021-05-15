#include <stdio.h>
#include <stdlib.h>

/* 
Uma empresa concederá um aumento de salário aos seus funcionários, variável de acordo com o cargo, 
conforme a tabela abaixo. Faça um algoritmo que leia o salário e o cargo de um funcionário e calcule o novo 
salário. Se o cargo do funcionário não estiver na tabela, ele deverá receber 40% de aumento. Mostre o 
salário antigo, o novo salário e a diferença.

Código  Cargo  Percentual
 101   Gerente    10%
 102  Engenheiro  20%
 103   Técnico    30% 
 */

int main() {
	int codigo;
	float salario;
	float salario_final;
	float reajuste;
	
	printf("Informe o codigo do seu cargo: ");
	scanf("%d", &codigo);
			
	printf("Informe o salario: ");
	scanf("%f", &salario);
	
	switch(codigo){
		case 101:
			printf("Gerente\n");
			printf("Salario inicial = %.2f\n", salario);
			reajuste = salario*0.1;
			salario_final = salario + reajuste;
			printf("Salario final = %.2f\n", salario_final);
			printf("Diferenca = %.2f", salario_final-salario);
		break;

		case 102:
			printf("Engenheiro\n");
			printf("Salario inicial = %.2f\n", salario);
			reajuste = salario*0.2;
			salario_final = salario + reajuste;
			printf("Salario final = %.2f\n", salario_final);
			printf("Diferenca = %.2f", salario_final-salario);			
		break;

		case 103:
			printf("Tecnico\n");
			printf("Salario inicial = %.2f\n", salario);
			reajuste = salario*0.3;
			salario_final = salario + reajuste;
			printf("Salario final = %.2f\n", salario_final);
			printf("Diferenca = %.2f", salario_final-salario);			
		break;
		
		default:
			printf("Cargo nao encontrado na tabela\n");
			printf("Salario inicial = %.2f\n", salario);
			reajuste = salario*0.4;
			salario_final = salario + reajuste;
			printf("Salario final = %.2f\n", salario_final);
			printf("Diferenca = %.2f", salario_final-salario);						
		break;
	}
	
	return 0;
}
