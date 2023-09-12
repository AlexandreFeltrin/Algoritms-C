#include <stdio.h>

int main(){
    int t,s,m,h;
    int resto;
    printf("#################################################\n");
    printf("Digite o tempo em segundos\n");
    scanf("%d",&t);
    if (t>59 &&t<3600)
    {
        m=t/60;
        s=t%60;
    }else if (t>3599)
    {
        h=t/3600;
        m=(t%3600)/60;
        s=((t%3600)/60)%60;
    }else(t=s);
    printf("Horas:%d\nMinutos:%d\nSegundos:%d",h,m,s);
    return 0;
}