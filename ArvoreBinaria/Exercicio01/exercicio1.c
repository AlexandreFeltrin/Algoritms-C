#include <stdio.h>
#include <stdlib.h>


struct No {
    int num;
    struct No* esquerda;
    struct No* direita;
};

struct No* novoNo(int num) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->num = num;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

struct No* inserir(struct No* raiz, int num) {
    if (raiz == NULL) {
        return novoNo(num);
    }

    if (num < raiz->num) {
        raiz->esquerda = inserir(raiz->esquerda, num);
    } else if (num > raiz->num) {
        raiz->direita = inserir(raiz->direita, num);
    }

    return raiz;
}


struct No* procurarNo(struct No* raiz, int num) {
    if (raiz == NULL || raiz->num == num) {
        return raiz;
    }

    if (num < raiz->num) {
        return procurarNo(raiz->esquerda, num);
    }

    return procurarNo(raiz->direita, num);
}

struct No* procurarNoMin(struct No* no) {
    struct No* atual = no;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}


struct No* removerNo(struct No* raiz, int num) {
    if (raiz == NULL) {
        return raiz;
    }

    if (num < raiz->num) {
        raiz->esquerda = removerNo(raiz->esquerda, num);
    } else if (num > raiz->num) {
        raiz->direita = removerNo(raiz->direita, num);
    } else {
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        struct No* temp = procurarNoMin(raiz->direita);
        raiz->num = temp->num;
        raiz->direita = removerNo(raiz->direita, temp->num);
    }

    return raiz;
}


void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
     emOrdem(raiz->esquerda);
        printf("%d ", raiz->num);
     emOrdem(raiz->direita);
    }
}


void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->num);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}


void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->num);
    }
}


void liberar(struct No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

int main() {
    struct No* raiz = NULL;
    int choice, num;
    struct No* found;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir Noh\n");
        printf("2. Remover Noh\n");
        printf("3. Localizar Noh\n");
        printf("4. Listar Nohs em Ordem\n");
        printf("5. Listar Nohs pré Ordem\n");
        printf("6. Listar Nohs pós Ordem\n");
        printf("7. Sair do Programa\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &num);
                raiz = inserir(raiz, num);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &num);
                raiz = removerNo(raiz, num);
                break;
            case 3:
                printf("Digite o valor a ser localizado: ");
                scanf("%d", &num);
                found = procurarNo(raiz, num);
                if (found != NULL) {
                    printf("%d encontrado na árvore.\n", num);
                } else {
                    printf("%d não encontrado na árvore.\n", num);
                }
                break;
            case 4:
                printf("Nós em Ordem: ");
             emOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Nós em pré Ordem: ");
                preOrdem(raiz);
                printf("\n");
                break;
            case 6:
                printf("Nós em pós Ordem: ");
                posOrdem(raiz);
                printf("\n");
                break;
            case 7:
                liberar(raiz);
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
}
