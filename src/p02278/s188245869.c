#include<stdio.h>
#include<math.h>
#define TRUE 1
#define FALSE 0
#define MAX 1000
#define VMAX 10000

int n, A[MAX], s;
int B[MAX], T[VMAX + 1];

int solve(){
  int i, j, tmp, ans = 0;
  int V[MAX];
  for(i = 0; i < n; i++){
    B[i] = A[i];
    V[i] = FALSE;
  }
  for(i = 0; i < n; ++i){
    for(j = i + 1; j < n; ++j){
      if(B[i] > B[j]){
	tmp = B[i];
	B[i] = B[j];
	B[j] = tmp;
      }
    }
  }
  for(i = 0; i < n; i++) T[B[i]] = i;
  for(i = 0; i < n; i++){
    if(V[i] == TRUE) continue;
    int cur = i;
    int S = 0;
    int m = VMAX;
    int an = 0;
    while(1){
      V[cur] = TRUE;
      an++;
      int v = A[cur];
      m = (int)fmin(m, v);
      S += v;
      cur = T[v];
      if(V[cur] == TRUE) break;
    }
    ans += (int)fmin(S + (an - 2) * m, m + S + (an + 1) * s);
  }

  return ans;
}

int main(){
  int i;
  scanf("%d",&n);
  s = VMAX;
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
    s = (int)fmin(s, A[i]);
  }
  int ans = solve();
  printf("%d\n",ans);

  return 0;
}