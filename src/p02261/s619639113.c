#include<stdio.h>

typedef struct{
  char suit;
  int value;
}Card;

void bubble(Card A[], int N){
  int i,j;
  Card t;

  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j].value<A[j-1].value){
	t = A[j];
	A[j] = A[j-1];
	A[j-1] = t;
      }
    }
  }
}

void selection(Card A[], int N){
  int i,minj,j;
  Card t;
  
  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j].value<A[minj].value)minj=j;
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
  }
}

void print(Card A[], int N){
  int i;

  for(i=0;i<N-1;i++){
    printf("%c%d ",A[i].suit,A[i].value);
  }
  printf("%c%d\n",A[i].suit,A[i].value);
}

int isStable(Card C1[], Card C2[], int N){
  int i;

  for(i=0;i<N;i++){
    if(C1[i].suit != C2[i].suit)return 0;//false
  }
  return 1;//true
}

int main(){
  Card C1[100], C2[100];
  int N,i;
  char ch;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i].suit,&C1[i].value);
    C2[i] = C1[i];
  }

  bubble(C1,N);
  selection(C2,N);

  print(C1,N);
  if(isStable(C1,C1,N)==1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  print(C2,N);
  if(isStable(C1,C2,N)==1){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}

