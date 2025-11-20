#include <stdio.h>
#include <math.h>
#define MAX 1000
#define WEIGHT 10000

int n,A[MAX],s,B[MAX],T[WEIGHT+1];

int partition(int A[],int p,int r){
  int i,j,m,k;
  m=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j]<=m){
      i=i+1;
      k=A[i];
      A[i]=A[j];
      A[j]=k;
    }
  }
  k=A[i+1];
  A[i+1]=A[r];
  A[r]=k;
  return i+1;
}

void quickSort(int A[],int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int solve(){
  int i,S,c,an,a=0,m,v;
  int W[MAX];

  for(i=0;i<n;i++){
    B[i]=A[i];
    W[i]=0;
  }
  quickSort(B,0,n-1);
  for(i=0;i<n;i++){
    T[B[i]]=i;
  }
  for(i=0;i<n;i++){
    if(W[i])continue;
    c=i;
    S=0;
    m=WEIGHT;
    an=0;
    while(1){
      W[c]=1;
      an++;
      v=A[c];
      m=fmin(m,v);
      S+=v;
      c=T[v];
      if(W[c])break;
    }
    a+=fmin(S+(an-2)*m,m+S+(an+1)*s);
  }
  return a;
}

int main(){
  int i,a;

  scanf("%d",&n);
  s=WEIGHT;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    s=fmin(s,A[i]);
  }
  a=solve();
  printf("%d\n",a);

  return 0;
}

