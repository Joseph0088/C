#include <stdio.h>
#define foo 3 // deifne is a maro
#define ADD(x,y) (x+y)
#define MUL(x,y) ((x)*(y))
//macros  with multiple lines 
//best  PRACTICE ADD BRAKETS TO THE AGUMENTS
#define sum_range(start,end) {         \
         float sum=0;                  \
         for(int i=(start); i<= (end);i++) \
               sum+=i;                  \
         printf("\nsum: %.2f",sum);       \
}

int main(){
      int a=ADD(2,4), b=MUL(2,4);
      printf("\n ADD : %i",a);
      printf("\n MUltiply : %i",b);
      sum_range(2,4);

}
