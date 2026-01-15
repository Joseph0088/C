#include <stdio.h>


typedef struct foo{
            int first_4 : 4;
            int next_4 : 4;
            int alone : 1;
            int first_7 : 7;

} foo;

int main(void){
    foo f;
    f.first_4=2;
    f.next_4=4;
    f.alone =1;
   printf("%d",f.first_4);
}
