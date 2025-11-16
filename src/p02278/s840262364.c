#include<stdio.h>

#define MAX  1000
#define MAX_1 10000


int n, a[MAX], s;
int b[MAX], T[MAX_1 + 1];


int partition(int a[], int p, int r){
  int i, j;
  int t, x;
  x = a[r];
  i = p - 1;

  for( j = p ; j < r ; j++ ){
    if(a[j] <= x){
      i++;
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }

  t = a[i + 1];
  a[i + 1] = a[r];
  a[r] = t;

  return i + 1;
}
void quickS(int a[], int p, int r){
  int q;
  if(p < r){
    q = partition(a, p, r);
    quickS(a, p, q - 1);
    quickS(a, q + 1, r);
  }
}


int solve(){
  int i, c, S, m, an, v,   ans = 0 ;

  int V[MAX];
  for(i = 0 ; i < n ; i++){
    b[i] = a[i];
    V[i] = 0;
  }

  quickS(b, 0, n - 1);

  for(i = 0 ; i < n ; i++) T[b[i]] = i;
  for(i = 0 ; i < n ; i++){
    if(V[i]) continue;
    c = i;
    S = 0;
    m = MAX_1;
    an = 0;
    while(1){
      V[c] = 1;
      an++;
      v = a[c];

      if(v < m) m = v;

      S += v;
      c = T[v];
      if(V[c]) break;
    }
    if(S + (an -2) * m < m + S + (an + 1) * s) ans += S + (an -2) * m;
    else ans +=  m + S + (an + 1) * s;
  }
  return ans;
}



int main(){
  int i;

  scanf("%d", &n);
  s = MAX_1;
  for(i = 0 ; i < n ; i++){
    scanf("%d", &a[i]);
    if(a[i] < s) s = a[i];
  }

  int ans = solve();
  printf("%d\n", ans);

  return 0;
}

