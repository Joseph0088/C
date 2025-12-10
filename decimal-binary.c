#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define b64 64

void Bin(int dec);
int Dec(int bin);
int main(){

char j='c';
     do{
       printf("\n Enter 'd' for decimal to binary and 'b' for binry to decimal and 'e' to terminate the program\n");
       scanf("%c",&j);
       switch(j){
        case 'd':
           int decimal=0;
            printf("Decimal Val: ");
            scanf("%i",&decimal);
            printf("\n\nDec: %i ",decimal);
            printf("\nBin: ");
            Bin(decimal);
            printf("\n\n\n");
        break;
        case 'b':
            int bin;
            printf("Binary Val: ");
            scanf("%i",&bin);
            printf("\n\n Bin: %i ",bin);
            printf("\nDec: %i",Dec(bin));
            printf("\n\n\n");
        break;
        case 'e':
             exit(-1);
        break;
        defaut:
               printf("Error a VALID value 'd','b' or 'e' ");
        }
    }while(j!='e');
return 0;
}


void Bin(int dec){
    int div=1, res;

    while(div>0){
       div = dec/2;
       res = dec%2;
       printf("%i",res);
       dec = div;
    }
}

int Dec(int bin) {
    int sum = 0,i=0;
    //find
    if(bin>=0){
        do{
            i++;
          }while(bin<=pow(10,i));
        for(int j=i;j >=0 ;j--){
          if(bin/pow(10,j)>1){
              printf("\n The number Value entered is not in base 2");
              return 0;
            }
          sum+=bin/pow(10,j);
    }
   }else{
     printf("\nInvide input");
     return 0;
   }
    return sum;
}


