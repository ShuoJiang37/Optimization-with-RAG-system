#include<stdio.h>

typedef struct{
  char suit;
  int value;
} Card;

void bubble(Card *A,int N){
  int i,j;
  Card temp;
  for(i=0 ; i<N ; i++){
    for(j=N-1 ; j>=i+1 ; j--){
      if(A[j].value < A[j-1].value){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
      }
    }
  }
}

void selection(Card *A,int N){
  int i,j,minj;
  Card temp;
  for(i=0 ; i<N ; i++){
    minj = i;
    for(j=i ; j<N ; j++){
      if(A[j].value < A[minj].value) minj = j;
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
}

void print(Card *A,int N){
  int i;
  for(i=0 ; i<N ; i++){
    if(i == N-1) printf("%c%d\n",A[i].suit,A[i].value);
    else printf("%c%d ",A[i].suit,A[i].value);
  }
}

char isStable(Card C1[],Card C2[],int N){
  int i;
  for(i=0 ; i<N ; i++) if(C1[i].suit != C2[i].suit) return 'F';
  return 'T';
}

int main(){
  Card C1[100],C2[100];
  char c;
  int N;
  int i;
  char ch;

  scanf("%d",&N);
  for(i=0 ; i<N ; i++) scanf(" %c%d",&C1[i].suit,&C1[i].value);
  for(i=0 ; i<N ; i++) C2[i] = C1[i];

  bubble(C1,N);
  selection(C2,N);

  print(C1,N);
  printf("Stable\n");

  print(C2,N);
  if(isStable(C1,C2,N) == 'T') printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}