#include<stdio.h>

typedef struct {
  char mark;
  int value;
}kard;

void bubble (kard*,int);
void select (kard*,int);

int main(){
  kard A[36],B[36],C[36];
  int i,j,N,flag=0;

  scanf("%d",&N);
  for(i = 0 ; i < N;i++){
    scanf("%c",&A[i].mark);
    scanf("%c%d",&A[i].mark,&A[i].value);
    B[i] = A[i];
    C[i] = A[i];
  }
  bubble(B,N);
  printf("Stable\n");
  select(C,N);
  for(i = 0 ; i < N;i++){
    if(B[i].mark != C[i].mark) flag = 1;
      }
  if(flag == 1) printf("Not stable\n");
  else printf("Stable\n");
}

void bubble(kard* A,int N){
  kard num;
  int i,j;
  
for(i = 0; i < N; i++){
    for(j = N - 1; j > i ; j--){
      if(A[j].value < A[j-1].value){
	num = A[j-1];
	A[j-1] = A[j];
	A[j] = num;
      }
    }
  }
 for(i = 0 ; i < N;i++){
   if(i) printf(" ");
   printf("%c%d",A[i].mark,A[i].value);
 }
 printf("\n");
}

void select(kard* A,int N){
  kard num;
  int i,j,minj;
for(i = 0 ; i < N-1;i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j].value < A[minj].value){
	minj = j;
      }
    }
    num = A[minj];
    A[minj] = A[i];
    A[i] = num;       
  }
 for(i = 0 ; i < N;i++){
   if(i) printf(" ");
   printf("%c%d",A[i].mark,A[i].value);
 }
 printf("\n");
}

