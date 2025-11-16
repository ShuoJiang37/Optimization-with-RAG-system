#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char suit;
  char value;
}Card;

//void bubble(Card, int);
//void selection(Card, int);
//void print(Card, int);
//int isStable(Card, Card, int);

void bubble(Card A[100], int N){
  int i,j;
  Card t;
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j].value<A[j-1].value){
        t=A[j];A[j]=A[j-1];A[j-1]=t;
      }
    }
  }
}

void selection(Card A[], int N){
  int i,j,minj;
  Card t;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j].value<A[minj].value) minj=j;
    }
    t=A[i];A[i]=A[minj];A[minj]=t;
  }
}

void print(Card A[], int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%c%c",A[i].suit,A[i].value);
  }
  printf("\n");
}

int isStable(Card C1[], Card C2[], int N){
  int i;
  for(i=0;i<N;i++){
    if(C1[i].suit!=C2[i].suit) return 1;
  }
  return 0;
}

int main(){
  Card C1[100],C2[100];
  int M;
  char ch;
  int i,j;

  scanf("%d",&M);
  for(i=0;i<M;i++) scanf(" %c%c",&C1[i].suit,&C1[i].value);

  for(i=0;i<M;i++) C2[i]=C1[i];

  bubble(C1,M);
  selection(C2,M);
  print(C1,M);
  printf("Stable\n");
  print(C2,M);
  if(isStable(C1,C2,M)==0){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  return 0;
}


