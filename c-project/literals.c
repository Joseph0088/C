#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){

    char * literal = " I am a  string literal";
    char *s = strdup(literal);
    char arr[] =" I am an string array";
    arr[0]='#';
    s[0]='#';
    
    printf("%s\n",s);
    printf("%s\n",arr);




}
