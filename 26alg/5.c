#include <stdio.h>

void main(){
    float n1,n2,n3,m;
    printf("Digite 3 números não inteiros \n");
    scanf("%f",&n1);
    scanf("%f",&n2);
    scanf("%f",&n3);
    if(n1>n2 && n2>n3){
        printf("Maior é %f\n",n1);
        printf("Menor é %f\n",n3);
    }else if (n1>n3 && n3>n2){
        printf("Maior é %f\n",n1);
        printf("Menor é %f\n",n2);
    }else if (n2>n1 && n1>n3){
        printf("Maior é %f\n",n2);
        printf("Menor é %f\n",n3);
    }else if (n2>n3 && n3>n1){
        printf("Maior é %f\n",n2);
        printf("Menor é %f\n",n1);
    }else if (n3>n1 && n1>n2){
        printf("Maior é %f\n",n3);
        printf("Menor é %f\n",n2);
    }else if (n3>n2 && n2>n1){
        printf("Maior é %f\n",n3);
        printf("Menor é %f\n",n1);
    }else(
        printf("Alguns números são iguais ou caracter invalido")
    );
    

    m=(n1+n2+n3)/3;
    printf("A média é %f",m);
}