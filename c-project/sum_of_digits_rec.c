//Sum of digits in a C program allows a user to enter any number, divide that number into individual numbers, and sum those individual numbers.

#include <stdio.h>

int sum_digits(int s,int x){
     if(x==0)
         return 0;
     else
         return s=sum_digits(s+x%10,x/10);
}

int  main(){
     int x,s=0;
     printf("Please Enter an Integer  number: ");
     scanf("%i",&x);

     printf("Sum : %i",sum_digits(s,x));
     return 0;
}
