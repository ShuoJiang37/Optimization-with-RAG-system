#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define N 1000000
int main(){
  int i, j, k, v, g, cnt=0, m=1, n, A[N], G[N];
 
  scanf("%d",&n);
  if(n > N) exit(1);
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  G[0] = 1;
  while(1){
    G[m] = 3*G[m-1]+1;
    if(G[m] > n || m > 100) break;
    m++;
  }
 
  for(i = m-1; i >= 0; i--){
    g = G[i];
 
    for(j = g; j < n; j++){
      v = A[j];
      k = j - g;
      while(k >= 0 && A[k] > v){
    A[k+g] = A[k];
    k = k - g;
    cnt++;
      }
      A[k+g] = v;
    }
  }
   
  printf("%d\n",m);
  for(i = m-1; i >= 0; i--){
    if(i < m-1) printf(" ");
    printf("%d",G[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i = 0; i < n; i++){
    printf("%d\n",A[i]);
  }
  return 0;
}