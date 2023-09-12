#include <stdio.h>

void main(){
    int x,y,z;
    printf("Digite tres valores: \n");
    scanf("%d%d%d", &x, &y, &z);

    if(x>0 && y>0 && z>0){
        printf("Estes valores podem formar um triangulo\n");
        if(x == y && x == z)
            printf("Equilatero\n");
        else
            if(x == y || x == z || y == z)
                printf("Isosceles\n");
            else
                printf("Escaleno\n");
    } else{
        printf("Os 3 lados NAO formam um trinagulo!\n");};
}