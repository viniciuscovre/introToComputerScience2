/*Implementar em C os métodos de ordenação SelectSort, InsertSort e ShellSort. Testá-los 
com diferentes conjuntos de dados de entrada. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int tam = 5;
int vet[tam];

int ler();
int escolha();
int VetOrdenado();
void SelectSort (int vet[]);
void InsertSort (int vet[]);
void ShellSort (int vet[]);

int main()
{   ler();
    escolha();
    VetOrdenado();
    system("pause");
    return 0;
}

int ler()
{   printf("ORDENACAO DE VETORES");
    printf("\n\nPreencha o vetor:\n");
    for (int i=0; i<tam; i++)
    {   printf("Posicao %d: ", i+1);
        scanf("%d", &vet[i]);
        fflush(stdin);
    }
    system("cls");
}

int escolha()
{   int resp;
    printf("ORDENACAO DE VETORES");
    printf("\n\nVetor:\n\n");
    for (int i=0; i<tam; i++)
       printf("  %d  ", vet[i]);
    printf("\n\nEscolha um tipo de ordenacao:");
    printf("\n\n 1.SelectSort\n 2.InsertSort\n 3.ShellSort\n\n ESCOLHA: ");
    scanf("%d", &resp);
    fflush(stdin);
    while(resp <1 || resp>3)
    {      printf("\nResposta invalida! Digite novamente: ");
           scanf("%d", &resp);
           fflush(stdin);
    }
    switch (resp)
    {     case 1: SelectSort (vet); break;
          case 2: InsertSort(vet); break;
          case 3: ShellSort (vet); break;
    }
}

int VetOrdenado()
{   printf("\n\nVetor ordenado: ");
    for (int i=0; i<tam; i++)
       printf("  %d  ", vet[i]);
    printf("\n\n");
}

void SelectSort (int vet[])
{    int i, index, j, maior;
     for (i = tam-1; i>0; i--)
     {   maior = vet[0];
         index = 0;
         for (j=1; j<=i; j++)
         {   if (vet[j] > maior)
             {   maior = vet[j];
                 index = j;
             }
         }
         vet[index] = vet[i];
         vet[i] = maior;
     }
}

void InsertSort (int vet[])
{    int i,k,y;
     for (k=1; k<tam; k++)
     {   y = vet[k];
         for (i=k-1; i>=0 && y<vet[i]; i--)
             vet[i+1] = vet[i];
         vet[i+1] = y;
     }
}

void ShellSort(int vet[])
{    int i, j, aux, h=1;  
     do
     {   
         h = 3*h + 1;
         
     }while(h < tam);
  
     do
     {   h /= 3;
         for(i = h; i < tam; i++)
         {    aux = vet[i];
              j = i - h;
              while (j >= 0 && aux < vet[j]) 
              {    vet[j + h] = vet[j];
                   j -= h;
              }
              vet[j + h] = aux;
         }
         
     }while(h > 1);
}
