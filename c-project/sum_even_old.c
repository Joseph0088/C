//The program takes the number N and finds the sum of odd and even numbers from 1 to N.
#include <stdio.h>

int  main(){
     int n=0, value=0, sum_even=0,sum_old=0;
     printf("Please Enter an Integer  number of values you want to enter: ");
     scanf("%i",&n);

     for(int i=0;i<n;i++)
     {
      printf("\n%i. Enter: ",i+1);
      scanf("%i",&value);

     if(value%2==0)
       sum_even+=value;
     else
       sum_old+=value;
     }
     printf("\nsum of Even numbers entered : %i\nsum of Old numbers entere: %i",sum_even,sum_old);
     
     return 0;
}
