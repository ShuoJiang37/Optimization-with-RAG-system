#include<stdio.h>
#define MAX 1000
#define N 10000

int n,s;
int a[MAX],b[MAX],T[N+1];
int partition(int a[],int p,int r);
void quickSort(int a[], int p, int r);
int partition(int a[], int p, int r);
int solve();

int main(){
  int i;
  int result;
  scanf("%d",&n);
  s = N;
  for(i = 0 ; i<n; i++){
    scanf("%d",&a[i]);
    if(a[i] < s){
      s = a[i];
    }
  }
    result = solve();
    printf("%d\n",result);
    return 0;
  }

int partition(int a[], int p, int r){
  int i, j,t,k;
  k = a[r];
  i = p-1;
  for(j = p ;j< r; j++ ){
    if(a[j] <= k){
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
    quickSort(a, p,q-1);
    quickSort(a, q + 1, r);
  }
}

int solve(){
  int i, cur;
  int S,v,m,a1;
  int result = 0;
  int V[MAX];
  for(i = 0 ; i< n; i++){
    b[i] = a[i];
    V[i] = 0;
	 }
  quickSort(b,0,n-1);

  for(i = 0; i<n; i++){
    T[b[i]] = i;
  }
  for(i = 0; i<n;i++){
    if(V[i]) continue;
    cur = i;
    S = 0;
    m = N;
    a1= 0;
    while(1){
      V[cur] = 1;
      a1++;
      v = a[cur];
      if(v < m) {
	m = v;
	  }
      S += v;
    cur = T[v];
    if(V[cur]) break;
  }

  if(S + (a1 -2)*m<m + S + (a1 +1) *s) {
    result += S + (a1 -2) * m;
  }
  
  else{
    result += m + S + (a1 +1) *s;
  }
  }
  return result;
}



