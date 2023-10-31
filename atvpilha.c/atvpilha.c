#include <stdlib.h>
#include <stdio.h>
typedef struct No{
    int num;
    struct No* prox;
}No;

typedef struct{
    No* topo;
}Pilha;

int pilhavazia(Pilha* pilha){
    return(pilha->topo==NULL);
}

void empilhar ( Pilha* pilha, int n){
    No* no=(No*) malloc(sizeof(No));
    no->prox=NULL;
    no->num=n;
    if(pilhavazia(pilha)){
        pilha->topo=no;
    }else{
        pilha->topo->prox=no;
        pilha->topo=no;
    }
}
void desempilhar(Pilha* pilha) {
    if (pilha->topo== NULL) {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }else{
        pilha->topo=NULL;
    }
}
void mostrarPilha(Pilha* pilha){
    if(pilha == NULL){
            printf("Pilha vazia.\n");
            return;
    }
    No* no = pilha->topo;
    while(no != NULL){
        printf("%d ",no->num);
        no = no->prox;
    }
}
int main(){
    Pilha* p;
    int num;
    int opc;

    while(opc!=4){
        printf("\nMenu:\n");
        printf("1. Adicionar um elemento a pilha\n");
        printf("2. Remover elemento da pilha\n");
        printf("3. Mostrar todos os elementos da pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Digite o numéro que você deseja adicionar:");
            scanf("%i",&num);
            printf("\n");
            empilhar(p,num);
            break;
        case 2:
            desempilhar(p);
            break;
        case 3:
            mostrarPilha(p);
            break;
        default:
            break;
        }
        free(p);
    }
    free(p);
    return(0);
}