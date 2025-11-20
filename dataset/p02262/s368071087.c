#include <stdio.h>

int tmp, cnt, j, m, n, a[1000000];

void insertionSort(int a[], int n, int g) {
  for(int i = g; i < n; i++) {
    tmp = a[i];
    j = i-g;
    while(j>=0 && a[j]>tmp) {
      a[j+g]=a[j]; j-=g;
    ++cnt;
    }
    a[j+g]=tmp;
  }
}

void shellSort(int a[], int n) {
  m=0; cnt=0;
  int G[100];
  G[0]=1;
  for(m=1 ; 3*G[m-1]+1 <= n ; m++) G[m] = 3*G[m-1]+1;
  printf("%d\n", m);
  for(int i=m-1; i>=0; --i) {
    printf("%d%c", G[i], " \n"[i==0]);
    insertionSort(a, n, G[i]);
  }
}

int main() {
  int i;
  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", a+i);
  shellSort(a, n);
  printf("%d\n", cnt);
  for(i=0; i<n; i++) printf("%d\n", a[i]);
  return 0;
}



