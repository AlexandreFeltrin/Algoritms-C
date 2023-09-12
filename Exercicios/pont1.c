#include <stdio.h>

void main(){
    int a=2;
    int b=8;
    int *ptr1=&a;
    int *ptr2=&b;

    printf("A: %d\n",a);
    printf("B: %d\n",b);

    printf("Após mudar:\n");

    trocaValor(ptr1,ptr2);

    printf("A: %d\n",*ptr1);
    printf("B: %d\n",*ptr2);

}

void trocaValor(int *ptr1, int *ptr2){
    int aux;

     aux=*ptr2;
    *ptr2=*ptr1;
    *ptr1=aux;

}