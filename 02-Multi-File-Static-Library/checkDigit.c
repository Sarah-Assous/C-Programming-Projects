# include "myHeaders/utils.h"

int checkDigit(int num,int indices){
   int count=countDigits(num);
   while(indices!=0){
     if(indices%10>count)
       return 0;
     indices=indices/10;
   }
 return 1;
}
