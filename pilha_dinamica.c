#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>

typedef struct NO{
    int dado;
    struct NO* prox;
}NO;

typedef struct PILHA{
    NO* topo;
}PILHA;

PILHA p;

void push(int dado);
int pop();
void imprimir();
void erro();
void menu();
void limparBuffer();

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    p.topo = NULL;
    int op, dado;

    do
    {   
        menu();
        printf("\nQual opcão ? ");
        scanf("%d", &op);
        limparBuffer();
        switch(op){
        case 0:
            break;
        case 1:
            printf("\nQual valor ? ");
            scanf("%d", &dado);
            limparBuffer();
            push(dado);
            break;
        case 2:
            dado = pop();
            if(dado == -1){
                printf("\nPilha vázia\n");
            }else{
                printf("\nValor removido %d\
                        \nDigite qualquer letra e pressiona 'ENTER'", dado);
                getchar();
            }
            break;
        case 3:
            imprimir();
            break;
        default:
            printf("\nOpcão inválida.\
                    \nDigite qualquer letra e pressione 'ENTER'");
            getchar();
            break;
        }
    } while (op != 0);
}

void push(int dado){
    NO* ptr = (NO*)malloc(sizeof(NO));
    if(ptr == NULL){
        erro();
        return;
    }
    if(p.topo == NULL){
        ptr->prox = p.topo;
        p.topo = ptr;
    }else{
        ptr->prox = p.topo;
        p.topo = ptr;
    }
    ptr->dado = dado;
}

int pop(){
    if(p.topo == NULL){
        return -1;
    }else{
        int dado;
        NO* ptr = p.topo;
        p.topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimir(){
    NO* current = p.topo;
    printf("Topo -> ");
    while(current != NULL){
        printf("%d ", current->dado);
        current = current->prox;
    }
    printf(" <- Início");
    printf("\n pressione 'ENTER'");
    getchar();
    
}

void erro(){
    printf("\tErro, ao alocar memória");
}

void menu(){
    printf("\n1 - Para empilhar\
            \n2 - Desempihar\
            \n3 - Imprimir\
            \n0 - Sair.");
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n') {
        // Descarta o caractere
    }
}