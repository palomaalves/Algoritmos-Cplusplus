#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Fa�a um programa que gerencie o estoque de um mercado e:
� crie e leia um vetor de 5 produtos, com os dados: c�digo (inteiro), nome (m�ximo 15 letras), pre�o e 
quantidade.
� Leia um pedido, composto por um c�digo de produto e a quantidade. Localize este c�digo no vetor e, se 
houver quantidade suficiente para atender ao pedido integralmente, atualize o estoque e informe o usu�rio. 
Repita este processo at� ler um c�digo igual a zero. 
Se por algum motivo n�o for poss�vel atender ao pedido, mostre uma mensagem informando qual erro 
ocorreu.
*/

// Define o valor maximo do vetor da estrutura.
#define MAX 5

// Estrutura do produto.
struct produto{
	int codigo;
	char nome[50];
	float preco;
	int quantidade;
};
// Vetor estrutura.
struct produto produtos[MAX];

// Declara uma vari�vel global para a quantidade de produtos.
int quant_produtos = 0;

// Fun��o menu.
char menu(){
	char opc;
	
	printf("\nMENU\n");
	printf("(a) Cadastrar um produto\n");
	printf("(b) Diminuir o estoque de um produto cadastrado\n");
	printf("(c) Imprimir os produtos\n");
	printf("(s) Sair\n");
	printf("- ");
	scanf("%c", &opc);
	fflush(stdin);
	
	return opc;
}

// Fun��o para cadastrar os produtos.
void cadastrar_produto(){
	int tamanho_nome;
	
	for(quant_produtos=0; quant_produtos<MAX; quant_produtos++){
		// O c�digo recebe o valor da quantidade de produtos.
		// produtos[0].codigo = 0+1;
		// produtos[1].codigo = 1+1;
		// ...
		produtos[quant_produtos].codigo = quant_produtos+1;
	
		printf("\nDigite o nome do produto %d: ", quant_produtos+1);
		fgets(produtos[quant_produtos].nome, 15, stdin);
		fflush(stdin);
		tamanho_nome = strlen(produtos[quant_produtos].nome);
		
		// Restri��o para o tamanho do nome do produto.
		while(tamanho_nome > 15){
			printf("Tamanho de caracteres excedido!\n");
			printf("Digite o nome do produto: ");
			fgets(produtos[quant_produtos].nome, 15, stdin);
			fflush(stdin);
		}

		printf("Digite o preco do produto: ");
		scanf("%f", &produtos[quant_produtos].preco);
		fflush(stdin);
		
		printf("Digite a quantidade no estoque: ");
		scanf("%d", &produtos[quant_produtos].quantidade);
		fflush(stdin);	
		
		printf("\nProduto cadastrado com sucesso!\n");		
	}	
}

// Fun��o para diminuir a quantidade de produtos no estoque.
void diminuir_estoque(int quantidade){
	int codigo_pesquisa;
	int venda;
	int i;
	
	// Se n�o houver produto, mostra "Nenhum produto cadastrado!".
	if(quantidade == 0){
		printf("\nNenhum produto cadastrado!\n");
	}else{
		printf("\nSe o codigo do produto nao existir, o programa voltara ao MENU.\n");
		printf("\nInforme o codigo do produto: ");
		scanf("%d", &codigo_pesquisa);
		fflush(stdin);
		
		codigo_pesquisa -= 1;
		
		for(i=0; i<quantidade; i++){
			if(codigo_pesquisa == i){
				printf("Informe as unidades vendidas: ");
				scanf("%d", &venda);
				fflush(stdin);
				
				// Restri��o para se a quantidade de vendas (pedidos) for maior que a quantidade atual no estoque.
				if(produtos[i].quantidade<venda){
					printf("\nO estoque nao possui essa quantidade!\n");
				}else{
					produtos[i].quantidade -= venda;

					printf("\nQuantidade atualizada!\n");			
				}	
			}
		}
	}	
}

// Fun��o que lista todos os produtos.
void listar_produtos(int quantidade){
	int i;
	
	if(quantidade == 0){
		printf("\nNenhum produto cadastrado!\n");
	}else{
		printf("\nLista de produtos cadastrados:\n");
		
		for(i=0; i<quantidade; i++){
			printf("\nCodigo: %d - Nome: %s - Preco: %.2f - Quantidade: %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);		
		}		
	}
	
}

// Fun��o principal.
int main() {
	char opcao;
	
	opcao = menu();
	
	while(opcao != 's'){
		switch(opcao){
			case 'a':
				cadastrar_produto();		
			break;
		
			case 'b':
				diminuir_estoque(quant_produtos);	
			break;
		
			case 'c':
				listar_produtos(quant_produtos);
			break;
		
			default:
				printf("Opcao invalida!\n");	
			break;
		}
		opcao = menu();		
	}
	
	return 0;
}
