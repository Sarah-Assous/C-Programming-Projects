int countDigits(int n){
 if(n<10)
   return 1;
 else 
   return countDigits(n/10)+1;
}
