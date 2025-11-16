#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000
#define VMAX 10000
int n,A[MAX],s;
int B[MAX], T[VMAX+1];
 
void swap(int *a,int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void qsort(int X[], int left, int right){
  int i,j;
  int pivot;
  i=left;j=right;
  pivot = X[(left+right)/2];
 
  while(1) {
    while(X[i]<pivot)i++;
    while(pivot<X[j])j--;
    if(i>=j) break;
 
    swap(&X[i],&X[j]);
    i++;  j--;
  }
  if(left < i-1) qsort(X,left,i-1);
  if(j+1<right) qsort(X,j+1,right);
}
int solve() {
  int i;
  int ans = 0;
 
  bool V[MAX];
  for(i=0;i<n;i++){
    B[i] = A[i];
    V[i]=false;
  }
  qsort(B,0,n-1);
  for(i=0;i<n;i++) T[B[i]] = i;
  for(i=0;i<n;i++) {
    if(V[i]) continue;
    int cur=i;
    int S=0;
    int m=VMAX;
    int an=0;
    while(1) {
      V[cur] = true;
      an++;
      int v = A[cur];
      m = fmin(m,v);
      S+=v;
      cur=T[v];
      if(V[cur])break;
    }
    ans+=fmin(S+(an - 2) * m , m+S+(an+1)*s);
 
  }
  return ans;
}
int main(){
  int i;
  scanf("%d",&n);
  s=VMAX;
  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
    s=fmin(s , A[i]);
  }
  int ans = solve();
  printf("%d\n", ans);
 
  return 0;
}