//This is a C Program which calculates the number of integers divisible by 5 in the given range.
#include <stdio.h>
#define n 4
int  main(){
     int c=0,x;
     printf("Enter %i numbers",n);

     for(int i=n;i>0;i--){
       printf("\n%i .Enter : ",(-1)*(i-n-1)); scanf("%i",&x);
       if(x%5==0)
          c++;
     }
     printf("\nThere are %i divisers",c);
     return 0;
}
