#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct regFunc 
{
  int num_mat;
  char nome[50];
  int idade;
  struct regFunc* prox;  
};

struct regFunc* listaRFunc;

void  leFuncionario()
{
    struct regFunc* func;
    int numero = 0;
    func = (struct regFunc*) malloc(sizeof(struct regFunc));
   
    while (numero < 1 || numero > 50)
    {
      printf("\nDigite o numero da matricula: ");
      scanf("%d",&numero);
    }
    func->num_mat = numero;
    printf("\nDigite o nome do funcionario: ");
    fflush(stdin);
    gets(func->nome);
    fflush(stdin);
    printf("\nDigite a idade do funcionario: ");
    scanf("%d",&(func->idade));
    
    struct regFunc* auxAnt;
    struct regFunc* auxProx;
    auxProx = listaRFunc;
    if (listaRFunc == NULL) //se a lista esta vazia
    {
     listaRFunc = func; 
     listaRFunc->prox = NULL;
    }
    else // a lista nao esta vazia
    {
    
    if (func->num_mat < auxProx->num_mat)//insere no primeiro registro
    {
       func->prox = auxProx; 
       listaRFunc = func;
    }
    else
    {
      while(auxProx->num_mat < func->num_mat) 
        {
          auxAnt = auxProx;
          auxProx = auxProx->prox;

          if (auxProx == NULL)
            break;
        } 
      func->prox = auxProx;
      auxAnt->prox = func;
    }
  }
}

void percorreLista()
{
  struct regFunc* aux;
  aux = listaRFunc;
  printf("\n\n\n LISTA: \n");
  while(aux) 
    {
      printf("\nNumero Matricula: %d", aux->num_mat);
      printf("\nNome: %s",aux->nome);
      printf("\nIdade: %d",aux->idade);
      aux = aux -> prox;
    } 
}

int main (void)
{
  for(int i = 0; i<3;i++)
  {
    leFuncionario();
  }
  
  percorreLista();
  free(listaRFunc);
  
  getch();
}
