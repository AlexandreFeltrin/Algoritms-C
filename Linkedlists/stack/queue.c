#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int n;
    struct no *prox;
}No;



typedef struct Fila{
    No* base;
    No* topo; 
}Fila;

Fila* criaFila(){
    Fila* fila=(Fila*)malloc(sizeof(Fila));
    fila->base=NULL;
    fila->topo=NULL;
    return fila;
}

int vazia(Fila* fila){
    if(fila->base==NULL){
        return 1;
    }else{
        return 0;
    };
}

No* NovoNo(){
    No *novo;
    novo=(No*)malloc(sizeof(No));
    printf("Digite o número que você deseja inserir"\n);
    scanf("%d",&novo->n);
    novo->prox=NULL;
}

void insereFila(Fila*f, No* no){
    if (vazia(f))
    {
        f->base=no;
        f->topo=no;
    }else{
        f->topo->prox=no;
        f->topo=no;
    }
    
}

int menu(){
    int opc;
    printf("1.Listar o números de aviões aguardando na fila de decolagem\n");
    printf("2.Autorizar a decolagem do primeiro avião da fila\n");
    printf("3.Adicionar um avião a lista de espera\n");
    printf("4.Listar todos os aviões na fila de espera\n ");
    printf("5.Listar as características do primeiro avião da fila\n");
    scanf("%d",&opc);
    return(opc);
}