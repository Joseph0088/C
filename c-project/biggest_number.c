//In C programming, the largest element of a number is the number with the highest numerical value of the three numbers.
#include <stdio.h>
#define n 3
int  main(){
     int biggest_number=0,x;
     printf("\nEnter %i numbers",n);
     for(int i=0; i<n;i++){
       printf("\n%i. Enter : ",i+1);
       scanf("%i",&x);
       if(i==0)
           biggest_number = x;
       else
         if(x>biggest_number)
              biggest_number = x;

       }
       printf("\n%i is the Biggest number entered",biggest_number);
     return 0;
}
