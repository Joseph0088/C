#include <stdio.h>

#define FOO(x,y) printf("%s + %s = %d", #x, #y, (x)+(y))
#define PREFIX(var) new_##var
#define generic_func_add(type) \
      type add_##type(type x, type y){ \
      return x+y;                  \
}


generic_func_add(int)


int main(){
//  int first =1,last=2;
//  FOO(first,last);
//  int PREFIX(foo) = 1;
//  printf("\n %i",new_foo);

printf("\n %i",add_int(1,3));
return 0;
}
