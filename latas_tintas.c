#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

/* 
Construa um algoritmo que calcule e escreva o custo e a quantidade de latas de tinta necessárias, para 
pintar tanques cilíndricos de combustível. É fornecida as seguintes informações: o preço da lata de 5 litros, 
o raio e a altura dos tanques cilíndricos. Cada litro de tinta pinta 3 metros quadrados.
*/

int main() {
	float raio, altura;
	float area_cilindro;
	float litros;
	float quantidade_latas;
	float custo;
	float preco;
	
	printf("Informe o preco da lata de tinta: ");
	scanf("%f", &preco);
	
	printf("Informe o raio da area em metros: ");
	scanf("%f", &raio);
	
	printf("Informe a altura da area em metros: ");
	scanf("%f", &altura);
	
	area_cilindro = 2*(PI*pow(raio, 2)) + 2*PI*raio*altura;
	
	litros = area_cilindro/3;
	
	quantidade_latas = area_cilindro/5;
	
	custo = quantidade_latas * preco;
	
	printf("\nArea do cilindro: %.2f m^2", area_cilindro);
	printf("\nQuantidade de latas necessarias: %.0f", quantidade_latas);
	printf("\nCusto total: R$%.2f", custo);

	return 0;
}
