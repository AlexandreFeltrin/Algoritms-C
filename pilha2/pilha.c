#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int num;
    struct No* prox;
}No;

typedef struct pilha{
    No* topo;
    No*base;
}pilha;

struct pilha* criarPilha(){
    pilha* Pilha=(pilha*)malloc(sizeof(pilha));
    Pilha->base=NULL;
    Pilha->topo=NULL;
    return Pilha;
}

int vazia(pilha* Pilha){
    return(Pilha->base==NULL);
}


void empilhar(pilha* Pilha, int n){
    No* novoNo= (struct No*)malloc(sizeof(struct No));
    novoNo->num = n;
    novoNo->prox = NULL;

    if (vazia(Pilha)) {
        Pilha->base = Pilha->topo = novoNo;
    } else {
        Pilha->topo->prox = novoNo;
        Pilha->topo = novoNo;
    }
};
void mostrarPilha(pilha* p){
    if(p == NULL){
            printf("Pilha vazia.\n");
            return;
    }
    No* no = p->base;
     
    printf("Números da pilha\n");
    while(no != NULL){
        printf("---------\n");
        printf("%d \n",no->num);
        no = no->prox;
        printf("---------\n");
    }
}

void desempilhar(struct pilha* Pilha) {
    if (vazia(Pilha)) {
        printf("Não há números na Lista.\n");
    } else {
        struct No* noRemov = Pilha->topo;
        Pilha->topo = noRemov->prox;
        printf("Número %d  removido.\n", noRemov->num);
        free(noRemov);
    }
}

void excluiPilha(pilha* Pilha){
    free(Pilha);
}

int main(){
    pilha* p=criarPilha();
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
    }
    free(p);
    return(0);
}