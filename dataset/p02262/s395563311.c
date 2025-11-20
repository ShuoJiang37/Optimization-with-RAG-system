#include<stdio.h>
#include<math.h>

#define N 1000000
#define M 100

int insertionSort(int *,int,int);
int shellSort(int *,int *,int,int);

int main(void){
  int num,cnt,A[N],m,G[M];
  int i;

  G[0] = 1;

  for(i = 1; i < M; i++){
    G[i] = 3*G[i-1] + 1;
  }

  scanf(" %d",&num);

  for(i = 0; i < M; i++){
    if(num < G[i])break;
  }

  m = i;
  
  for(i = 0; i < num; i++){
    scanf(" %d",&A[i]);
  }

  cnt = shellSort(A,G,m,num);

  printf("%d\n",m);
  for(i = m-1; i > 0; i--){
    printf("%d ",G[i]);
  }
  printf("%d\n",G[0]);
  printf("%d\n",cnt);

  for(i = 0; i < num; i++){
    printf("%d\n",A[i]);
  }
  
  
  return 0;
}

int insertionSort(int *A, int num, int g){
  int i,j;
  int v,cnt=0;

  for(i = g; i < num; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }

  return cnt;
}

int shellSort(int *A, int *G, int m, int num){
  int cnt=0;
  int i;

  for(i = m-1; i >= 0; i--){
    cnt += insertionSort(A,num,G[i]);
  }

  return cnt;
}

