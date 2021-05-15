#include <stdio.h>
#include <stdlib.h>

/*
Dada a atual crise hídrica do país, as pessoas começaram a construir reservatórios para armazenar água 
em suas propriedades. Faça um programa em linguagem C que auxilie os utilizadores do reservatório a 
controlarem seu consumo. Obtenha do teclado as dimensões de um reservatório (altura, largura e 
comprimento, em centímetros) e o consumo médio diário dos utilizadores do reservatório (em litros/dia).
Assuma que o reservatório esteja cheio, tenha formato cúbico e informe:
(a) A capacidade total do reservatório, em litros;
(b) A autonomia do reservatório, em dias;
(c) A classificação do consumo, de acordo com a quantidade de dias de autonomia: Consumo elevado, se a 
autonomia for menor que 2 dias; Consumo moderado, se a autonomia estiver entre 2 e 7 dias; Consumo 
reduzido, se a autonomia maior que 7 dias.

Obs.: Considere que cada litro equivale a 1000 cm3
ou 1 dm3. 
*/

int main() {
	int altura;
	int largura;
	int comprimento;
	float consumo_litros;
	int capacidade_total = 0;
	int litros = 0;
	float autonomia = 0;
	
	printf("Informe a altura (cm) do reservatorio: ");
	scanf("%d", &altura);

	printf("Informe a largura (cm) do reservatorio: ");
	scanf("%d", &largura);

	printf("Informe a comprimento (cm) do reservatorio: ");
	scanf("%d", &comprimento);
	
	printf("Informe o consumo medio de diario (L) dos utilizadores do reservatorio: ");
	scanf("%f", &consumo_litros);
	
	printf("\nCapacidade total do reservatorio = %d cm^3\n", capacidade_total = altura*largura*comprimento);
	printf("Capacidade total em litros = %d L\n", litros = capacidade_total/1000);
	
	autonomia = (float)litros/consumo_litros;
	
	printf("Autonomia do reservatorio = %.0f dias\n", autonomia);
	
	printf("Classificacao do consumo:\n");
	
	if(autonomia<2){
		printf("Consumo elevado.");
	}else if(autonomia>=2 && autonomia<7){
		printf("Consumo moderado");
	}else{
		printf("Consumo reduzido.");
	}
	
	return 0;
}
