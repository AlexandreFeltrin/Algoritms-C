#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void imprimir(int *n, int t);

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

  free(numbers);

  return 0;
}

void imprimir(int *n, int t) {
  for (int z = 0; z < t; z++) {
    printf("%d\n", n[z]);
  }
}
