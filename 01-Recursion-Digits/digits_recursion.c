#include<stdio.h>

int sumDigits(int n){
if(n<10)
return n;
else
return sumDigits(n/10)+n%10;
}

int searchOnce(int n,int d){
if(n<10)
return n==d;
else {
if(n%10==d)
return 1;
return searchOnce(n/10,d);
}
}

int countAll(int n,int d){
if(n<10){
  if(n==d)
     return 1;
  else 
    return 0;
}
int counter=0;
if(n%10==d)
counter++;
return counter+countAll(n/10,d);
}

int getMax(int n){
if(n<10)
return n;
int max=n%10;
int m=getMax(n/10);
if(m>max)
max=m;
return max;
}

int countEvens(int n){
if(n<10)
return n%2==0;
int counter=0;
if((n%10)%2==0)
counter++;
return counter+countEvens(n/10);
}

int isSorted(int n){
if(n<10)
return 1;
int last =n%10;
int next=(n/10)%10;
if(next<last)
return 0;
return isSorted(n/10);
}

int sort(int n){
if(n<10)
return n;
int x=sort(n/10);
if(n%10<x%10)
return x*10+n%10;
else
return sort((x/10)*10+n%10)*10+x%10;
}


int merge(int n,int m){
if(n==0)
return m;
if(m==0)
return n;
if(n%10<m%10)
return (merge(n/10,m))*10+n%10;
else 
return (merge(n,m/10))*10+m%10;
}


void adjacentHanoi(int n,int from,int aux,int to){
if(n==0)
  return;
if(n==1){
   if(from+1==to||from-1==to)
     printf("Move disk from %d to %d\n",from,to);
else{
printf("Move disk from %d to %d\n",from,aux);
printf("Move disk from %d to %d\n",aux,to);
}
  return;
}
adjacentHanoi(n-1,from,to,aux);
adjacentHanoi(1,from,aux,to);
adjacentHanoi(n-1,aux,from,to);

}

int main(){
printf("sumDigits=%d",sumDigits(57812));
printf("\nsearchOnce=%d",searchOnce(57812,5));
printf("\nsearchOnce=%d",searchOnce(42361,7));
printf("\ncountAll=%d",countAll(578172,7));
printf("\ngetMax=%d",getMax(57812));
printf("\ncountEvens=%d",countEvens(578712));
printf("\nisSorted=%d",isSorted(321));
printf("\nisSorted=%d",isSorted(123));
printf("\nsort=%d",sort(51432));
printf("\nmerge=%d",merge(321,432));
printf("\n");
adjacentHanoi(3,1,2,3);

return 0;
}
