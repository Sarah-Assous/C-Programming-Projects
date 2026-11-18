#include <stdio.h>
#include <string.h>

void sortArrayG(void *array, int size, int elementSize,int (*compare)(const void *,const void *));

void swapG(void *a, void *b,int elementSize);

int compareInt(const void *a,const void *b);
int compareDouble(const void *a,const void *b);
int compareStr(const void *a,const void *b);
int comparePointerStr(const void *a, const void *b);

void printArrayG(const void *array,int size, int elementSize,void(*printArray)(const void *));
void printInt(const void *a);
 void printDouble(const void *a);
void printStr(const void *a);
void printPointerStr(const void *a);


int main(){
    int a[] = {2, 7, 6, 4, 1};
    double b[] = {12.5, 2.7, 3.0, 5.5, 5.9, 1.0};
    char c[][5]={"abc","xy","ac"};
    char *d[]=  {"abc","xy","ac"};


    int sizeA = sizeof(a) / sizeof(a[0]);
    int sizeB = sizeof(b) / sizeof(b[0]);
    int sizeC =sizeof(c) / sizeof(c[0]);
    int sizeD =sizeof(d) / sizeof(d[0]);

    
    printf("array a-int befor sort:\n");
    printArrayG(a, sizeA, sizeof(a[0]), printInt);
    printf("\narray b-double befor sort:\n");
    printArrayG(b, sizeB, sizeof(b[0]),printDouble);
    printf("\narray c-array2d befor sort:\n ");
    printArrayG(c , sizeC, sizeof(c[0]),printStr);
    printf("\narray d-arrayOfPointer befor sort:\n ");
    printArrayG(d , sizeD, sizeof(d[0]),printPointerStr);
    printf("\n");
    printf("\n");
    
    
    

    sortArrayG(a, sizeA, sizeof(a[0]),compareInt);

    sortArrayG(b, sizeB, sizeof(b[0]),compareDouble);
    
    sortArrayG(c, sizeC, sizeof(c[0]),compareStr);
     
    sortArrayG(d, sizeD, sizeof(d[0]),comparePointerStr);
    
    
     printf("array a-int after sort:\n");
    printArrayG(a, sizeA, sizeof(a[0]), printInt);
    printf("\narray b-double after sort:\n");
    printArrayG(b, sizeB, sizeof(b[0]),printDouble);
    printf("\narray c-array2d after sort:\n ");
    printArrayG(c , sizeC, sizeof(c[0]),printStr);
    printf("\narray d-arrayOfPointer after sort:\n ");
    printArrayG(d , sizeD, sizeof(d[0]),printPointerStr);
   
    

 


    return 0;
}




void sortArrayG(void *array, int size, int elementSize,int (*compare)(const void *, const void *)){
    char *arr = (char *)array;

    for (int i = 0; i < size; i++) {
        void *element1 = arr + i * elementSize;

        for (int j = i + 1; j < size; j++) {
            void *element2 = arr + j * elementSize;

            if (compare(element1, element2) > 0) {
                swapG(element1, element2,elementSize);
            }
        }
    }
}



void swapG(void *a, void *b,int elementSize){
       char *x = (char *)a;
       char *y = (char *)b;
       char temp;
       for (int i=0;i<elementSize;i++){
           temp=x[i];
          x[i]=y[i];
           y[i]=temp;
       }
}

int compareInt(const void *a, const void *b){
    return *(const int*)a-*(const int*)b;
}


int compareDouble(const void *a, const void *b){
    double diff= *(const double*)a-*(const double*)b;
    if (diff<0.001)
    return 0;
    else if (diff>0)
    return 1;
    return -1;
}


int compareStr(const void *a,const void *b){
    const char *x = (const char *)a;
    const char *y= (const char *)b;
    return strcmp(x,y);
}


int comparePointerStr(const void *a, const void *b){
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return strcmp(s1, s2);
}

void printArrayG(const void *array,int size, int elementSize,void(*printArray)(const void *)){
     const char *arr = (const char *)array;
    for (int i = 0; i < size; i++) {
        const void *element= arr + i * elementSize;
        printArray(element);
    
}
}


void printInt(const void *a){
    printf("%d ",*(const int*)a);
}
 void printDouble(const void *a){
     printf("%.1f ",*(const double*)a);
 }

void printStr(const void *a){
    const char *s = (const char *)a;
    printf("%s ", s);
}

void printPointerStr(const void *a){
    const char *s=*(const char**)a;
    printf("%s ", s);
}
