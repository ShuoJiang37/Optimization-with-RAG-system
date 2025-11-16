#include<stdio.h>
#include<stdlib.h>

int insertionSort(int*, int, int);
void shellSort(int*, int);

int insertionSort(int *A, int n, int g){
  int i, j, v;
  int cnt = 0;

  for(i=g;i<n;i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }

  return cnt;
}

void shellSort(int *A, int n){
  int i, j;
  int cnt = 0;
  int m = 0;
  int *G;

  i = n;
  if(n == 1)  m = 1;
  while(i > 1){
    m++;
    i /= 2;
  }

  G = (int *)malloc(sizeof(int) * m);

  G[0] = n/2;
  for(i=1;i<m;i++){
    G[i] = G[i-1]/2;
  }

  for(i=0;i<m;i++){
    cnt += insertionSort(A, n, G[i]);
  }

  // print
  printf("%d\n",m);
  for(i=0;i<m;i++){
    printf("%d",G[i]);
    if(i != m-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }
}

int main(){
  int i,n;
  int *A;

  scanf("%d",&n);
  A = (int *)malloc(sizeof(int) * n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  shellSort(A, n);

  return 0;
}

