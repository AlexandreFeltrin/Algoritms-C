#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sort, num, t = 0;
    srand(time(NULL));
    sort= rand()%501;


    do{
        printf("Informe o numero magico !\n");
        scanf("%d", &num);

        if(sort < num)
            printf("O numero sorteado é menor!\n");

        if(sort > num)
            printf("O numero sorteado é maior!\n");

        t++;

    }while(num!=sort);

    if(t<4){
        printf("Voce é extremamente sortudo!\n");
    }else if(t<7){
        printf("Voce é sortudo!\n");
    }else if(t<11){
        printf("Você possui uma sorte mediana\n");
    }else{
        printf("Tome banho de sal grosso e tente novamente!\n");
    }
    return 0;
}
