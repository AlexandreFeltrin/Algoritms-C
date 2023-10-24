#include <stdio.h>
#include <stdlib.h>


struct No {
    int numeroAviao;
    char modelo[50];
    struct No* proximo;
};

// Definição da estrutura da fila
struct Fila {
    struct No* frente;
    struct No* tras;
};

// Função para criar uma fila vazia
struct Fila* criarFila() {
    struct Fila* fila = (struct Fila*)malloc(sizeof(struct Fila));
    fila->frente = fila->tras = NULL;
    return fila;
}

// Função para verificar se a fila está vazia
int filaVazia(struct Fila* fila) {
    return (fila->frente == NULL);
}

// Função para adicionar um avião à fila de espera
void adicionarAviao(struct Fila* fila, int numeroAviao, char modelo[]) {
    struct No* novoAviao = (struct No*)malloc(sizeof(struct No));
    novoAviao->numeroAviao = numeroAviao;
    strcpy(novoAviao->modelo, modelo);
    novoAviao->proximo = NULL;

    if (filaVazia(fila)) {
        fila->frente = fila->tras = novoAviao;
    } else {
        fila->tras->proximo = novoAviao;
        fila->tras = novoAviao;
    }
    printf("Avião %d (%s) adicionado à fila de espera.\n", numeroAviao, modelo);
}

// Função para listar o número de aviões aguardando na fila de decolagem
int contarAvioesNaFila(struct Fila* fila) {
    int contador = 0;
    struct No* atual = fila->frente;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

// Função para listar todos os aviões na fila de espera
void listarAvioesNaFila(struct Fila* fila) {
    struct No* atual = fila->frente;
    printf("Aviões na fila de espera:\n");
    while (atual != NULL) {
        printf("Avião %d (%s)\n", atual->numeroAviao, atual->modelo);
        atual = atual->proximo;
    }
}


void decolarAviao(struct Fila* fila) {
    if (filaVazia(fila)) {
        printf("Não há aviões na fila de espera.\n");
    } else {
        struct No* aviaoDecolado = fila->frente;
        fila->frente = aviaoDecolado->proximo;
        printf("Avião %d (%s) decolou.\n", aviaoDecolado->numeroAviao, aviaoDecolado->modelo);
        free(aviaoDecolado);
    }
}

// Função para listar as características do primeiro avião da fila
void listarPrimeiroAviao(struct Fila* fila) {
    if (filaVazia(fila)) {
        printf("Não há aviões na fila de espera.\n");
    } else {
        printf("Características do primeiro avião na fila de espera:\n");
        printf("Número: %d\n", fila->frente->numeroAviao);
        printf("Modelo: %s\n", fila->frente->modelo);
    }
}

int main() {
    struct Fila* filaEspera = criarFila();
    int opcao, numeroAviao;
    char modelo[50];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Listar número de aviões na fila de decolagem\n");
        printf("2. Autorizar a decolagem do primeiro avião\n");
        printf("3. Adicionar avião à fila de espera\n");
        printf("4. Listar aviões na fila de espera\n");
        printf("5. Listar características do primeiro avião na fila\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Número de aviões na fila de decolagem: %d\n", contarAvioesNaFila(filaEspera));
                break;
            case 2:
                decolarAviao(filaEspera);
                break;
            case 3:
                printf("Digite o número do avião:\n ");
                scanf("%d", &numeroAviao);
                printf("\n");
                printf("Digite o modelo do avião: \n");
                scanf("%s", modelo);
                adicionarAviao(filaEspera, numeroAviao, modelo);
                break;
            case 4:
                listarAvioesNaFila(filaEspera);
                break;
            case 5:
                listarPrimeiroAviao(filaEspera);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
