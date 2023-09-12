#include <stdio.h>

int main(){
    int notas[5],i;
    float soma;

    for(i=0;i<5;i++){
        printf("\nDigite o nota do aluno %d\n",i);
        scanf("%d",&notas[i]);
        soma+=notas[i];
    }
    printf("\nMedia das notas é: %f \n",soma/5);
}