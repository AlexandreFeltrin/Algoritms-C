#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definindo a estrutura da fila
typedef struct Queue {
    Node* front; // Início da fila
    Node* rear;  // Fim da fila
} Queue;

// Função para criar uma nova fila vazia
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Função para enfileirar um elemento na fila
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para desenfileirar um elemento da fila
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return -1; // Valor inválido para indicar erro
    }
    Node* frontNode = queue->front;
    int data = frontNode->data;
    queue->front = frontNode->next;
    free(frontNode);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

// Função para obter o elemento na frente da fila sem desenfileirar
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return -1; // Valor inválido para indicar erro
    }
    return queue->front->data;
}

// Função para imprimir os elementos da fila
void printQueue(Queue* queue) {
    Node* current = queue->front;
    printf("Fila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printQueue(queue);

    printf("Elemento na frente da fila: %d\n", peek(queue));

    printf("Desenfileirando: %d\n", dequeue(queue));
    printf("Desenfileirando: %d\n", dequeue(queue));

    printQueue(queue);

    return 0;
}
