#include <stdio.h>

void maxSubArray(int A[], int size) {
    int maxSum = A[0];
    int start = 0;
    int end = 0;

    for (int i = 0; i < size; i++) {
        int currentSum = 0;

        for (int j = i; j < size; j++) {
            currentSum += A[j];

            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = i;
                end = j;
            }
        }
    }

    printf("max = %d\n", maxSum);

    for (int i = start; i <= end; i++) {
        printf("%d\n", A[i]);
    }
}

int main() {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    maxSubArray(A, sizeof(A) / sizeof(A[0]));

    return 0;
}
