#include <stdio.h>
int n, cnt;
int A[1000000];

void shellSort(); 
void insertionSort(int);

int main() {  
  int i;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", A+i);
  }
  shellSort();
  return 0;
}

void insertionSort(int g) { 
  int v;
  int i, j;
  for(i = g; i < n; i++) {
    v = A[i];
    j = i-g;

    while(j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}
void shellSort() {
  
  int G[100];
  int m = 0, g = 0;
  int i;
  
  while(3 * g + 1 <= n) {
    g = 3 * g + 1;
    G[m++] = g;

  }
  
  printf("%d\n", m);
  for(i = m - 1; i >= 0; i--) {

    if(i < m - 1) printf(" ");
    printf("%d", G[i]);
    insertionSort(G[i]);
  }

  puts("");
  printf("%d\n", cnt);

  for(i = 0; i < n; i++){
    printf("%d\n", A[i]);
  }
}