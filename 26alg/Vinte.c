#include <stdio.h>

void main(){
    float amount,h,valueHour ,hn,hext1, hext2;

    printf("Digite quantas horas você trabalhou:\n");
    scanf("%f",&h);
    printf("Digite qual o preço por hora trabalhada:\n");
    scanf("%f",&valueHour);

    if(h<=40){
        amount=h*valueHour;
        printf("Seu salario é %f \n",amount);
    }else if(h>40 && h<=60){
        hn=40*valueHour;
        hext1=(h%40)*1,5;
        amount=hn+hext1;
        printf("Seu salario é %f \n",amount);
    }else if(h>60){
        hn=40*valueHour;
        hext2=(h%40)*2;
        amount=hn+hext2;
        printf("Seu salario é %f \n",amount);
    }


}