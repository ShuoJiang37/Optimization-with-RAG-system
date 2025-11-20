#include<stdio.h>
#include<stdlib.h>

int insertionSort(int *A,int n,int g){
  int v, i, j, cnt=0;
  for(i=g; i<=n-1; i++){
    v = A[i];
    j = i - g;
    while(j>=0 && A[j]>v){
      A[j+g] = A[j];
      j = j-g;
      cnt++;
    }
    A[j+g] = v;
  }
  return cnt;
}

int main(){

  int *A, N, i, *G, cnt, m, j;

  scanf("%d",&N);
  A = (int *)malloc(sizeof(int)*N);
  for(i=0; i<=N-1; i++){
    scanf("%d",&A[i]);
  }

  //shellSort(A, n)
  cnt = 0;
  m = N/2;
  if(m > 100) m = 100;
  else if(0 >= m) m = 1;
  G = (int *)malloc(sizeof(int)*m);
  j = N/2;
  for(i=0; i<=m-1; i++){
    if(j <1) j = 1;  
    G[i] = j;
    j = j / 2;
  }

  for(i=0; i<=m-1; i++){
    cnt += insertionSort(A, N, G[i]);
  }

  printf("%d\n",m);
  printf("%d",G[0]);
  for(i=1; i<=m-1; i++){
  printf(" %d",G[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0; i<=N-1; i++){
    printf("%d\n",A[i]);
  }

  return 0;
}
