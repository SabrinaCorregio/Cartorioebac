#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
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
		printf("Cpf não locaizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
		
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
		
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
			
	FILE *file;   //Abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	file = fopen(cpf,"r");
		
	if(file == NULL)   //Em caso de numero não encontrado no arquivo
	{
		printf("O CPF digitado nã pertence a um usuário cadastrado \n\n");   //Mensagem exibida ao ususario
		system("pause");   //Comando para pausar a tela
		return 0;    //Comando que faz o usuario retornar a tela inicial
	}
	
	fclose(file);   //Fecha o arquivo depois de verificar a existencia dele 
	
	printf("Confira os dados a serem deletados: ");   //Confirmando a escolha do usuario sobre deletar ou nao este aluno
	printf("%s", cpf);   //Mostra o cpf a ser deletado
	printf("\nDigite (s) para sim ou digite (n) para não!\n\n");   //Dando escolha para o usuario fazer em caracteres
	
	getchar();   //Função para capturar a entrada do usuario atraves de caracteres
	
	char opcao;   //criando variavel opcao
	opcao = getchar();   //definindo que a variavel opcao sera referente ao getchar
	
	if (opcao == 's' || opcao == 'S')    //se o caractere for maiusculo ou minusculo
	{
		if (remove(cpf) == 0)   //remove o arquivo
		{
			
			printf("Aluno deletedo com sucesso!\n");   //Mensagem ao usuario de confirmação da remoção
			system("pause");
			
		}
		
	}
	
	else if (opcao == 'n' || opcao =='N')    //se o caractere for maiusculo ou minusculo
	{
		printf("Retorne ao menu principal. \n\n");    //Mensagem oo usuario caso ele não confirme a exclusão do cpf
		system("pause");
	}
	
	else
	{
		printf("Opção inválida!");   
		system("pause");
	}
	
		
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;	
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)
		{	
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 		

			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha o que deseja fazer agora:\n\n");
			printf("\t1-Incluir novos alunos\n");
			printf("\t2-Consultar um aluno\n");
			printf("\t3-Remover um aluno\n");
			printf("\t4-Sair do sistema\n\n");
			printf("Opção: "); //Final do menu
	
			scanf("%d", &opcao); //Armazeando as informações
	
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
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			}
		}
	}
	
	else
	 printf("Senha incorreta\n\n");
	 
	 
}
	
	
