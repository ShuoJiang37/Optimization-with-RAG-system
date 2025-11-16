#include<stdio.h>

#define Max  1000
#define vMax 10000

int n, a[Max], s;
int b[Max], t[vMax + 1];


int partition(int a[], int p, int r){
  int i, j;
  int t, x;
  x = a[r];
  i = p - 1;

  for(j = p ; j < r ; j++){
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
  int i,ans = 0, cur, S, m, an, v;

  int V[Max];
  for(i = 0 ; i < n ; i++){
    b[i] = a[i];
    V[i] = 0;
  }

  quickSort(b, 0, n - 1);

  for(i = 0 ; i < n ; i++) t[b[i]] = i;
  for(i = 0 ; i < n ; i++){
    if(V[i]) continue;
    cur = i;
    S = 0;
    m = vMax;
    an = 0;
    while(1){
      V[cur] = 1;
      an++;
      v = a[cur];

      if(v < m) m = v;

      S += v;
      cur = t[v];
      if(V[cur]) break;
    }
    if(S + (an -2) * m < m + S + (an + 1) * s) ans += S + (an -2) * m;
    else ans +=  m + S + (an + 1) * s;
  }
  return ans;
}


int main(){
  int i;

  scanf("%d", &n);
  s = vMax;
  for(i = 0 ; i < n ; i++){
    scanf("%d", &a[i]);
    if(a[i] < s) s = a[i];
}

  int ans = solve();
  printf("%d\n", ans);

  return 0;
}
