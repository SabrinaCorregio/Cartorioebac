#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);                                //Responsavel por copiar os valores das strings
	
	FILE *file;                                        //cria o arquivo
	file = fopen(arquivo, "w");                        //cria o arquivo
	fprintf(file,cpf);                                //salvar o valor da variavel
	fclose(file);                                     //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadsatrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
		
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Cpf n�o locaizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
		
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
		
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
			
	FILE *file;   //Abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	file = fopen(cpf,"r");
		
	if(file == NULL)   //Em caso de numero n�o encontrado no arquivo
	{
		printf("O CPF digitado n� pertence a um usu�rio cadastrado \n\n");   //Mensagem exibida ao ususario
		system("pause");   //Comando para pausar a tela
		return 0;    //Comando que faz o usuario retornar a tela inicial
	}
	
	fclose(file);   //Fecha o arquivo depois de verificar a existencia dele 
	
	printf("Confira os dados a serem deletados: ");   //Confirmando a escolha do usuario sobre deletar ou nao este aluno
	printf("%s", cpf);   //Mostra o cpf a ser deletado
	printf("\nDigite (s) para sim ou digite (n) para n�o!\n\n");   //Dando escolha para o usuario fazer em caracteres
	
	getchar();   //Fun��o para capturar a entrada do usuario atraves de caracteres
	
	char opcao;   //criando variavel opcao
	opcao = getchar();   //definindo que a variavel opcao sera referente ao getchar
	
	if (opcao == 's' || opcao == 'S')    //se o caractere for maiusculo ou minusculo
	{
		if (remove(cpf) == 0)   //remove o arquivo
		{
			
			printf("Aluno deletedo com sucesso!\n");   //Mensagem ao usuario de confirma��o da remo��o
			system("pause");
			
		}
		
	}
	
	else if (opcao == 'n' || opcao =='N')    //se o caractere for maiusculo ou minusculo
	{
		printf("Retorne ao menu principal. \n\n");    //Mensagem oo usuario caso ele n�o confirme a exclus�o do cpf
		system("pause");
	}
	
	else
	{
		printf("Op��o inv�lida!");   
		system("pause");
	}
	
		
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;	
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)
		{	
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 		

			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha o que deseja fazer agora:\n\n");
			printf("\t1-Incluir novos alunos\n");
			printf("\t2-Consultar um aluno\n");
			printf("\t3-Remover um aluno\n");
			printf("\t4-Sair do sistema\n\n");
			printf("Op��o: "); //Final do menu
	
			scanf("%d", &opcao); //Armazeando as informa��es
	
			system("cls");
		
			switch(opcao)
			
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();			
				break;
			
				case 4:
				printf("Obrigada por utilizar o sistema!\n\n");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			}
		}
	}
	
	else
	 printf("Senha incorreta\n\n");
	 
	 
}
	
	
