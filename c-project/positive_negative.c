//This is a C program to check whether a given integer is positive or negative.


#include <stdio.h>

int  main(){
     float x=0;
     printf("Please Enter a number: ");
     scanf("%f",&x);

     if(x>=0)
       printf("\n%2.f is Positive",x);
     else
       printf("\n%.2f is Negative ",x);
     return 0;
}
