#include <stdio.h>

main(){
    int n=1000;
      while(n <= 9999)
      {
                if(n == (((n/100)+(n%100))*((n/100)+(n%100))))
                       printf("%d\n",n);
                n=n+1;
      }
}