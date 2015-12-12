/*Faça um programa para criar um arquivo chamado CADASTRO.DAT, no qual cada registro será composto pelos seguintes campos: 
numero, nome, salario, desconto (sendo este um número decimal representando o percentual; por exemplo, 0,275 para um 
desconto de 27,5%). Gravar ao menos um registro no arquivo. Depois, ler os registros gravados, calcular o salário líquido 
e apresentar na tela o valor calculado.*/
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

FILE *fp;
struct registro
{   int num;
    char nome[50];
    float salario;
    float desconto;
    float novo_salario;
    struct registro *prox;
}*gravar, *p;

void escrever();
void imprimir();

int main()
{    char resp;
     gravar = (struct registro*) malloc (sizeof(struct registro));
     p = gravar;
     
     while (resp != 'n')
     {   
         escrever();
         printf("Deseja registrar mais um? ");
         scanf("%c", &resp);
         resp = tolower(resp);
         
         if (resp != 'n')
         {  gravar->prox = (struct registro*) malloc (sizeof(struct registro));
            gravar = gravar->prox;
            printf("\n");
         }
     }
     
     imprimir();
     getch();
}

void escrever()
{    fp = fopen("CADASTRO.DAT", "a");
     if (fp == NULL)
     {   printf("Erro na abertura do arquivo! Encerrando o programa...");
         getch();
         exit(0);
     }
     printf("NUMERO: ");
     scanf("%d", &(gravar->num));
     fflush(stdin);
     fprintf(fp, "\nNumero: %d", gravar->num);
     
     printf("NOME: ");
     gets(gravar->nome);
     fflush(stdin);
     fprintf(fp, "\nNome: %s", gravar->nome);
     
     printf("SALARIO: ");
     scanf("%f", &(gravar->salario));
     fflush(stdin);
     fprintf(fp, "\nSalario: %.2f", gravar->salario);
     
     printf("DESCONTO: ");
     scanf("%f", &(gravar->desconto));
     fflush(stdin);
     fprintf(fp, "\nDesconto: %1.3f", gravar->desconto);
     
     gravar->novo_salario = gravar->salario - ((gravar->salario)*(gravar->desconto));
     fprintf(fp, "\nNovo Salario: %.2f", gravar->novo_salario);
     
     fprintf(fp, "\n\n");
     fclose(fp);
}

void imprimir()
{    char ch;
     system("cls");
     fp = fopen("CADASTRO.DAT", "r");
     if (fp == NULL)
     {   printf("Erro na abertura do arquivo! Encerrando o programa...");
         getch();
         exit(0);
     }
     
     ch = getc(fp);
     while (ch != EOF)
     {   putchar(ch);
         ch = getc(fp);
     }
     
     fclose(fp);
     free(p);
     free(gravar);
} 
     
     
