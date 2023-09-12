#include <stdio.h>
#include <stdlib.h>

void main(){

    int i, soma, n;


    while(n < 101){
        for(i = 1; i <= n/2; i++){
            if(n % i == 0){
                soma += i;
                if(soma == n){
                printf("O número %d é perfeito",n);
                }
            }
        }
        n++;
    }
}