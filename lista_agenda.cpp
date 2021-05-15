#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/* 
Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se ter os seguintes 
dados:
• Nome
• E-mail
• Endereço (contendo campos para Rua, número, complemento, bairro, cep, cidade, estado, país).
• Telefone (contendo campo para DDD e número) 
• Data de aniversário (contendo campo para dia, mês, ano). 
• Observações: Uma linha (string) para alguma observação especial. 
(a) Definir a estrutura acima.
(b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 nomes. 
(c) Definir um bloco de instruções busca por primeiro nome: Imprime os dados da pessoa com esse nome 
(se tiver mais de uma pessoa, imprime para todas).
(d) Definir um bloco de instruções busca por mês de aniversário: Imprime os dados de todas as pessoas 
que fazem aniversario nesse mês.
(e) Definir um bloco de instruções busca por dia e mês de aniversário: Imprime os dados de todas as 
pessoas que fazem aniversario nesse dia e mês. 
(f) Definir um bloco de instruções insere pessoa: Insere por ordem alfabética de nome. 
(g) Definir um bloco de instruções retira pessoa: Retira todos os dados dessa pessoa e desloca todos os 
elementos seguintes do vetor para a posição anterior. 
(h) Definir um bloco de instruções imprime agenda com as opções: 
• Imprime nome, telefone e e-mail.
• Imprime todos os dados.
(i) O programa deve ter um menu principal oferecendo as opções acima. 
*/

typedef struct{
	char rua[20];
	int numero;
	char complemento[20];
	char bairro[20];
	int cep;
	char cidade[20];
	char estado[20];
	char pais[20];
}Endereco;

typedef struct{
	int ddd;
	int numero;
}Telefone;

typedef struct{
	int dia;
	int mes;
	int ano;
}Data;

typedef struct{
	char nome[20];
	char email[100];
	Endereco endereco_pessoal;
	Telefone telefone_pessoal;
	Data data_aniversario;
}Agenda;

Agenda agenda[MAX];

// Definir uma variável global para incrementar na quantidade de pessoas cadastradas.
int quantidade_total = 0;

// Função para ler strings.
void ler_string(char *ptr, int tam){
	fflush(stdin);
	fgets(ptr, tam, stdin);
	
	// Remove o \n da string.
	ptr[strcspn(ptr, "\n")] = 0;
}

// Função para ler char.
void ler_char(char *ptr){
	fflush(stdin);
	scanf(" %c", ptr);
}

// Função para ler inteiro.
void ler_int(int *ptr){
	fflush(stdin);
	scanf("%d", ptr);	
}

// Função para ler real.
void ler_float(float *ptr){
	fflush(stdin);
	scanf("%f", ptr);
}

// Função MENU
int menu(){
	int opc;
	
	printf("==== AGENDA ====\n");
	printf("(1) Cadastrar um contato\n");
	printf("(2) Verificar todos os contatos (Nome, Telefone, E-mail)\n");
	printf("(3) Verificar todos os contatos (Todos os dados)\n");
	printf("(4) Busca um contato pelo primeiro nome\n");
	printf("(5) Busca um contato pelo mes do aniversario\n");
	printf("(6) Busca um contato pelo dia e mes do aniversario\n");
	printf("(7) Excluir contato\n");
	printf("(8) Ordenar Agenda\n");
	printf("(0) Sair\n");
	printf("Digite a opcao: ");
	ler_int(&opc);
	
	return opc;
}

// Função para CADASTRAR CONTATO
void cadastro_contato(){
	char opc;
	
	while(opc != 'n'){
		printf("\nInforme nome: ");
		ler_string(agenda[quantidade_total].nome, 20);
			
		printf("Informe e-mail: ");	
		ler_string(agenda[quantidade_total].email, 20);
		
		printf("Informe a rua, numero, complemento, bairro, cep, cidade, estado e pais: ");	
		ler_string(agenda[quantidade_total].endereco_pessoal.rua, 20);
		ler_int(&agenda[quantidade_total].endereco_pessoal.numero);
		ler_string(agenda[quantidade_total].endereco_pessoal.complemento, 20);
		ler_string(agenda[quantidade_total].endereco_pessoal.bairro, 20);
		ler_int(&agenda[quantidade_total].endereco_pessoal.cep);
		ler_string(agenda[quantidade_total].endereco_pessoal.cidade, 20);
		ler_string(agenda[quantidade_total].endereco_pessoal.estado, 20);
		ler_string(agenda[quantidade_total].endereco_pessoal.pais, 20);
		
		printf("Informe telefone (ddd e numero):\n");
		
		do{
			printf("Insira o ddd: ");
			ler_int(&agenda[quantidade_total].telefone_pessoal.ddd);
			
			if(agenda[quantidade_total].telefone_pessoal.ddd>2 && agenda[quantidade_total].telefone_pessoal.ddd<1){
				printf("DDD POSSUI APENAS DOIS NUMEROS!\n");
			}
		}while(agenda[quantidade_total].telefone_pessoal.ddd>2 && agenda[quantidade_total].telefone_pessoal.ddd<1);
		
		do{
			printf("Insira o numero: ");
			ler_int(&agenda[quantidade_total].telefone_pessoal.numero);
	
			if(agenda[quantidade_total].telefone_pessoal.numero>8 && agenda[quantidade_total].telefone_pessoal.numero<=7){
				printf("O TELEFONE DEVE POSSUIR 8 NUMEROS!\n");
			}
		}while(agenda[quantidade_total].telefone_pessoal.numero>8 && agenda[quantidade_total].telefone_pessoal.numero<=7);
			
		printf("\nInforme data de nascimento: ");
		do{
			printf("Insira o dia: ");
			ler_int(&agenda[quantidade_total].data_aniversario.dia);
			
			// Mensagem de erro.
			if(agenda[quantidade_total].data_aniversario.dia>31 || agenda[quantidade_total].data_aniversario.dia<1){
				printf("DIA INVALIDO!\n");
			}
			
		}while(agenda[quantidade_total].data_aniversario.dia>31 || agenda[quantidade_total].data_aniversario.dia<1);
	
			// Se o mes foi maior que 12 ou menor que 1, ele irá repetir a pergunta.	
		do{
			printf("Insira o mes: ");
			ler_int(&agenda[quantidade_total].data_aniversario.mes);
			
			// Mensagem de erro.
			if(agenda[quantidade_total].data_aniversario.mes>12 || agenda[quantidade_total].data_aniversario.mes<1){
				printf("MES INVALIDO!\n");
			}else{
				// Como fevereiro tem 28 dias, ele não ira aceitar se o dia for maior ou igual a 29.
				if(agenda[quantidade_total].data_aniversario.dia>=29 && agenda[quantidade_total].data_aniversario.mes==2){
					printf("FEVEREIRO CONTEM 28 DIAS!\n");
					do{
						printf("Insira o mes: ");
						ler_int(&agenda[quantidade_total].data_aniversario.mes);	
					}while(agenda[quantidade_total].data_aniversario.dia>=29 && agenda[quantidade_total].data_aniversario.mes==2);			
				}
			}
			
		}while(agenda[quantidade_total].data_aniversario.mes>12 || agenda[quantidade_total].data_aniversario.mes<1);	
		
		printf("Insira o ano: ");
		ler_int(&agenda[quantidade_total].data_aniversario.ano);	
		
		quantidade_total++;
		
		printf("Deseja cadastrar mais uma pessoa? (s-n)");
		ler_char(&opc);		
	}
}

// Função que mostra os CONTATOS (NOME, TELEFONE, E-MAIL)
void mostrar_contatos_basico(int i){
	printf("\nPosicao na agenda: %d\n", i+1);
	printf("Nome: %s\n", agenda[i].nome);
	printf("Telefone: (%d) 9%d\n", agenda[i].telefone_pessoal.ddd, agenda[i].telefone_pessoal.numero);
	printf("E-mail: %s\n\n", agenda[i].email);		
}

// Função que mostra os CONTATOS (TODOS OS DADOS)
void mostrar_contatos_completo(int i){
	printf("\nPosicao na agenda: %d\n", i+1);
	printf("Nome: %s\n", agenda[i].nome);
	printf("E-mail: %s\n", agenda[i].email);
	printf("Endereco: %s, %d, %s, %s, %d, %s, %s, %s\n", agenda[i].endereco_pessoal.rua, agenda[i].endereco_pessoal.numero, agenda[i].endereco_pessoal.complemento, agenda[i].endereco_pessoal.bairro, agenda[i].endereco_pessoal.cep, agenda[i].endereco_pessoal.cidade, agenda[i].endereco_pessoal.estado, agenda[i].endereco_pessoal.pais);
	printf("Telefone: (%d) 9%d\n", agenda[i].telefone_pessoal.ddd, agenda[i].telefone_pessoal.numero);
	printf("Data de nascimento: %d/%d/%d\n\n", agenda[i].data_aniversario.dia, agenda[i].data_aniversario.mes, agenda[i].data_aniversario.ano);
}

// Função BUSCAR CONTATO PELO NOME
void buscar_pelo_nome(char *pesquisa_nome, int i){
	if(strcmp(pesquisa_nome, agenda[i].nome)==0){
		printf("\nPosicao na agenda: %d\n", i+1);
		printf("Nome: %s\n", agenda[i].nome);
		printf("E-mail: %s\n", agenda[i].email);
		printf("Endereco: %s, %d, %s, %s, %d, %s, %s, %s\n", agenda[i].endereco_pessoal.rua, agenda[i].endereco_pessoal.numero, agenda[i].endereco_pessoal.complemento, agenda[i].endereco_pessoal.bairro, agenda[i].endereco_pessoal.cep, agenda[i].endereco_pessoal.cidade, agenda[i].endereco_pessoal.estado, agenda[i].endereco_pessoal.pais);
		printf("Telefone: (%d) 9%d\n", agenda[i].telefone_pessoal.ddd, agenda[i].telefone_pessoal.numero);
		printf("Data de nascimento: %d/%d/%d\n\n", agenda[i].data_aniversario.dia, agenda[i].data_aniversario.mes, agenda[i].data_aniversario.ano);	
	}
}

// Função BUSCAR CONTATO PELO MES
void buscar_pelo_mes_nascimento(int pesquisa_mes, int i){
	if(pesquisa_mes == agenda[i].data_aniversario.mes){
		printf("\nPosicao na agenda: %d\n", i+1);
		printf("Nome: %s\n", agenda[i].nome);
		printf("E-mail: %s\n", agenda[i].email);
		printf("Endereco: %s, %d, %s, %s, %d, %s, %s, %s\n", agenda[i].endereco_pessoal.rua, agenda[i].endereco_pessoal.numero, agenda[i].endereco_pessoal.complemento, agenda[i].endereco_pessoal.bairro, agenda[i].endereco_pessoal.cep, agenda[i].endereco_pessoal.cidade, agenda[i].endereco_pessoal.estado, agenda[i].endereco_pessoal.pais);
		printf("Telefone: (%d) 9%d\n", agenda[i].telefone_pessoal.ddd, agenda[i].telefone_pessoal.numero);	
		printf("Data de nascimento: %d/%d/%d\n\n", agenda[i].data_aniversario.dia, agenda[i].data_aniversario.mes, agenda[i].data_aniversario.ano);	
	}
}

// Função BUSCAR CONTATO PELO DIA E MES
void buscar_pelo_dia_mes_nascimento(int pesquisa_dia, int pesquisa_mes, int i){
	if(pesquisa_dia == agenda[i].data_aniversario.dia && pesquisa_mes == agenda[i].data_aniversario.mes){
		printf("\nPosicao na agenda: %d\n", i+1);
		printf("Nome: %s\n", agenda[i].nome);
		printf("E-mail: %s\n", agenda[i].email);
		printf("Endereco: %s, %d, %s, %s, %d, %s, %s, %s\n", agenda[i].endereco_pessoal.rua, agenda[i].endereco_pessoal.numero, agenda[i].endereco_pessoal.complemento, agenda[i].endereco_pessoal.bairro, agenda[i].endereco_pessoal.cep, agenda[i].endereco_pessoal.cidade, agenda[i].endereco_pessoal.estado, agenda[i].endereco_pessoal.pais);
		printf("Telefone: (%d) 9%d\n", agenda[i].telefone_pessoal.ddd, agenda[i].telefone_pessoal.numero);	
		printf("Data de nascimento: %d/%d/%d\n\n", agenda[i].data_aniversario.dia, agenda[i].data_aniversario.mes, agenda[i].data_aniversario.ano);	
	}
}

//void ordenar_agenda(int i){
//	int y;
//	char aux[10];
//	
//	for(y = i; y<quantidade_total; y++){
//		if(agenda[i].nome > agenda[y].nome){
//			aux[10] = agenda[i].nome;
//			agenda[i].nome = agenda[y].nome;
//			agenda[y].nome = aux[10];
//		}
//	}
//}

// Função PRINCIPAL
int main() {
	int opcao;
	
	int i = 0;
	
	char pesquisa_nome[20];
	int pesquisa_dia;
	int pesquisa_mes;
	
	opcao = menu();
	
	while(opcao != 0){
		switch(opcao){
				case 1:
					cadastro_contato();
				break;
		
				case 2:
					for(i=0; i<quantidade_total; i++){
						mostrar_contatos_basico(i);
					}
				break;
		
				case 3:
					for(i=0; i<quantidade_total; i++){
						mostrar_contatos_completo(i);
					}			
				break;
		
				case 4:
					printf("Digite o nome desejado para a busca na agenda: ");
					ler_string(pesquisa_nome, 20);
					
					for(i=0; i<quantidade_total; i++){
						buscar_pelo_nome(pesquisa_nome, i);
					}
				break;
		
				case 5:
					printf("Digite o mes desejado para a busca na agenda: ");
					ler_int(&pesquisa_mes);
					
					for(i=0; i<quantidade_total; i++){
						buscar_pelo_mes_nascimento(pesquisa_mes, i);
					}	
				break;
		
				case 6:
					printf("Digite o dia e o mes desejado para a busca na agenda\n");
					printf("Dia: ");
					ler_int(&pesquisa_dia);
					printf("Mes: ");
					ler_int(&pesquisa_mes);
					
					for(i=0; i<quantidade_total; i++){
						buscar_pelo_dia_mes_nascimento(pesquisa_dia, pesquisa_mes, i);
					}					
				break;
		
				case 7:
					
				break;
				
				case 8:
//					for(i=0; i<quantidade_total; i++){
//						ordenar_agenda(i);
//					}	
				break;	
				
				default:
					printf("Opcao invalida!\n");
				break;	
			}
			
		opcao = menu();	
	}
	
	printf("Finalizando programa!\n");
	
	return 0;
}
