#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct regFunc
{   int nm;
    char nome[50];
    int idade;
    struct regFunc *prox;
}*listaRFunc;

void leitura();
void imprimir();

int main()
{   leitura();
    imprimir();
    free(listaRFunc);
    getch();
}
void leitura()
{   char resp;
    printf("REGISTRO DOS FUNCIONARIOS\n\n");
    
    for ( ; ; )
    {   struct regFunc *p;
        p = (struct regFunc*)malloc(sizeof(struct regFunc));
        
        printf("  Numero da matricula: ");
        scanf("%d", &(p->nm));
        fflush(stdin);
        while (p->nm <1 || p->nm >50)
        {   printf("  Numero invalido! Digite novamente: ");
            scanf("%d", &(p->nm));
            fflush(stdin);
        }
    
        printf("  Nome: ");
        gets(p->nome);
        fflush(stdin);
    
        printf("  Idade: ");
        scanf("%d", &(p->idade));
        fflush(stdin);

        printf("  Deseja cadastrar mais algum funcionario? ");
        scanf("%c", &resp);
        resp = tolower(resp);
        fflush(stdin);
        
        struct regFunc *auxAnt, *auxProx;
        auxProx = listaRFunc;
        if (listaRFunc == NULL) //se a lista esta vazia
        {  
           listaRFunc = p; 
           listaRFunc->prox = NULL;
        }
        
        else // a lista nao esta vazia
        {
    
             if (p->nm < auxProx->nm)//insere no primeiro registro
             {
                 p->prox = auxProx; 
                 listaRFunc = p;
             }
             else
             {
                 while(auxProx->nm < p->nm) 
                 {
                     auxAnt = auxProx;
                     auxProx = auxProx->prox;

                     if (auxProx == NULL)
                        break;
                 } 
                 p->prox = auxProx;
                 auxAnt->prox = p;
             }
        }//fecha o else da lista nao vazia
        
        if (resp == 'n')
           break;
        printf("\n");
             
    }//fecha o for
    system("cls");
}//fecha leitura()

void imprimir()
{    struct regFunc *i;
     i = listaRFunc;
     printf("FUNCIONARIOS CADASTRADOS\n\n");
     while (i)
     {   printf("  Numero da matricula: %d\n", i->nm);
         printf("  Nome do funcionario: %s\n", i->nome);
         printf("  Idade: %d\n\n", i->idade);
         i=i->prox;
     }//fecha o while
          
}//fecha o ordenar()
