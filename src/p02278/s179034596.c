#include<stdio.h>

#define MAX1  1000
#define MAX2 10000


int n, a[MAX1], s;
int b[MAX1], T[MAX2 + 1];


int partition(int [], int , int );
void quickSort(int [], int , int );
int solve();
 

int main(){
  int i;

  scanf("%d", &n);
  s = MAX2;
  for(i = 0 ; i < n ; i++){
    scanf("%d", &a[i]);
    if(a[i] < s) s = a[i];
  }

  int ans = solve();
  printf("%d\n", ans);

  return 0;
}

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
void quickSort(int a[], int p, int r){
  int q;
  if(p < r){
    q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
}


int solve(){
  int i, cur, S, m, an, v,   ans = 0 ;

  int V[MAX1];
  for(i = 0 ; i < n ; i++){
    b[i] = a[i];
    V[i] = 0;
  }

  quickSort(b, 0, n - 1);

  for(i = 0 ; i < n ; i++) T[b[i]] = i;
  for(i = 0 ; i < n ; i++){
    if(V[i]) continue;
    cur = i;
    S = 0;
    m = MAX2;
    an = 0;
    while(1){
      V[cur] = 1;
      an++;
      v = a[cur];

      if(v < m) m = v;

      S += v;
      cur = T[v];
      if(V[cur]) break;
    }
    if(S + (an -2) * m < m + S + (an + 1) * s) ans += S + (an -2) * m;
    else ans +=  m + S + (an + 1) * s;
  }
  return ans;
}



