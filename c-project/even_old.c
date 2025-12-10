#include <stdio.h>

int  main(){
     int x=0;
     printf("Please Enter an Integer  number: ");
     scanf("%i",&x);
     
     if(x%2==0)
       printf("\n%i is even",x);
     else
       printf("\n%i is old ",x);
     return 0;
}
