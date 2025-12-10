//Sum of digits in a C program allows a user to enter any number, divide that number into individual numbers, and sum those individual numbers.

#include <stdio.h>

int  main(){
     int x,sum=0;
     printf("Please Enter an Integer  number: ");
     scanf("%i",&x);

     while(x!=0){
        sum+=x%10;
        x/=10;
     }

     printf("Sum : %i",sum);
     return 0;
}
