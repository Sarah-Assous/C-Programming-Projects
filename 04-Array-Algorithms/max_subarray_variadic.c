#include <stdio.h>
#include <stdarg.h>

void maxSubArraySumEllipsis(int size,...){
    va_list param;
    va_start (param,size);

    int currentSum = va_arg(param,int);
    int maxSum = currentSum;

    int sum = 0;
    int x = 0;
    int start = 0;
    int bestStart = 0;
    int end = 0;

    for(int i = 1; i < size; i++){
        x = va_arg(param,int);
        sum = currentSum + x;

        if(sum > 0)
            currentSum += x;
           
        else{
            currentSum = 0;
            start = i + 1;
        }

        if (currentSum > maxSum){
            maxSum = currentSum;
            end = i;
            bestStart = start;          
        }
    }

    va_end(param);

    printf("max sum = %d\n", maxSum);
    printf("start=%d end=%d\n", bestStart + 1, end + 1);
}

int main()
{
    maxSubArraySumEllipsis(4,-4,-2,6,-5);
     maxSubArraySumEllipsis(9, -2, 1, -3, 4, -1, 2, 1, -5, 4);
    return 0;
}
