#include<stdio.h>
#define faulse 0
#define true 1
typedef struct{
  char suit;
  int value;
}Card;
void bubbleSort(Card *A,int N){
  int i,j,flg;
  Card t;
  for(i = 0;i < N; i++){
    flg = 0;
    for(j = N - 1;j >= i + 1;j--){
      if(A[j].value < A[j - 1].value){
        t.suit = A[j].suit;
        t.value = A[j].value;
        A[j].suit = A[j - 1].suit;
        A[j].value = A[j - 1].value;
        A[j - 1].suit = t.suit;
        A[j - 1].value = t.value;
        flg = 1;
      }
    }
    if(flg == 0) break;
  }
}
void selectingSort(Card *A,int N){
  int i,j,minj;
  Card t;
  for(j = 0;j < N; j++){
    minj = j;
    for(i = j;i < N;i++){
      if(A[i].value < A[minj].value) minj = i;
    }
      if(minj != j){
      t.suit = A[j].suit;
      t.value = A[j].value;
      A[j].suit = A[minj].suit;
      A[j].value = A[minj].value;
      A[minj].suit = t.suit;
      A[minj].value = t.value;
    }
  }
}
int isStanble(Card *C1,Card *C2,int N){
  int i;
  for(i = 0;i < N;i++){
    if(C1[i].suit != C2[i].suit) return faulse;
  }
  return true;
}
int main(){
  Card C1[100],C2[100];
  int N,i;
  char ch,space;
  scanf("%d\n",&N);
  for(i =0;i < N;i++){
    scanf("%c%d%c",&C1[i].suit,&C1[i].value,&space);
  }
  for(i = 0;i < N;i++){
    C2[i].suit = C1[i].suit;
    C2[i].value = C1[i].value;
  }
  bubbleSort(C1,N);
  selectingSort(C2,N);
  for(i =0;i < N - 1;i++) printf("%c%d ",C1[i].suit,C1[i].value);
  printf("%c%d\nStable\n",C1[i].suit,C1[i].value);
  for(i =0;i < N - 1;i++) printf("%c%d ",C2[i].suit,C2[i].value);
  printf("%c%d\n",C2[i].suit,C2[i].value);
  if(isStanble(C1,C2,N)) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}

