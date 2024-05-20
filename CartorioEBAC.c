#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings


//Início do código
int adicionar() //Função que é responsável por adicionar usuários ao sistema
	{

	//Criação das variáveis/string de cadastro do usuário
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das variáveis/string de cadastro do usuário
	
	
	printf("Inclua o CPF que deseja adicionar ao sistema: "); //Pedido de coleta das informações do usuário
	scanf("%s", cpf); //Armazena a informação de uma string (%s)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e com o "w" o escreve
	fprintf(file,cpf); //Salva o valor da variável (CPF) no documento
	fclose(file); //Fecha o arquivo (IMPORTANTE!!!!!)
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza com "a"
	fprintf(file, ","); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Inclua o nome do usuário: "); //Pedido de coleta das informações
	scanf("%s", nome); //Armazena a informação de uma string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, nome); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, ","); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Inclua o sobrenome do usuário: "); //Pedido de coleta das informações
	scanf("%s", sobrenome); //Armazena a informação da string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, sobrenome); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, ","); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Inclua o cargo do usuário: "); //Pedido de coleta de informações
	scanf("%s", cargo); //Armazena a informação da string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, cargo); //Salva a informação no arquivo
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Comunicação com o sistema, solicitando uma pausa
	
}

int consultar() {
	
	setlocale(LC_ALL, "Portuguese"); //Definição de linguagem utilizada no programa
	
	//Criação das variáveis/string para consulta do usuário
	char cpf[40];
	char conteudo[200];
	//Final das variáveis/string para consulta do usuário
	
	printf("Inclua o CPF do usuário que deseja consultar no sistema: "); //Pedido de coleta da informação a ser consultada
	scanf("%s", cpf); //Armazena a informação da string
	
	FILE *file; //Cria o arquivo ou informa
	file = fopen(cpf, "r"); //Abre o arquivo e solicita a leitura do mesmo por meio de "r"
	
	if(file == NULL) //Se a consulta do arquivo for igual a nulo ou inexistente, o código não vai localizar o mesmo
	{
		
		printf("Arquivo não localizado!\n"); //Vai avisar que o arquivo não existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto a consulta de informação no arquivo for diferente de nulo
	{
		
		printf("\nEssas são as informações do usuário: "); //Mensagem de resposta da consulta
		printf("%s", conteudo); //Declara as informações encontradas
		printf("\n\n"); //Pula linha
	}
	
	system("pause"); //Comunicação com o sistema solicitando uma pausa
	
	fclose(file);
	
}

int deletar() {
	
	//Criação da variável/string a ser deletada
	char cpf[40];
	//FInal da variável/string a ser deletada
	
	printf("Inclua o CPF do usuário que deseja deletar do sistema:\n"); //Pedido de coleta de informação do usuário
	scanf("%s", cpf); //Armazenamento da informação na string
	
	remove(cpf); //Exclusão da informação
	
	FILE *file; //Criação do arquivo ou informa
	file = fopen(cpf, "r"); //Abertura do arquivo e pedido de leitura do mesmo
	
	if (file == NULL) //Enquanto o arquivo for igual a nulo ou inexistente, o código não vai localizar o mesmo
	{
		
		printf("O usuário não existe ou foi deletado!\n"); //Mensagem que confirma ou informa a situação do usuário
		system("pause"); //Comunicação com o sistema solicitando uma pausa
	} 
	
	fclose(file); //Fecha o arquivo
}

int main() 
{
	int opcao=0; //Definição de variável
	int laco=1; //Definação de varíavel para o laço
	
	for(laco=1;laco=1;) //Início e definição do laço de repetição
	{
		
		system("cls"); //Responsável pela limpeza da tela
	
		setlocale(LC_ALL, "Portuguese"); //Definição de linguagem utilizada no programa
	
		printf("\tCartório da EBAC\n\n\n"); //Início do menu
		printf("Selecione como deseja prosseguir: \n\n");
		printf("\t1 - Adicionar um nome\n");
		printf("\t2 - Consultar um nome\n");
		printf("\t3 - Deletar um nome\n");
		printf("\t4 - Sair do sistema.\n\n\n");
		printf("Resposta: "); //Última opção e fim do menu interativo
	
		scanf("%d", &opcao); //Armazenar a informação inserida pelo usuário na variável
	
		system("cls"); //Responsável pela limpeza da tela
		
		switch(opcao) //Início do código de repetição
		{
			
			case 1: //Condição
			adicionar(); //Chamada de função
			break; //Quebra da função
			
			case 2: //Condição
			consultar(); //Chamada de função
			break; //Quebra da função
			
			case 3: //Condição
			deletar(); //Chamada de função 
			break; //Quebra de função
			
			case 4:
			printf("Obrigado por utilizar nosso sistema! Até breve!");
			return 0;
			break;
			
			default: //Condição e/ou término do código de repetição
			printf("Essa opção não está disponível! Volte ao menu.\n"); //Informação de informação inexistente
			system("pause"); //Comunicação com o sistema solicitando uma pausa
			break; //Quebra da função
			
		}
	
	}
} //Fim do código
