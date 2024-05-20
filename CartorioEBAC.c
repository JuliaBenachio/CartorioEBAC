#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings


//In�cio do c�digo
int adicionar() //Fun��o que � respons�vel por adicionar usu�rios ao sistema
	{

	//Cria��o das vari�veis/string de cadastro do usu�rio
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das vari�veis/string de cadastro do usu�rio
	
	
	printf("Inclua o CPF que deseja adicionar ao sistema: "); //Pedido de coleta das informa��es do usu�rio
	scanf("%s", cpf); //Armazena a informa��o de uma string (%s)
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e com o "w" o escreve
	fprintf(file,cpf); //Salva o valor da vari�vel (CPF) no documento
	fclose(file); //Fecha o arquivo (IMPORTANTE!!!!!)
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza com "a"
	fprintf(file, ","); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Inclua o nome do usu�rio: "); //Pedido de coleta das informa��es
	scanf("%s", nome); //Armazena a informa��o de uma string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, nome); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, ","); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Inclua o sobrenome do usu�rio: "); //Pedido de coleta das informa��es
	scanf("%s", sobrenome); //Armazena a informa��o da string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, sobrenome); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, ","); //Salva o valor no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Inclua o cargo do usu�rio: "); //Pedido de coleta de informa��es
	scanf("%s", cargo); //Armazena a informa��o da string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o atualiza
	fprintf(file, cargo); //Salva a informa��o no arquivo
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Comunica��o com o sistema, solicitando uma pausa
	
}

int consultar() {
	
	setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem utilizada no programa
	
	//Cria��o das vari�veis/string para consulta do usu�rio
	char cpf[40];
	char conteudo[200];
	//Final das vari�veis/string para consulta do usu�rio
	
	printf("Inclua o CPF do usu�rio que deseja consultar no sistema: "); //Pedido de coleta da informa��o a ser consultada
	scanf("%s", cpf); //Armazena a informa��o da string
	
	FILE *file; //Cria o arquivo ou informa
	file = fopen(cpf, "r"); //Abre o arquivo e solicita a leitura do mesmo por meio de "r"
	
	if(file == NULL) //Se a consulta do arquivo for igual a nulo ou inexistente, o c�digo n�o vai localizar o mesmo
	{
		
		printf("Arquivo n�o localizado!\n"); //Vai avisar que o arquivo n�o existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto a consulta de informa��o no arquivo for diferente de nulo
	{
		
		printf("\nEssas s�o as informa��es do usu�rio: "); //Mensagem de resposta da consulta
		printf("%s", conteudo); //Declara as informa��es encontradas
		printf("\n\n"); //Pula linha
	}
	
	system("pause"); //Comunica��o com o sistema solicitando uma pausa
	
	fclose(file);
	
}

int deletar() {
	
	//Cria��o da vari�vel/string a ser deletada
	char cpf[40];
	//FInal da vari�vel/string a ser deletada
	
	printf("Inclua o CPF do usu�rio que deseja deletar do sistema:\n"); //Pedido de coleta de informa��o do usu�rio
	scanf("%s", cpf); //Armazenamento da informa��o na string
	
	remove(cpf); //Exclus�o da informa��o
	
	FILE *file; //Cria��o do arquivo ou informa
	file = fopen(cpf, "r"); //Abertura do arquivo e pedido de leitura do mesmo
	
	if (file == NULL) //Enquanto o arquivo for igual a nulo ou inexistente, o c�digo n�o vai localizar o mesmo
	{
		
		printf("O usu�rio n�o existe ou foi deletado!\n"); //Mensagem que confirma ou informa a situa��o do usu�rio
		system("pause"); //Comunica��o com o sistema solicitando uma pausa
	} 
	
	fclose(file); //Fecha o arquivo
}

int main() 
{
	int opcao=0; //Defini��o de vari�vel
	int laco=1; //Defina��o de var�avel para o la�o
	
	for(laco=1;laco=1;) //In�cio e defini��o do la�o de repeti��o
	{
		
		system("cls"); //Respons�vel pela limpeza da tela
	
		setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem utilizada no programa
	
		printf("\tCart�rio da EBAC\n\n\n"); //In�cio do menu
		printf("Selecione como deseja prosseguir: \n\n");
		printf("\t1 - Adicionar um nome\n");
		printf("\t2 - Consultar um nome\n");
		printf("\t3 - Deletar um nome\n");
		printf("\t4 - Sair do sistema.\n\n\n");
		printf("Resposta: "); //�ltima op��o e fim do menu interativo
	
		scanf("%d", &opcao); //Armazenar a informa��o inserida pelo usu�rio na vari�vel
	
		system("cls"); //Respons�vel pela limpeza da tela
		
		switch(opcao) //In�cio do c�digo de repeti��o
		{
			
			case 1: //Condi��o
			adicionar(); //Chamada de fun��o
			break; //Quebra da fun��o
			
			case 2: //Condi��o
			consultar(); //Chamada de fun��o
			break; //Quebra da fun��o
			
			case 3: //Condi��o
			deletar(); //Chamada de fun��o 
			break; //Quebra de fun��o
			
			case 4:
			printf("Obrigado por utilizar nosso sistema! At� breve!");
			return 0;
			break;
			
			default: //Condi��o e/ou t�rmino do c�digo de repeti��o
			printf("Essa op��o n�o est� dispon�vel! Volte ao menu.\n"); //Informa��o de informa��o inexistente
			system("pause"); //Comunica��o com o sistema solicitando uma pausa
			break; //Quebra da fun��o
			
		}
	
	}
} //Fim do c�digo
