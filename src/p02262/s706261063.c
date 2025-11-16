#include <stdio.h>

void insertion(int [], int, int);

int cnt = 0;

int main(){
  int i, n, m = 10, A[1000000], G[] = {10000, 5000, 2500, 1000, 500, 100, 50, 10, 4, 1}, m_cnt = 0;

  scanf("%d", &n);

  for(i=0; i<n; i++) scanf("%d", &A[i]);

  for(i=0; i<m; i++)
    if(G[i] <= n){
      insertion(A, n, G[i]);
      m_cnt++;
    }

  printf("%d\n", m_cnt);
  for(i=0; i<m-1; i++) if(G[i] <= n) printf("%d ", G[i]);
  printf("%d\n%d\n", G[i], cnt);

  for(i=0; i<n; i++) printf("%d\n", A[i]);
  
  return 0;
}

void insertion(int A[], int n, int g){
  int i, j, v;

  for(i=g; i<n; i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}