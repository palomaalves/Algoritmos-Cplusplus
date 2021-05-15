#include <stdio.h>
#include <stdlib.h>

/*
Dada a atual crise h�drica do pa�s, as pessoas come�aram a construir reservat�rios para armazenar �gua 
em suas propriedades. Fa�a um programa em linguagem C que auxilie os utilizadores do reservat�rio a 
controlarem seu consumo. Obtenha do teclado as dimens�es de um reservat�rio (altura, largura e 
comprimento, em cent�metros) e o consumo m�dio di�rio dos utilizadores do reservat�rio (em litros/dia).
Assuma que o reservat�rio esteja cheio, tenha formato c�bico e informe:
(a) A capacidade total do reservat�rio, em litros;
(b) A autonomia do reservat�rio, em dias;
(c) A classifica��o do consumo, de acordo com a quantidade de dias de autonomia: Consumo elevado, se a 
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
