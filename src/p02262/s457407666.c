#include <stdio.h>

void insertionSort(int *, int, int);
int shellSort(int *, int);

int cnt = 0;
int G[100];

int main() {
  int i;
  int a[1000000];
  int n, m;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  m = shellSort(a, n);

  printf("%d\n", m);
  for(i = m - 1; i >= 0; i--) {
    printf("%d", G[i]);
    if(i > 0) printf(" ");
  }
  printf("\n");
  printf("%d\n", cnt);
  
  for(i = 0; i < n; i++)
    printf("%d\n", a[i]);
  
  return 0;
}

void insertionSort(int *A, int n, int g) {
  int i, j, key;

  for(i = g; i < n; i++) {
    key = A[i];
    j = i - g;
    while(j >= 0 && A[j] > key) {
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = key;
  }
}

int shellSort(int *A, int n) {
  int i, r;

  G[0] = 1;
  for(i = 1; ; i++) {
    if(G[i-1] > n) break;
    G[i] = 3 * G[i-1] + 1;
  }
  
  r = i - 1;

  for(i = r; i >= 0; i--) {
    insertionSort(A, n, G[i]);
  }

  return r;

}