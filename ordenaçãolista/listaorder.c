
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void imprimir(int *n, int t);
void ordenar(int *n,int l);

int main() {
  int *numbers;
  int t;
  int len;

  printf("Digite a quantidade de números que você deseja registrar\n");
  scanf("%d", &t);
  numbers = (int *) malloc(t * sizeof(int));

  for (int i = 0; i < t; i++) {
    printf("Digite o número que você deseja inserir\n");
    scanf("%d", &numbers[i]);
  }

  len = sizeof(numbers) / sizeof(int);

  imprimir(numbers, len);
  ordenar(numbers,len);
  imprimir(numbers,len);
  free(numbers);

  return 0;
}
void ordenar (int *n, int l) {
    int k, j, aux;

    for (k = 1; k < l; k++) {
        for (j = 0; j < l - 1; j++) {
            if (n[j] > n[j + 1]) {
                aux          = n[j];
                n[j]     = n[j + 1];
                n[j + 1] = aux;
            }
        }
    }
}
void imprimir(int *n, int t) {
  for (int z = 0; z < t; z++) {
    printf("%d\n", n[z]);
  }
}