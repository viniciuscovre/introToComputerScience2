/*2. Faça um programa que leia um conjunto de números inteiros e o ordena utilizando o
método BubbleSort ou QuickSort, dependendo da escolha do usuário. Testá-lo com 
diferentes conjuntos de dados de entrada, comparando-os.*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int tam = 100;

int lerN();
int escolha();
int BubbleSort(int vet[], int n);
int QuickSort(int vet[], int inicio, int fim);

int main()
{   int n = lerN();
    int vet[n], opt; // opt é a opcao do usuário (entre BubbleSort e QuickSort)
    printf("\nVETOR:\n\n");    
    srand(time(NULL));
    for (int i=0; i<n; i++)
    {   vet[i] = rand () % tam+1;
        printf("  %d  ", vet[i]);
    }
    opt = escolha();
    
    if (opt == 1)
       BubbleSort(vet, n);
    
    else
    {
        QuickSort(vet, 0, n);
        printf("\n\nVETOR ORDENADO:\n\n");
        for (int j=0; j<n; j++)
        printf("  %d  ", vet[j]);
    }
        
    getch();
}

//Ler o tamanho do vetor
int lerN()
{   int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    fflush(stdin);
    return n;
}

//Escolher entre BubbleSort ou QuickSort
int escolha()
{   int opt;
    printf("\n\n1. BubbleSort \n2. QuickSort\n\n ESCOLHA: ");
    scanf("%d", &opt);
    fflush(stdin);
    
    while (opt <=0 || opt >2)
    {   printf("\nOpcao Invalida! Digite Novamente: ");
        scanf("%d", &opt);
        fflush(stdin);
    }
    
    return opt;
}

//BubbleSort
int BubbleSort(int vet[], int n)
{   int aux, j, passo, troca = 1;

    for (passo=0; passo<n-1 && troca; passo++)
    {   troca=0;
        for (j=0; j<n-passo-1; j++)
        {   if (vet[j] > vet[j+1])
            {   troca=1;
                aux = vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
            }
        }
    }
    printf("\n\nVETOR ORDENADO:\n\n");
    for (j=0; j<n; j++)
       printf("  %d  ", vet[j]);
}

//QuickSort
int QuickSort (int vet[], int inicio, int fim)
{  int pivo, aux, i, j, meio;
    
   i = inicio;
   j = fim;
    
   meio = (int) ((i + j) / 2);
   pivo = vet[meio];
    
   do{
      while (vet[i] < pivo) i++;
      while (vet[j] > pivo) j--;
       
      if(i <= j){
         aux = vet[i];
         vet[i] = vet[j];
         vet[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
    
   if(inicio < j) QuickSort(vet, inicio, j);
   if(i < fim) QuickSort(vet, i, fim);   
}
