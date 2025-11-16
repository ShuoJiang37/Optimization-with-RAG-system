#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Card{
  char suit;
  int value;
};
void bubble(struct Card A[],int N){
  int i,j;
  struct Card t;
  for(i = 0 ; i < N ; i++){
    for(j = N - 1 ; j >= i + 1 ; j--){
      if(A[j].value < A[j - 1].value){
	t = A[j];
	A[j] = A[j - 1];
	A[j - 1] = t;
      }
    }
  }    
}

void selection(struct Card A[],int N){
  int i,j,minj;
  struct Card t;
  for(i = 0 ; i < N ; i++){
    minj = i;
    for(j = i ; j < N ; j++){
      if(A[j].value < A[minj].value)minj = j;
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
  }
}

void print(struct Card A[],int N){
  int i;
  for(i = 0 ; i < N ; i++){
    if(i > 0)printf(" ");
    printf("%c%d",A[i].suit,A[i].value);
  }
  printf("\n");
}

int isStable(struct Card C1[],struct Card C2[],int N){
  int i;
  for(i = 0 ; i < N ; i++){
    if(C1[i].suit != C2[i].suit)return 0;
  }
  return 1;
}

int main(){
  struct Card C1[100],C2[100];
  int N,i;
  char num[3];

  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%s",num);
    C1[i].suit = num[0];
    C1[i].value = atoi(&num[1]);
  }

  for(i = 0 ; i < N ; i++){
    C2[i] = C1[i];
  }
  bubble(C1,N);
  selection(C2,N);

  print(C1,N);
  printf("Stable\n");
  print(C2,N);
  if(isStable(C1,C2,N)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}

