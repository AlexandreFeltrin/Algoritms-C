#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int  main(){
    int *numbers;
    int t=0;
   
    printf("Digite a quantidade de números que você deseja registrar\n");
    scanf("%d",&t);
    numbers=(int*)malloc(t*sizeof(int));

    for(int i=0;i<t;i++){
        printf("Digite o número que você deseja inserir");
        scanf("%d",&numbers[i]);
    }

    for(int z;z<t;z++){
        printf("%i",numbers[z]);
        printf("\n");
    }
    free(numbers);
   return 0; 
}


