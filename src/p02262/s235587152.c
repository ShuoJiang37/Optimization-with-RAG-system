#include <stdio.h>

int cnt;

void insertionSort(int A[], int n, int g);
void shellSort(int A[], int n);

int n;
int A[1000000];

int main() {
  int i;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) scanf("%d", A+i);
  shellSort(A, n);
  printf("%d\n", cnt);
  for(i = 0; i < n; ++i) printf("%d\n", A[i]);
  return 0;
}

void insertionSort(int A[], int n, int g) {
  int tmp;
  int i, j;
  for(i = g; i < n; ++i) {
    tmp = A[i];
    j = i-g;
    while(j >= 0 && A[j] > tmp) {
      A[j+g] = A[j];
      j -= g;
      ++cnt;
    }
    A[j+g] = tmp;
  }
}

void shellSort(int A[], int n) {
  int m = 0;
  int G[100];
  int i;
  G[0] = 1;
  for(m = 1; 3*G[m-1]+1 <= n; ++m) G[m] = 3*G[m-1]+1;
  printf("%d\n", m);
  cnt = 0;
  for(i = m-1; i >= 0; --i) {
    printf("%d%c", G[i], " \n"[i==0]);
    insertionSort(A, n, G[i]);
  }
}


