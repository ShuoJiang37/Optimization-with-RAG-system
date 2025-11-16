#include <stdio.h>

#define MAX_N 2000000
#define MAX_M 10000
#define max(a,b) ((a) < (b) ? (b) : (a))

void Counting_Sort(int*, int, int);

int ans[MAX_N];

int main(){
  int a[MAX_N], n, i, k = 0;

  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d" , a + i);
    k = max(k ,a[i]);
  }
  Counting_Sort(a, k+1, n);

  return 0;
}

void Counting_Sort(int a[], int k, int n){
  int i, C[MAX_M];

  for(i = 0 ; i < k ; i++){
    C[i] = 0;
  }

  for(i = 0 ; i < n ; i++){
    C[a[i]]++;
  }

  for(i = 0 ; i < k ; i++){
    C[i] += C[i-1];
  }
  for(i = n-1 ; i >= 0 ; i--){
    ans[C[a[i]]-1] = a[i];
    C[a[i]]--;
  }

  for(i = 0 ; i < n ; i++){
    printf("%d%c" , ans[i], i != n-1 ?  ' ' : '\n');
  }
}