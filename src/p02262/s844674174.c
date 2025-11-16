#include<stdio.h>
#include<stdlib.h>
int cnt;

void swap(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
 
}


void insertionSort(int *A, int N, int g)
{
  int i,j;
  int v;
  for(i=g; i<N; i++) {
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;

    //    for(j=0; j<N-1; j++)
    //      printf("%d ", A[j]);
    //    printf("%d\n", A[N-1]);
  }
}

void shellSort(int *A, int n, int *G, int m)
{
  int cnt = 0, i;
  for (i = m-1; i>=0; i--) {
    insertionSort(A, n, G[i]);
  }
}

int main(void)
{
  int *A, N, i;
  int m = 2;
  int G[100];
  
  scanf("%d",&N);
  A = (int *) calloc(N, sizeof(int));
  
  for(i=0;i<N;i++) {
    scanf("%d", &A[i]); //配列読み込み
  }    

  G[0] = 1;
  for (m = 1; G[m-1] <= N; m++){
    G[m] = 3*G[m-1]+1;
  }
  m -= 1;
    
  cnt = 0;
  shellSort(A, N, G, m);

  // m を出力
  printf("%d\n", m);
  // G を出力
  for(i=m-1; i>0; i--)
    printf("%d ", G[i]);
  printf("%d\n", G[0]);
  // cnt を出力
  printf("%d\n", cnt);

  // A を出力
  for(i=0; i<N; i++){
    printf("%d\n", A[i]);
  }

  return 0;
}

  

