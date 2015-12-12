//1. Faça um programa recursivo que resolva o problema das Torres de Hanói.
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int ler();
void hanoi(int n, char a, char b, char c);
int main()
{   printf("TORRES DE HANOI");
    int n = ler();
    printf("\n\n");
    hanoi (n, 'A', 'B', 'C');
    getch();
}   

int ler()
{   int n;
    printf("\n\nDigite o numero de discos: ");
    scanf("%d", &n);
    fflush(stdin);
    return n;
}

void hanoi(int n, char a, char b, char c)
{    if (n == 1)
        printf("Mover o disco %d de %c para %c\n", n, a, b);
        else
        {
            hanoi(n - 1, a, c, b);
            printf("Mover o disco %d de %c para %c\n", n, a, b);
            hanoi(n - 1, c, b, a);
  		}        
}
