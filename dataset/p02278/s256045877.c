#include<stdio.h>
#include<math.h>
#define MAX 1000
#define VMAX 10000
 
int n, A[MAX], s;
int B[MAX], T[VMAX+1];
 
int partition(int A[], int p, int r){
  int i, j;
  int x, t;
  x = A[r];
  i = p-1;
  for( j = p ; j < r ; j++ ){
    if( A[j] <= x ){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;
  return i + 1;
}
 
void quickSort(int A[], int p, int r){
  int q;
  if( p < r ){
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}
 
 
int solve(){
  int i, ans = 0;
 
  int V[MAX];
  for( i = 0 ; i < n ; i++ ){
    B[i] = A[i];
    V[i] = 0;
  }
  quickSort(B, 0, n-1);
  for( i = 0 ; i < n ; i++ ) T[B[i]] = i;
  for( i = 0 ; i < n ; i++ ){
    if( V[i] ) continue;
    int cur = i;
    int S = 0;
    int m = VMAX;
    int an = 0;
    while( 1 ){
      V[cur] = 1;
      an++;
      int v = A[cur];
      m = fmin(m, v);
      S += v;
      cur = T[v];
      if( V[cur] ) break;
    }
    ans += fmin(S+(an-2)*m, m+S+(an+1)*s);
  }
 
  return ans;
}
 
int main(){
  int i;
  scanf("%d",&n);
  s = VMAX;
  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &A[i]);
    s = fmin(s, A[i]);
  }
  int ans = solve();
  printf("%d\n", ans);
 
  return 0;
}

