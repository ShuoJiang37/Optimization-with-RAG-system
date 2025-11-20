#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *,int,int);
void shellSort(int *,int);
int cnt, m, *G;

int main()
{
  int n, i, *A; 

  scanf("%d",&n);
  A = (int *)malloc(n * sizeof(int)); 

  for(i = 0 ; i < n ; i++) scanf("%d",&A[i]);

  shellSort(A,n);

  printf("%d\n",m);
  for(i = 0 ; i < m ; i++) printf("%d ",G[i]);
  printf("\n");
  printf("%d\n",cnt);

  for(i = 0 ; i < n ; i++) printf("%d\n",A[i]);

  free(A);
  free(G);
  
  return 0;
}

void insertionSort(int *A,int n,int  g){
  int i, j, v;
  for(i = g ; i <= n-1 ; i++){ 
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
      A[j+g] = v; }
  }
}

void shellSort(int *A,int n){
  int i, h, count = 0;
  
  cnt =0;

  /* Gを作る */
  for(h = 1 ; h <= n ; h = 3 * h + 1) count++;
  m = count;
  G = (int *)malloc(m * sizeof(int));
  G[0] = (h - 1)/3;
  for(i = 1 ; i < m ; i++) G[i] = (G[i-1] - 1)/3;
  
  for(i = 0 ; i <= m-1 ; i++) insertionSort(A,n,G[i]);
  
}
