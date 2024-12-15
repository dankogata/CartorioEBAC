#include <stdio.h> //biblioteca padr�o
#include <stdlib.h> //biblioteca que usa de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de tete por regi�o
#include <string.h> //biblioteca de string

int registro()
{
	//iniciando vari�veis e tamanho
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//input de cpf
	printf("Digite o CPF a ser cadastrada: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //Copia de strings
	
	//input cpf
	FILE *file; //chamando file nas bibliotecas
	file = fopen(arquivo, "w"); //abertura de arquivo e escrever "w" ==> criar arquivo
	fprintf(file,cpf);//print do arquivo e cpf ==> salvar
	fclose(file); //fechar a fun��o de arquivo
	
	file = fopen(arquivo,"a"); //"a" atualiza os dados sem criar novo arquivo
	fprintf(file,","); // salvar nome dentro do arquivo
	fclose(file);
	printf("====================================================\n\n");
	//input nome
	printf("Digite o nome a ser cadastrada: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); //"a" atualiza os dados sem criar novo arquivo
	fprintf(file,nome); // salvar nome dentro do arquivo
	fprintf(file,",");
	fclose(file);
	printf("====================================================\n\n");
	//input sobrenome
	printf("Digite o sobrenome a ser cadastrada: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a"); //"a" atualiza os dados sem criar novo arquivo
	fprintf(file,sobrenome); // salvar nome dentro do arquivo
	fprintf(file,",");
	fclose(file);
	printf("====================================================\n\n");
	//input cargo
	printf("Digite o cargo a ser cadastrada: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); //"a" atualiza os dados sem criar novo arquivo
	fprintf(file,cargo); // salvar nome dentro do arquivo
	fclose(file);
	printf("====================================================\n\n");
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //le o arquivo pelo CPF
	
	if (file ==NULL)
	{
		printf("n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //La�o para rodar at� condi��o de falso
	{
		printf("Essas s�o as informa��es do usu�rio: \n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //atualizar o arquivo pelo CPF

	if (file == NULL)
	{
		
		fclose(file);
		printf("n�o localizado!\n");
		system("pause");
	}
	
	fclose(file);
	printf("Foi deletado com sucesso\n");
	remove(cpf); //remover cpf do cliente
}

int main()
{
	int opcao=0;
	int x =1;
	
	for (x=1;x=1;)
	{
	
		system("cls"); //Limpar tela dos itens j� escritos
		
		
			
		setlocale (LC_ALL,"Portuguese"); //Definir o idioma
		
		printf("###Cart�rio###\n\n");
		printf("Escolher op��o desejada: \n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar os nomes\n");
		printf("Op��o: \n");
		scanf("%d", &opcao); // atribuir novo valor ao int opcao
		
		switch(opcao){
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default: //vai pra sa�da padr�o se tem erro digitacao
			printf("Digitou errado\n");
			system("pause");
			break;
		}
	}
	printf("\nEsse software � de livre uso pessoal\n");
}



