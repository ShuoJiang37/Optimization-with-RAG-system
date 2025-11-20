#include<stdio.h>

void show(int A[],int N){
  for (int i = 0; i < N; i++) {
    printf("%d",A[i] );
    if(i!=N-1)printf(" " );
  }
  printf("\n");
}

int  bubble (int A[],int N){
  int i ,j;
  int c=0;
  j=N-1;
  int sw;
for (int j = 0; j < N-1 ; j++)
  for (i= N-1; j<i; i--) { //これだと二回め以降の繰り返しができていない。
    if(A[i]<A[i-1]){
      sw=A[i-1];
      A[i-1]=A[i];
      A[i]=sw;
      c++;
    }
  }
  show(A,N);
  return c;
}

int main(){
  int A[100];
  int N;
scanf("%d\n",&N);
for (int i = 0; i < N; i++) scanf("%d",&A[i]);
printf("%d\n",bubble(A,N) );
  return 0;
}

