#include<stdio.h>

typedef struct{
  int value;
  char moji;
}Set;

void BubbleSort(void);
void SelectionSort(void);
void isstable(void);

int n;
Set A[36],B[36];

int main(){
  //Set A[36],B[36];
  int i;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].moji,&A[i].value);
    //printf("%c\n", A[i].moji);
    B[i]=A[i];
  }
//for(i=0;i<n;i++)printf("%c%d\n", A[i].moji,A[i].value);
  BubbleSort();

  SelectionSort();

  return 0;
}

void BubbleSort(){
  int i,j;
  Set c;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j].value<A[j-1].value){
        c = A[j];
        A[j] = A[j-1];
        A[j-1] = c;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%c%d ", A[i].moji,A[i].value);
  }
  printf("%c%d\n", A[i].moji,A[i].value);
  printf("Stable\n");
}

void SelectionSort(){
  int i,j,min;
  Set c;

  for(i=0;i<n;i++){
    min = i;
    for(j=i;j<n;j++){
      if(B[j].value<B[min].value) min = j;
    }
    c = B[i];
    B[i] = B[min];
    B[min] = c;
  }
  for(i=0;i<n-1;i++){
    printf("%c%d ", B[i].moji,B[i].value);
  }
  printf("%c%d\n", B[i].moji,B[i].value);
  isstable();
}

void isstable(){
  int i,x=0;
  for(i=0;i<n;i++){
    if(A[i].value==B[i].value && A[i].moji!=B[i].moji) x=1;
  }
  if(x==1) printf("Not stable\n");
  else printf("Stable\n");
}