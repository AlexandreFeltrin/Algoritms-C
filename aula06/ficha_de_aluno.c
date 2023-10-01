#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float notaprova1;
    float notaprova2;
    float notaprova3;
}Aluno;

int main(){
    Aluno a;
    a.notaprova1=9.7;
    a.notaprova2=8.0;
    a.notaprova3=9.0;

    printf ("%f", a.notaprova1);

    return 0;
}
