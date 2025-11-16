#include<stdio.h>

#define N 1000000

int a[N], G[N], count = 0, m = 1;

void insertionSort(int n, int g){
  int i, j, v;
  for(i = g ; i < n ; i++){
    v = a[i];
    j = i - g;

    while(j >= 0 && a[j] > v){
      a[j + g] = a[j];
      j = j - g;
      count++;
    }
    a[j + g] = v;
  }
}


void shellSort(int n){
  int i, h = n;
  G[0] = 1;

  while(1){
    G[m] = G[m - 1]*3 + 1;
    if(G[m] > n) break;
    m++;
  }

  for(i = m - 1 ; i >= 0 ; i--){
    insertionSort(n, G[i]);
  }
}


int main(){
  int i, n;

  scanf("%d", &n);
  for(i = 0 ; i < n ; i++) scanf("%d", &a[i]);

  shellSort(n);

  printf("%d\n", m);
  for(i = m - 1 ; i > 0 ; i--) printf("%d ", G[i]);

  printf("%d\n", G[0]);

  printf("%d\n", count);

  for(i = 0 ; i < n ; i++) printf("%d\n", a[i]);

  return 0;
}
