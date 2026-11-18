#include <stdio.h>

void transpose(int *a[])
{
    int **q = a;

    int *refRow = NULL;
    int *refEnd = NULL;

    while (*q)
    {
        int *row = *q;
        int *rowEnd = row + *row;

        if (refRow == NULL || (rowEnd - row) > (refEnd - refRow))
        {
            refRow = row;
            refEnd = rowEnd;
        }
        q++;
    }
    
    

    if (refRow == NULL)
        return;

    int *refCol = refRow + 1;

    while (refCol < refEnd)
    {
        q = a;

        while (*q)
        {
            int *row = *q;
            int *rowEnd = row + *row;

            int *cell = (row + 1) + (refCol - (refRow + 1));

            if (cell < rowEnd)
                printf("%4d", *cell);      
            else
                printf("%4s", "");       

            q++;
        }

        printf("\n");
        refCol++;
    }
}


int main(){
int A[]={5,-5,14,5,2};
int B[]={3,6,11};
int C[]={4,1,-3,4};
int D[]={6,2,7,1,8,2};
int E[]={2,15};
int F[]={3,4,-2};
int *All[]={A,B,C,D,E,F,NULL};
transpose(All);
return 0;
}
