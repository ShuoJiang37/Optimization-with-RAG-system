#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
  if(n == 1)  m =1;
  while(i > 1){
    m++;
    i /= 2;
  }

  G = (int *)malloc(sizeof(int) * m);
  /*if(n % 2){
    G[0] = n-1;
    for(i=1;i<m;i++){
      for(j=G[i-1];j>0;j--){
        if(n%j == 0){
          G[i] = j;
          break;
        }
      }
    }
  } else {*/
    G[0] = n/2;
    for(i=1;i<m;i++){
      G[i] = G[i-1]/2;
    }
  //}

  // print
  printf("%d\n",m);
  for(i=0;i<m;i++){
    printf("%d",G[i]);
    if(i != m-1) printf(" ");
    else printf("\n");
  }

  for(i=0;i<m;i++){
    cnt += insertionSort(A, n, G[i]);
  }
  printf("%d\n",cnt);
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

  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }

  return 0;
}

