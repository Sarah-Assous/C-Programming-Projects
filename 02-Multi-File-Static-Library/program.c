#include <stdio.h>
#include "myHeaders/utils.h"
 int createNumByIdx(int num,int indices){
   int countNum=countDigits(num);
   int countIndices=countDigits(indices);
   int idc= indices;
   int new_num=0;
   
   for(int i=0;i<countIndices;i++){
    int digit_i=idc%10;
    idc/=10;
    int nm=num;
    int count=countNum;
    int y=0;
       for(int j=0;j<countNum;j++){
        int digit_n=nm%10;
        count--;
        if(count==digit_i){
         y=digit_n;
        }
        nm/=10;
      }
      new_num=new_num*10+y;
   }
   return reverse (new_num);
}



int main(void){
  int num;
  int indices;
  printf("Enter a num and an indice\n");
  if((scanf("%d",&num))==EOF ||(scanf("%d",&indices))==EOF){
    fprintf(stderr,"2\n");
    return 2;
  }
  else if(num==0||indices==0){
   fprintf(stderr,"4\n");
   return 4;
  }
  else if(num<0||indices<0){
  fprintf(stderr,"3\n");
  return 3;
  }
  else if(checkDigit(num,indices)==0){
  fprintf(stderr,"1\n");
  return 1;
  }
  else{
    int createNumIdx=createNumByIdx(num,indices);
    printf("The new number is:%d\n",createNumIdx);
  }
  return 0;
}
