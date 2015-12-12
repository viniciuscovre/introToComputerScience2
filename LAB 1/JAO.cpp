#include <stdio.h>
#include <stdlib.h>
#define tam 255
typedef struct regFunc {
    int numero_matricula;
    char nome[tam];
    int idade;
    regFunc* prox;
};
regFunc* lista;
regFunc* lerFuncionario() {
    regFunc* funcionario = (regFunc*) malloc(sizeof(regFunc));
    funcionario->numero_matricula = 1;
    
    do{
        if (funcionario->numero_matricula < 1 || funcionario->numero_matricula > 50) {
            printf("Matricula invalida:\n");
        }
        
        printf("Digite o numero de matricula:\n");
        scanf("%d", &(funcionario->numero_matricula));
        
    } while (funcionario->numero_matricula < 1 || funcionario->numero_matricula > 50);
    
    fflush(stdin);
    printf("Digite o nome do funcionario:\n");
    gets(funcionario->nome);
    
    printf("Digite a idade:\n");
    scanf("%d", &(funcionario->idade));
    
    funcionario->prox = NULL;
    
    return funcionario;
}
void inserirFuncionario(regFunc* funcionario) {
    regFunc *aux, *ant;
    aux = lista;
    if (lista == NULL) {
        lista = funcionario;
        
    } else {
        aux = lista;
        
        while (aux->numero_matricula < funcionario->numero_matricula) {
            ant = aux;
            aux = aux->prox;
            
            if (aux == NULL) {
                break;
            }
        }
        
        ant->prox = funcionario;
        funcionario->prox = aux;
    }
}
void escreve() {
    //     printf("Matricula| Nome                     | Idade");
    regFunc *aux;
    aux = lista;
    
    do {
        printf("%d, %s, %d\n", aux->numero_matricula, aux->nome, aux->idade);
        aux = aux->prox;
    } while (aux != NULL);
}
int main() {
    regFunc *funcionario;
    int continua = 0;
    
    lista = NULL;
    do {
        funcionario = lerFuncionario();
        
        inserirFuncionario(funcionario);
        
        escreve();
        printf("Deseja inserir um funcionario (0 - Nao / 1 - Sim)");
        scanf("%d", &continua);
    } while (continua);
}