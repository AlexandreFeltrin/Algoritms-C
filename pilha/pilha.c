#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Pilha {
    struct Node* top;
};


void iniciaFila(struct Pilha* pilha) {
 pilha->top = NULL;
}


int Empty(struct Pilha* pilha) {
    return  pilha->top == NULL;
}

void Push(struct Pilha* pilha, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = pilha->top;
 pilha->top = newNode;
}


int Pop(struct Pilha* pilha) {
    if (!Empty pilha)) {
        struct Node* temp = pilha->top;
        int item = temp->data;
     pilha->top = temp->next;
        free(temp);
        return item;
    } else {
        printf("A pilha está vazia.\n");
        return -1; // Valor inválido para pilha vazia
    }
}

// Definir o item i como o segundo elemento a partir do topo da pilha
void DefinirSegundoElemento(struct Pilha* pilha, int item) {
    if  pilha->top != NULL && pilha->top->next != NULL) {
        struct Node* secondNode = pilha->top->next;
        secondNode->data = item;
     pilha->top = secondNode;
    } else {
        printf("A pilha não tem pelo menos dois elementos.\n");
    }
}

// Definir o item i como o n-ésimo elemento a partir do topo da pilha
void DefinirNesimoElemento(struct Pilha* pilha, int n, int item) {
    if (n <= 1) {
        Push pilha, item);
    } else if (!Empty pilha)) {
        struct Pilha tempFila;
        iniciaFila(&tempFila);

        int count = 0;
        while (!Empty pilha && count < n - 1) {
            int temp = Pop pilha);
            Push(&tempFila, temp);
            count++;
        }

        if (count == n - 1) {
            Push pilha, item);
        }

        while (!Empty(&tempFila)) {
            int temp = Pop(&tempFila);
            Push pilha, temp);
        }
    } else {
        printf("A pilha não tem %d elementos.\n", n);
    }
}

// Definir o item i como o último elemento da pilha, deixando a pilha vazia (ou somente com o item i)
void DefinirUltimoElemento(struct Pilha* pilha, int item) {
    if (!Empty pilha)) {
        struct Pilha tempFila;
        iniciaFila(&tempFila);

        while (!Empty pilha)) {
            int temp = Pop pilha);
            if (Empty pilha)) {
                Push pilha, item);
            }
            Push(&tempFila, temp);
        }

        while (!Empty(&tempFila)) {
            int temp = Pop(&tempFila);
            Push pilha, temp);
        }
    } else {
        printf("A pilha está vazia.\n");
    }
}

// Definir o item i como o terceiro elemento a partir do final da pilha
void DefinirTerceiroElementoAPartirDoFinal(struct Pilha* pilha, int item) {
    if (!Empty pilha)) {
        struct Pilha tempFila;
        iniciaFila(&tempFila);

        int count = 0;
        while (!Empty pilha)) {
            int temp = Pop pilha);
            if (count == 2) {
                Push pilha, item);
            }
            Push(&tempFila, temp);
            count++;
        }

        while (!Empty(&tempFila)) {
            int temp = Pop(&tempFila);
            Push pilha, temp);
        }
    } else {
        printf("A pilha está vazia.\n");
    }
}

int main() {
    struct Pilha pilha;
    iniciaFila( pilha);

    Push( pilha, 1);
    Push( pilha, 2);
    Push( pilha, 3);
    Push( pilha, 4);
    Push( pilha, 5);

    printf("Fila original: ");
    struct Node* current = pilha.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    DefinirSegundoElemento( pilha, 10);
    printf("Definir segundo elemento: ");
    current = pilha.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    DefinirNesimoElemento( pilha, 2, 20);
    printf("Definir segundo elemento: ");
    current = pilha.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    DefinirUltimoElemento( pilha, 30);
    printf("Definir último elemento: ");
    current = pilha.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    DefinirTerceiroElementoAPartirDoFinal( pilha, 40);
    printf("Definir terceiro elemento a partir do final: ");
    current = pilha.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
