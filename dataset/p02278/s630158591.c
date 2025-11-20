#include <stdio.h>
#include <math.h>

#define MAX 1000
#define VMAX 10000

int n,A[MAX],s,B[MAX],T[VMAX+1];

int partition(int A[],int p,int r){
  int i,j,x,t;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i=i+1;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }
  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;
  return i+1;
}

void quicksort(int A[],int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

int solve(){
  int i,S,c,an,ans=0,m,v;
  int V[MAX];

  for(i=0;i<n;i++){
    B[i]=A[i];
    V[i]=0;
  }
  quicksort(B,0,n-1);
  for(i=0;i<n;i++){
    T[B[i]]=i;
  }
  for(i=0;i<n;i++){
    if(V[i])continue;
    c=i;
    S=0;
    m=VMAX;
    an=0;
    while(1){
      V[c]=1;
      an++;
      v=A[c];
      m=fmin(m,v);
      S+=v;
      c=T[v];
      if(V[c])break;
    }
    ans+=fmin(S+(an-2)*m,m+S+(an+1)*s);
  }
  return ans;
}

int main(){
  int i,ans;

  scanf("%d",&n);
  s=VMAX;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    s=fmin(s,A[i]);
  }
  ans=solve();
  printf("%d\n",ans);

  return 0;
}

