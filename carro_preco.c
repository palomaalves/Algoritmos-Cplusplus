#include <stdio.h>
#include <stdlib.h>

/* 
Desenvolver um algoritmo para calcular e imprimir o pre�o final de um carro. O valor do pre�o inicial 
de f�brica � fornecido por meio de entrada. O carro pode ter as seguintes op��es:
� (a) Ar condicionado: R$ 2.450,00
� (b) Pintura Met�lica: R$ 900,00
� (c) Vidro El�trico: R$ 1.800,00
� (d) Dire��o Hidr�ulica: R$ 2200,00 
*/

int main() {
	char opc;
	float preco;
	float ar_condicionado = 2450.0;
	float pintura_metalica = 900.0;
	float vidro_eletrico = 1800.0;
	float direcao_hidraulica = 2200.0;
	
	printf("Digite o preco inicial do carro: ");
	scanf("%f", &preco);
	
	printf("====== OPCOES =======\n");
	printf("Informe com (s-n) as opcoes que desejar: \n");
	printf("(a) Ar condicionado: R$ 2.450,00\n");
	scanf(" %c", &opc);
	fflush(stdin);
	
	if(opc == 's')
		preco+=ar_condicionado;
	
	printf("(b) Pintura Metalica: R$ 900,00\n");
	scanf(" %c", &opc);
	fflush(stdin);
	
	if(opc == 's')
		preco+=pintura_metalica;

	printf("(c) Vidro Eletrico: R$ 1.800,00\n");
	scanf(" %c", &opc);
	fflush(stdin);
	
	if(opc == 's')
		preco+=vidro_eletrico;
		
	printf("(d) Direcao Hidraulica: R$ 2200,00\n");
	scanf(" %c", &opc);
	fflush(stdin);
	
	if(opc == 's')
		preco+=direcao_hidraulica;	
	
	printf("Preco final do carro = R$ %.2f", preco);
	
	return 0;
}
