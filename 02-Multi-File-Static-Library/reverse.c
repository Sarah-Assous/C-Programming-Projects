int reverse(int num){
 int result=0;
  while(num>0){
   int digit=num%10;
   result=result*10+digit;
   num=num/10;
   }
 return result;
}
