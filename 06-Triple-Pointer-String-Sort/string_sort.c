#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void printAllStrings(char ***s){
    if(s==NULL)
    return;
    for (int i=0;s[i]!=NULL;i++){
        char **p=s[i];
        for(int j=0;p[j]!=NULL;j++){
            char *q =p[j];
            while (*q){
                printf("%c",*q);
                q++;
            }
            printf(" ");
        }
        printf("\n");
    }
}


void sort (char ***s){
     if(s==NULL)
    return;
    
    
    int total = 0;
   for (int i = 0; s[i] != NULL; i++) {
    for (int j = 0; s[i][j] != NULL; j++) {
        total++;
    }
  }
  
  char **newArray = malloc((total + 1) * sizeof(char *));
   if (newArray == NULL)
    return;
   
    
    char *temp;
    int k=0;
    for(int i=0;s[i]!=NULL;i++){
        char **p=s[i];
        for(int j=0;p[j]!=NULL;j++){
            newArray[k]=p[j];
            k++;
        }
    }
    
    newArray[k]=NULL;
      for(int i=0;newArray[i]!=NULL;i++){
          for(int j=i+1;newArray[j]!=NULL;j++){
              if(strcmp(newArray[i],newArray[j])>0){
                  temp=newArray[i];
                  newArray[i]=newArray[j];
                  newArray[j]=temp;
              }
          }
      }
      k=0;
       for(int i=0;s[i]!=NULL;i++){
        char **p=s[i];
        for(int j=0;p[j]!=NULL;j++){
            p[j]=newArray[k];
            k++;
      
        }
       }
       free(newArray);
}







char *maxLengthString(char ***s){
    if(s==NULL)
    return NULL;
    char *maxLengthS=NULL;
    int maxLength=0;
    int count=0;
    for (int i=0;s[i]!=NULL;i++){
        char **p=s[i];
        for (int j=0;p[j]!=NULL;j++){
            count= strlen(p[j]);
            
            if(count>maxLength){
                maxLength=count;
                maxLengthS=p[j];
            }
        }
    }   
    return maxLengthS;
}










int main ()
{
 char * arrP1 [ ] = { "father", "mother", NULL};
 char * arrP2 [ ] = { "sister", "brother", "grandfather", NULL };
 char * arrP3 [ ] = { "grandmother", NULL};
 char *arrP4 [ ] = { "uncle", "aunt", NULL };
 char ** arrPP [ ] = { arrP1, arrP2, arrP3, arrP4 , NULL};
 
printf("All strings:\n");
 printAllStrings(arrPP);
 printf("\n");
 printf("Sort:");
 sort (arrPP);
 printf("\n");
 printAllStrings(arrPP);
  
 printf("\n");
 printf("maxLengthString: %s\n", maxLengthString (arrPP));
return 0;
}
