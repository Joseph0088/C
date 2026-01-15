#include <stdio.h>

#define print(count,...){                                  \
           for(int i = 0 ; i < (count); i++ )               \
                 printf(__VA_ARGS__);                     \
}


int main(void){
     print(1,"Hi %s %i %s\n","bonjour",2,"Booh");
}
