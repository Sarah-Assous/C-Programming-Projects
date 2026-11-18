#include <stdio.h>

int degree(int P[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (P[i] != 0)
            return i;
    }
    return -1;
}

void divPoly(int A[], int sizeA, int B[], int sizeB) {

    int degA = degree(A, sizeA);
    int degB = degree(B, sizeB);

    int Q[100] = {0};
    int R[100];

    for (int i = 0; i < sizeA; i++)
        R[i] = A[i];

    while (degA >= degB) {

        int coef = R[degA] / B[degB];
        int shift = degA - degB;

        Q[shift] = coef;

        for (int i = 0; i <= degB; i++) {
            R[i + shift] -= coef * B[i];
        }

        degA = degree(R, sizeA);
    }

    printf("Quotient: ");

int first = 1;
for (int i = sizeA - 1; i >= 0; i--) {
    if (Q[i] != 0) {

        if (!first) {
            if (Q[i] > 0)
                printf(" + ");
            else
                printf(" - ");
        } else {
            if (Q[i] < 0)
                printf("-");
            first = 0;
        }

        int coef = Q[i] > 0 ? Q[i] : -Q[i];

        if (i == 0)
            printf("%d", coef);
        else if (i == 1)
            printf("%dx", coef);
        else
            printf("%dx^%d", coef, i);
    }
}
printf("\n");

    printf("Remainder: ");

int firstR = 1;
for (int i = sizeA - 1; i >= 0; i--) {
    if (R[i] != 0) {

        if (!firstR) {
            if (R[i] > 0)
                printf(" + ");
            else
                printf(" - ");
        } else {
            if (R[i] < 0)
                printf("-");
            firstR = 0;
        }

        int coef = R[i] > 0 ? R[i] : -R[i];

        if (i == 0)
            printf("%d", coef);
        else if (i == 1)
            printf("%dx", coef);
        else
            printf("%dx^%d", coef, i);
    }
}
printf("\n");
}
int main() {

    // A(x) = 4 - 2x + 0x^2 + 1x^3
    int A[] = {4, -2, 0, 1};

    // B(x) = -1 + 1x
    int B[] = {-1, 1};

    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    divPoly(A, sizeA, B, sizeB);

    return 0;
}
