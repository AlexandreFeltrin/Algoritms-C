#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *prox;
} no;

void insert(no **lista, int num) {
    no *NovoNo = (no *)malloc(sizeof(no));
    NovoNo->num = num;
    NovoNo->prox = *lista;
    *lista = NovoNo;
}


void imprimir(no *lista) {
    no *atual = lista;
    while (atual != NULL) {
        printf("%d \n", atual->num);
        atual = atual->prox;
    };
}


void ordenar(no *lista) {
    int sw, temp;
    no *ptr1;
    no *lptr = NULL;

    if (lista == NULL)
        return;

    do {
        sw = 0;
        ptr1 = lista;

        while (ptr1->prox != lptr) {
            if (ptr1->num > ptr1->prox->num) {
                temp = ptr1->num;
                ptr1->num = ptr1->prox->num;
                ptr1->prox->num = temp;
                sw = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (sw);
}

int main() {
    no *lista = NULL;
    int n, num;

    printf("Quantos elementos deseja inserir na lista? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Insira o elemento %d: ", i + 1);
        scanf("%d", &num);
        insert(&lista, num);
    }

    printf("Lista original: \n");
    imprimir(lista);

    ordenar(lista);

    printf("Lista ordenada: \n");
    imprimir(lista);

    return 0;
}
