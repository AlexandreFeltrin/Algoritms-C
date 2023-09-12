
#include <stdio.h>

int main(void) {
    int i, n, p, aux, t;
    
    p = 1;
    i = 1;
    printf("Digite n: ");
    scanf("%d", &n);
    
    aux = 0 ;
    
    while ( n > 0 ) {
    t = 2;
    i = 0;
    p++;
        while ( t< p )
        {
            if ( p % t == 0 )
            {
                p++;
                t= 2;
            }
            t++;
        }
        
        while ( n % p == 0 )
        {
            i++;
            n = n / p;
        }
        printf("Fator %d multiplicidade %d \n", p, i);
    }
    
    return 0;
}