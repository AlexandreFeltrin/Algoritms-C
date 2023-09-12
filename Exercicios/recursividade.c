#include <stdio.h>
int somar(int a, int b);
int main(){
    int a,b;
    a=0;
    b=4;
    printf("%d\n", somar(a,b));
}

int somar(int a, int b){
    if(a==b){
        return 0;
    }else if(b>a) {
        return b+somar(a,(b-1));
    }else{
        return a+somar((a-1),b);
    }
}