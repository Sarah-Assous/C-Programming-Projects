#include <stdio.h>

void maxSubArraySumV2(int A[], int size){
    int maxSum=A[0];
  
    int start=0;
    int bestStart=0;
    int end=0;
    
    int currentSum=0;
    int sum=0;
   
    for(int i=0;i<size;i++){
        sum=currentSum+A[i];
        if(sum>0){
        currentSum+=A[i];
        
        }
        else{
        currentSum=0;
        start=i+1;
        }
        
        
         if(currentSum>maxSum){
            maxSum=currentSum;
             end=i;
             bestStart=start;
         }   
    }
    printf("max sum =%d\n",maxSum);
    printf("start=%d,end=%d\n",bestStart,end);
    for(int i=bestStart;i<=end;i++){
       printf("%d\n",A[i]);
       
   }
   

}





int main()
{
   int A []={-4,-2,6,-5};
   maxSubArraySumV2(A,sizeof(A)/sizeof(A[0]));
    int B []={-2, 1, -3, 4, -1, 2, 1, -5, 4};
   maxSubArraySumV2(B,sizeof(B)/sizeof(B[0]));

    return 0;
}

