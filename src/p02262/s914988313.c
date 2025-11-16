#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9 + 7
#define endl printf("\n")
typedef long long ll;

void insertionSort(int *a, int n, int g, int *cnt){
  for(int i = g; i < n; i++){
    int v = a[i];
    int j = i - g;
    while(j >= 0 && a[j] > v){
      a[j + g] = a[j];
      j -= g;
      (*cnt)++;
    }
    a[j + g] = v;
  }
  return;
}

void shellSort(int *a, int n){
  int cnt = 0;
  int g[100] = {};
  int k = 0; g[0] = 1;
  
  while(1){
    if(g[k] <= n && 3 * g[k] + 1 > n){
      k++;
      break;
    }
    g[k + 1] = 3 * g[k] + 1;
    k++;
  }

  printf("%d\n", k);
  for(int i = 0; i < k - 1; i++) printf("%d ", g[k - 1 - i]);
  printf("1\n");

  for(int i = 0; i < k; i++){
    insertionSort(a, n, g[k - 1 - i], &cnt);
  }
  printf("%d\n", cnt);
  return;
}

int
main(int argc, char *argv[])
{
  int n, a[1000000];
  scanf("%d", &n);
  rep(i, n) scanf("%d", &a[i]);

  shellSort(a, n);
  rep(i, n) printf("%d\n", a[i]);
  return 0;
}
  

