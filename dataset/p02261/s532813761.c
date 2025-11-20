#include <stdio.h>
#include <string.h>
#define N 36

typedef struct {
  char mark;
  int value;
} Card;

void BubbleSort(Card *,int);
void SelectionSort(Card *,int);
void Pri(Card *,int);
int judge(Card *,Card *,int);

int main(){
  Card C1[N], C2[N];
  int i, n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&C1[i].mark,&C1[i].value);
  }
  for(i=0;i<n;i++){
    C2[i] = C1[i];
  }
  BubbleSort(C1,n);
  Pri(C1,n);
  printf("Stable\n");
  SelectionSort(C2,n);
  Pri(C2,n);
  if( judge(C1,C2,n)==0){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}
void BubbleSort(Card C[], int n)
{
  int i, j;
  Card cng;

  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(C[j].value<C[j-1].value ){
        cng=C[j];
        C[j]=C[j-1];
        C[j-1]=cng;
      }
    }
  }
}
void SelectionSort(Card C[], int n){
  int i,j,min;
  Card cng;

  for(i=0;i<=n-2;i++){
    min=i;
    for(j=i;j<=n-1;j++){
      if(C[j].value<C[min].value){
    min=j;
      }
    }
    cng=C[i];
    C[i]=C[min];
    C[min]=cng;
  }
}

void Pri(Card C[],int n)
{
  int i;

  for(i=0;i<n;i++){
    if(i>0){
      printf(" ");
    }
    printf("%c%d",C[i].mark,C[i].value);
  }
  printf("\n");
}

int judge(Card C1[],Card C2[],int n)
{
  int i;

  for(i=0;i<n;i++)
    if(C1[i].mark!=C2[i].mark){
      return 1;
    }
  return 0;
}

