#include <stdio.h>


main() {
    int a, b, acumulador, i;

    a = 0;
    b = 1;

    printf("\nSérie de Fibonacci:\n");
    printf("%d\n", b);

    for(i = 0; acumulador<99 ; i++) {

        acumulador = a + b;
        a = b;
        b = acumulador;

        printf("%d\n", acumulador);
    }
}