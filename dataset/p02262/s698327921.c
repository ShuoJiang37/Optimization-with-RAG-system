#include <stdio.h>

int cnt;

void insertionSort(int A[], int n, int g) {
  int v, i, j;

  for(i = g; i < n; i++) {
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j =j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[], int n) {
  int m = 0, G[100], i;

  G[0] = 1;
  for(m = 1; 3*G[m-1]+1 <= n; m++){
    G[m] = 3*G[m-1]+1;
  }

  printf("%d\n", m);

  for(i = m - 1; i >= 0; i--) {

    printf("%d ", G[i]);
    if(i == 0){
      printf(" \n");
    }

    insertionSort(A, n, G[i]);
  }
}

int main() {
  int n, i;

  scanf("%d", &n);

  int A[n];

  for(i = 0; i < n; i++){
    scanf("%d", A+i);
  }
  shellSort(A, n);
  printf("%d\n", cnt);

  for(i = 0; i < n; i++){
    printf("%d\n", A[i]);
  }
  return 0;
}

