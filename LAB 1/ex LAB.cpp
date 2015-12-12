#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct regFunc
{   unsigned int nm;
    char nome[100];
    int idade;
    struct regFunc *prox;
}*listaRFunc, *primeiro, *a, *b;

void itemBeC();
void itemD();

int main()
{   char resp;
    listaRFunc = (struct regFunc*) malloc (sizeof(struct regFunc));
    primeiro = listaRFunc;
    b = listaRFunc;
    printf("CADASTRAR FUNCIONARIOS:\n\n");
    for ( ; ; )
    {   itemBeC();
        printf("  Deseja cadastrar mais funcionarios? ");
        scanf("%c", &resp);
        fflush(stdin);
        if (resp != 'n')
        {  //INSERE NO FINAL
           /*
           printf("\n");
           listaRFunc->prox = (struct regFunc*) malloc (sizeof (struct regFunc));
           listaRFunc = listaRFunc->prox;*/
           
           //INSERE NO INICIO
           
           printf("\n");
           a = (struct regFunc*) malloc (sizeof (struct regFunc));
           a->prox = listaRFunc;
           listaRFunc = a;
           primeiro = a;
        }

        else
        {   //listaRFunc->prox = NULL; //INSERE NO FINAL
            a->prox = NULL; //INSERE NO INICIO
            break;
        }
    }
    printf("\n\nFUNCIONARIOS CADASTRADOS!");
    getch();
    system("cls");
    itemD();
    getch();
}

void itemBeC() //Cadastrar funcionarios... e ja ordenar
{   printf("  Numero da Matricula: ");
    scanf("%d", &(listaRFunc->nm));
    fflush(stdin);
    while (listaRFunc->nm < 1 || listaRFunc->nm > 50)
    {   printf("  Numero Invalido! Digite um numero de matricula no intervalo 1 - 50: ");
        scanf("%d", &(listaRFunc->nm));
        fflush(stdin);
    }
          
    printf("  Nome do funcionario: ");
    gets(listaRFunc->nome);
    fflush(stdin);
          
    printf("  Idade: ");
    scanf("%d", &(listaRFunc->idade));
    fflush(stdin);
}

void itemD() //Visualizar funcionarios cadastrados
{    struct regFunc *aux;
     printf("FUNCIONARIOS CADASTRADOS:\n\n");
     for (aux = primeiro; aux != NULL; aux = aux->prox)
     {   printf("  Numero da matricula: %d\n", aux->nm);
         printf("  Nome do funcionario: %s\n", aux->nome);
         printf("  Idade: %d\n\n", aux->idade);
     }
     //para nao gastar memoria a toa
     free(listaRFunc);
     free(primeiro);
}
