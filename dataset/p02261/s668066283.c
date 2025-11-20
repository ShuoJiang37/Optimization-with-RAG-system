#include<stdio.h>

typedef struct{
  char suit;
  char num;
  int idx;
}Card;

void print(Card* A, int N){
  int i;
  for(i = 0; i < N; i++){
    if(i) printf(" ");
    printf("%c%c",A[i].suit,A[i].num);
  }
  printf("\n");
}

void is_stable(Card* A, int N){
  int i;
  for(i = 0; i+1 < N; i++)
    if(A[i].num == A[i+1].num && A[i].idx > A[i+1].idx){
      printf("Not stable\n");
      return;
    }
  printf("Stable\n");
}

void swap(Card* a, Card* b){
  Card tmp = *a;
  *a = *b;
  *b = tmp;
}

int bubble_sort(Card* A, int N){
  int i,j, cnt=0;
  for(i = 0; i < N; i++)
    for(j = N-1; j >= i+1; j--)
      if(A[j].num < A[j-1].num){
	swap(&A[j],&A[j-1]);
	cnt++;
      }
  return cnt;
}

int selection_sort(Card* A, int N){
  int i,j,cnt=0;
  for(i = 0; i < N; i++){
    int mini = i;
    for(j = i; j < N; j++) if(A[j].num < A[mini].num) mini = j;
    cnt += (i==mini?0:1);
    swap(&A[i],&A[mini]);
  }
  return cnt;
}

int main(){
  int i,N;
  Card data1[40],data2[40];
  scanf("%d\n",&N);
  for(i = 0; i < N; i++) scanf("%c%c ",&data1[i].suit, &data1[i].num);
  for(i = 0; i < N; i++){
    data2[i] = data1[i];
    data1[i].idx = data2[i].idx = i;
  }
  bubble_sort(data1,N);
  selection_sort(data2,N);
  print(data1,N);
  is_stable(data1,N);
  print(data2,N);
  is_stable(data2,N);
  return 0;
}