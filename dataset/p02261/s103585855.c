#include <stdio.h>
#include <string.h>
#define M 36
#define O 0
#define I 1

typedef struct {
  char mark;
  int value;
} Card;

void BubbleSort(Card *,int);
void SelectionSort(Card *,int);
void disply(Card *,int);
int isStable(Card *,Card *,int);

int main(){
  Card C1[M+I], C2[M+I];
  int i, N;

  scanf("%d",&N);
  for(i=O;i<N;i++){
    scanf(" %c%d",&C1[i].mark,&C1[i].value);
  }
  for(i=O;i<N;i++){
    C2[i] = C1[i];
  }
  BubbleSort(C1,N);
  disply(C1,N);
  printf("Stable\n");
  SelectionSort(C2,N);
  disply(C2,N);
  if( isStable(C1,C2,N)==O){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}
void BubbleSort(Card C1[], int N)
{
  int i, j;
  Card t;

  for(i=O;i<N;i++){
    for(j=N-I;j>i;j--){
      if(C1[j].value<C1[j-I].value ){
        t=C1[j];
        C1[j]=C1[j-I];
        C1[j-I]=t;
      }
    }
  }
}
void SelectionSort(Card C2[], int N){
  int i,j,Min;
  Card t;

  for(i=O;i<N;i++){
    Min=i;
    for(j=i;j<N;j++){
      if(C2[j].value<C2[Min].value){
	Min=j;
      }
    }
    t=C2[i];
    C2[i]=C2[Min];
    C2[Min]=t;
  }
}

void disply(Card C[],int N)
{
  int i;

  for(i=O;i<N;i++){
    if(i>O){
      printf(" ");
    }
    printf("%c%d",C[i].mark,C[i].value);
  }
  printf("\n");
}

int isStable(Card C1[],Card C2[],int N)
{
  int i;

  for(i=O;i<N;i++)
    if(C1[i].mark!=C2[i].mark){
      return I;
    }
  return O;
}

