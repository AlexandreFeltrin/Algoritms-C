#include <stdio.h>
float juros( float m, float j, float v);
int main(){
    float m;
    float j,v;
    m=4;
    v=1000;
    j=0.01;


    printf("%f",juros(m,j,v));
    return 0;

}

float juros( float m, float j, float v){
    if(m==0){
        return v;

    }else{
        v+=(v*j);
        return juros(m-1,j,v);
    }
}