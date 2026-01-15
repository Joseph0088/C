#include <stdio.h>

int main(){
      int  a=8;
      size_t size =11234;
      printf("\n %i",a);//integer
      printf("\n %u",a); //unsigned 
      printf("\n %p",&a); //pointer to a
      printf("\n %c",'a');//character
      printf("\n %s","Hello");// sstring
      printf("\n %%");
      printf("\n %g",1.12);//greater
      printf("\n###%5d###",-32);//print only five figures
      printf("\n###% d###",-12);// printing signed numbers
      printf("\n###%.2f###",.2);// precision.
     // printf("\n%ld",a); //long  integer
      printf("\n%zu",size);
    return 0;
}
