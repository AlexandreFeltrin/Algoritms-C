#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    No* esquerda;
    No* direita
}No;



No* inserirNo(No* raiz, int num){
    if(raiz==NULL){
        No *aux=malloc(sizeof(No));
        aux->data=num;
        aux->direita=NULL;
        aux->esquerda=NULL;
    }else{
        if(num<raiz-data){
            aux
        }
    }
}