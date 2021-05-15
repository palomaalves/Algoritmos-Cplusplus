#include <stdio.h>
#include <stdlib.h>

/* 
Uma empresa conceder� um aumento de sal�rio aos seus funcion�rios, vari�vel de acordo com o cargo, 
conforme a tabela abaixo. Fa�a um algoritmo que leia o sal�rio e o cargo de um funcion�rio e calcule o novo 
sal�rio. Se o cargo do funcion�rio n�o estiver na tabela, ele dever� receber 40% de aumento. Mostre o 
sal�rio antigo, o novo sal�rio e a diferen�a.

C�digo  Cargo  Percentual
 101   Gerente    10%
 102  Engenheiro  20%
 103   T�cnico    30% 
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
