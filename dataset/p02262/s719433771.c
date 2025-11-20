/*挿入ソート*/
#include <stdio.h>
#include <stdlib.h>
#define N 1000001

void insertionSort(int *, int, int);

int cnt=0;

int main()
{
  int i, j, n, m, x;
  int g[N], A[N];
  
  scanf("%d", &n);
  for (i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  
  g[0] = 1;
  i=1;
  while(1){
    x = 3*g[i-1]+1;
    if (n>x){
      g[i] = x;
      i++;
    }
    else break;
  }
  m = i;

  for (i=m-1; i>=0; i--){
    insertionSort(A, n, g[i]);
  }
  
  /*結果の出力*/
  printf("%d\n", m);

  for (i=m-1;i>=0;i--){
    if(i==0)
      printf("%d\n", g[i]);
    else
      printf("%d ", g[i]);
  }

  printf("%d\n", cnt);

  for (i=0; i<n; i++)
    printf("%d\n", A[i]);
  
  return 0;
}

void insertionSort(int *A, int n, int g){
  int i, j, v;

  for (i=g; i<n; i++){
    v = A[i];
    j = i - g;
    while (j>=0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}

