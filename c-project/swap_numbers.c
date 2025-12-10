//Swapping two numbers in C programming means swapping the values of two variables. For example, there are two variables m & n. Value of m is “2” & value of n is “3”.
#include <stdio.h>

int  main(){
     int m=0,n=0,x;
     printf("\nPlease Enter the value for m: ");
     scanf("%i",&m);
     printf("\nPlease Enter the value for n: ");
     scanf("%i",&n);

     x=m;
     m=n;
     n=x;

     printf("\nThe value of m now: %i ",m);
     printf("\nThe value of n now: %i",n);
     return 0;
}








//alternatively 
/*

#include<stdio.h>

void swap(long *ptr1, long *ptr2)

{

    // Step 4. Performing XOR operation on the values

    *ptr1 = *ptr1 ^ *ptr2;

    *ptr2 = *ptr1 ^ *ptr2;

    *ptr1 = *ptr1 ^ *ptr2;

}

void main()
{

    long m, n;

    // Step 1. Take user input

    printf("Enter the value of M (accepted decimal values): ");

    scanf("%ld", &m);

    printf("Enter the value of N (accepted decimal values): ");

    scanf("%ld", &n);

    // Step 2. Show the values before passing their addresses to the function

    printf("Before swapping : M = %5ld\tN = %5ld\n", m, n);

    // Step 3. Pass the addresses to the function

    swap(&m, &n);

    // Step 5. Print the values after the swap function has executed

    printf("After swapping : M  = %5ld\tN = %5ld\n", m, n);

}
*/
