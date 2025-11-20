#include<stdio.h>
typedef struct
{
  char suit;
  int value;
}Card;

void bubble(Card A[], int N);
void selection(Card A[], int N);
void print(Card A[], int N);
int isStable(Card C1[],Card C2[], int N);

int main(){
  Card C1[100],C2[100];
  int N,i;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf(" %c %d",&C1[i].suit,&C1[i].value);
  for(i=0;i<N;i++) C2[i]=C1[i];
  
  bubble(C1,N);
  selection(C2,N);
  
  print(C1,N);
  printf("Stable\n");
  print(C2,N);
  if(isStable(C1,C2,N)==1){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}

void bubble( Card A[], int N){
  int i,j;
  Card a;
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j].value<A[j-1].value){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
      }
    }
  }
}

void selection(Card A[], int N){
  int i,j,minj;
  Card a;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j].value<A[minj].value) minj=j;
    }
    a=A[i];
    A[i]=A[minj];
    A[minj]=a;
  }
}

void print(Card A[], int N){
  int i;
  for(i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%c%d",A[i].suit,A[i].value);
    }
  printf("\n");
}

int isStable(Card C1[],Card C2[], int N){
  int i;
  for(i=0;i<N;i++){
    if(C1[i].suit!=C2[i].suit) return 0;
  }
  return 1;
}
