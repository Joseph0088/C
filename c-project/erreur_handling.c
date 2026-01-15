#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

int main(void){

FILE *f = fopen("animals.txt","wa");
      //assert(f); //methode one to throw the error 
      //now method 2
      if(f==NULL){
          printf("%i",errno);
          perror(NULL);
          exit(-1);
      }
 
      char c;
      while (c=fgetc(f) !=EOF){
            fputc(c,stdout);
       }
        free(f);
      return 0;

}
