#include<stdio.h>
#define GSIZE 100

void insertionSort(int *, int, int);
int shellSort(int *, int);

int cnt = 0;
int g[GSIZE];

int main(){
  int n, m;
  int i;

  scanf("%d", &n);

  int a[n];

  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }

  m = shellSort(a, n);

  printf("%d\n", m);
  for(i=m-1;i>=0;i--){
    if(i == 0) printf("%d\n", g[i]);
    else printf("%d ", g[i]);
  }
  printf("%d\n", cnt);
  for(i=0;i<n;i++){
    printf("%d\n", a[i]);
  }
  return 0;
}

void insertionSort(int *a, int n, int g){
  int v;
  int i, j;

  for(i=g;i<n;i++){
    v = a[i];
    j = i - g;
    while(j >= 0 && a[j] > v){
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = v;
  }
}

int shellSort(int *a, int n){
  int i = 0, j;
  
  g[0] = 1;
  while(g[i] < n){
    i++;
    g[i] = 3 * g[i-1] + 1;
  }
  //printf("%d\n", i);
  //ここの時点でg[i] >= n
  //i+1がgの要素数

  //ループ1回も回らなかったらiおかしくなる
  if(i == 0) i++;
  
  //g[i]はnを超えてるから含めない
  for(j=i-1;j>=0;j--){
    insertionSort(a, n, g[j]);
  }

  return i;
}

