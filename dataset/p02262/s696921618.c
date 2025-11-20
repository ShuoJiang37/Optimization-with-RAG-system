#include<stdio.h>

static const int N = 1000000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf("\n");
    printf("%d", A[i]);
  }
  printf("\n");
}

void trace_rev(int A[], int n){
  int i;
  int start = n -1;
  for ( i = n-1; i >=0; i--){
    if ( i < start ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int cnt = 0;

void insertionSort(int A[], int n, int g) {
  int i, v, j;
  for(i=g;i<n;i++) {
    v = A[i];
    j = i - g;
    while (j >=0 && A[j] > v) {
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
	A[j+g] = v;
  }
}

void shellSort(int A[], int n) {
  int i;
  int m = 1;
  int G[100];
  int nG = 1;
  G[0] = 1;
  
  while ((m = 3 * m + 1) < n) {
    G[nG] = m;
	nG++;
  }
  printf("%d\n", nG);
  trace_rev(G,nG);
  for(i=nG-1;i>=0;i--) {
    insertionSort(A, n, G[i]);
  }
}

int main(){
  int n, i, j;
  int A[N+1];
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  shellSort(A, n);
  printf("%d\n", cnt);
  trace(A, n);
  return 0;
}

