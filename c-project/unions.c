#include <stdio.h>
#include <stdbool.h>
enum tag{
     TAG_BOO,
     TAG_INT,
     TAG_FLOAT,

};

typedef struct dynamic {
     enum tag tag;
     union {
      bool b;
      int i;
      float f;
     }value;
    }call;

int main(void){
 call d;
//d.tag = TAG_INT;
//d.value.i = 42;

 d.tag = TAG_FLOAT;
 d.value.f = 42.42;

 switch(d.tag){

  case TAG_BOO: printf("bool: %d\n",d.value.b); break;
  case TAG_INT : printf("int: %d\n",d.value.i); break;
  case TAG_FLOAT: printf("float: %f\n",d.value.f); break;

  default:
        printf("unknown type \n"); 

}

}
