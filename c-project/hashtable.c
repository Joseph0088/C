#include <stdio.h>

enum foo{
        foo_2=0,
        foo_3,
        foo_4,

};

static int square[] ={
       [foo_3] =9,
       [foo_2] =4,
       [foo_4] =10,
};

static char case_coverte[]={
        ['a'] = 'A',
        ['b']  = 'B',
        ['c'] = 'c',
};

int main(){

   printf("%d\n",square[foo_2]);
   printf("%d\n",square[foo_3]);
   printf("%d\n",square[foo_4]);

   printf("%c\n",case_coverte['b']);
   printf("%c\n",case_coverte['c']);
   printf("%c\n",case_coverte['a']);

return 0;
}
