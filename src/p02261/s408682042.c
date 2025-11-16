#include <stdio.h>
#include <stdbool.h>
typedef struct {
  char gara;
  int value;
}Huda;

void bubbleSort(Huda [],int);
void selectionSort(Huda [],int);
void printArray(Huda [],int);
bool isStable(Huda [],Huda[],int N);

int main(){
 Huda H1[50];
 Huda H2[50];
 int n;
 char ch;
 int i;

 scanf("%d",&n);
 for(i=0;i<n;i++){
   scanf(" %c%d",&H1[i].gara,&H1[i].value);
 }

for(i=0;i<n;i++){
  H2[i]=H1[i];
}

 bubbleSort(H1,n);
 selectionSort(H2,n);

printArray(H1,n);
printf("Stable\n");
printArray(H2,n);
if(isStable(H1,H2,n)){
  printf("Stable\n");
}else printf("Not stable\n");

return 0;
}

void bubbleSort(Huda H1[],int N){
  int i,j;
  int h;
  i=0;
  Huda t;

for(h=0;h<=N-1;h++){
    for(j=N-1;j>=i+1;j--){
      if(H1[j].value<H1[j-1].value){
        t=H1[j];
        H1[j]=H1[j-1];
        H1[j-1]=t;
}
    }
  i++;
  }
 }

 void selectionSort(Huda H2[],int N){
   int i,minj,j;
   Huda t;
   for(i=0;i<N;i++){
     minj=i;
     for(j=i;j<N;j++){
       if(H2[j].value<H2[minj].value){
         minj=j;
       }
     }
   if(i!=minj){
     t=H2[i];
     H2[i]=H2[minj];
     H2[minj]=t;
   }
  }
  }

bool isStable(Huda H1[],Huda H2[],int N){
  int i;
  for(i=0;i<N;i++){
    if(H1[i].gara!=H2[i].gara)return false;
  }
return true;
}

void printArray(Huda A[],int N){
  int i;
  for(i=0;i<N;i++){
    if(i)printf(" ");
    printf("%c%d",A[i].gara,A[i].value);
  }
printf("\n");
}