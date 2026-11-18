#include <stdio.h>

int isSubsequence (int A[],int size_A,int B[],int size_B ){
    int count=0;
    int j=0;
    for(int i=0;i<size_A&& j < size_B;i++){
    if(A[i]==B[j]){
        count++;
        j++;
    }
    }
    if(count==size_B)
    return 1;
    else 
    return 0;
    
}


int main(){
    
    int A[]={2,8,14,-9,5,6,2,19,4};
    int B[]={8,5,2,4};
printf("%d\n",isSubsequence(A,sizeof(A)/sizeof(A[0]),B, sizeof(B)/sizeof(B[0])));
       
    int A2[] = {7, 8, 9};
    int B2[] = {8, 7};
printf("%d\n", isSubsequence(A2,sizeof(A2)/sizeof(A2[0]),B2,sizeof(B2)/sizeof(B2[0])));
    
    return 0;
    
}
