#include <stdio.h>

int main(){
    float a,b,r;
    char op;

    printf("Digite um operador:\n+\n-\n/\n*\n");
    scanf("%c",&op);

    printf("Digite um números real:\n");
    scanf("%f",&a);
    printf("Digite um número real:\n");
    scanf("%f",&b);
    
    if (op=='+'){
        r=a+b;
        printf("A soma de %f + %f é %f",a,b,r);
    }else if (op=='-'){
        r=a-b;
        printf("A subtração de %f - %f é %f",a,b,r);
    }else if(op=='/'){
        r=a/b;
        printf("A divisão de %f / %f é %f",a,b,r);
    }else if (op=='*'){
        r=a*b;
        printf("A multiplicação de %f + %f é %f",a,b,r);
    }else{
        printf("Operação invalida\n");
    }
    
    
    return 0;
}