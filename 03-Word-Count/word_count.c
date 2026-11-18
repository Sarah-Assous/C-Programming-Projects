#include <stdio.h>
int isWhitespace(int c){
 return (c==' '||c=='\t'||c=='\n');
}

int isLetter(int c){
 return ((c>='A' && c<='Z')|| (c>='a' && c<='z'));
}

int isDigit(int c){
 return (c>='0' && c<='9');
}

 int main(void)
{
  int c;

  int nbChars=0;
  int nbWords=0;
  int nbLines=0;
  int nbLetters=0;
  int nbDigits=0;
  int nbWhitespace=0;
  
  int inWord=0;
  int lastChar='\n';

  while ((c=getchar())!=EOF)
  {
       nbChars++;
       lastChar=c;

     if(isWhitespace(c))
     {
       nbWhitespace++;

        if(c=='\n')
        {
          nbLines++;
        }
   
       inWord=0;
     }
    else 
    {    
     if(!inWord)
     {
      nbWords++;
      inWord=1;
     }
    }
    if(isLetter(c))
    {
     nbLetters++;
    }
    if(isDigit(c))
    {
     nbDigits++;
    }
  }
  if(nbChars>0 && lastChar!='\n')
  {
   nbLines++;
  }


  printf("Total chars:%d\n",nbChars);
  printf("Total words:%d\n",nbWords);
  printf("Total lines:%d\n",nbLines);
  printf("Total letters:%d\n",nbLetters);
  printf("Total digits:%d\n",nbDigits);
  printf("Total whitespace:%d\n",nbWhitespace);

  return 0;
}



















