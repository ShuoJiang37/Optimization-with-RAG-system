#include<stdio.h>

#define N 1000
#define M 10000
#define O 0
#define I 1
#define W 2

int n,s,a[N],b[N],T[M+I];


int partition(int a[],int p,int r){
  int i,j,t,x;
  x=a[r];
  i=p-I;
  for(j=p;j<r;j++){
    if(a[j]<=x){
      i++;
      t=a[i];
      a[i]=a[j];
      a[j]=t;
    }
  }
  t=a[i+I];
  a[i+I]=a[r];
  a[r]=t;
  return i+I;
}
void quickSort(int a[],int p,int r){
  int q;
  if(p<r){
    q=partition(a,p,r);
    quickSort(a,p,q-I);
    quickSort(a,q+I,r);
  }
}


int solve(){
  int i,c,S,m,A,v,ans=O;

  int V[N];
  for(i=O;i<n;i++){
    b[i]=a[i];
    V[i]=O;
  }
  quickSort(b,0,n-I);

  for(i=O;i<n;i++){
    T[b[i]]=i;
  }
  for(i=O;i<n;i++){
    if(V[i]){
      continue;
    }
    c=i;
    S=O;
    m=M;
    A=0;
    while(I){
      V[c]=I;
      A++;
      v=a[c];
      if(v<m){
	m=v;
      }
      S+=v;
      c=T[v];
      if(V[c]){
	break;
      }
    }
    if(S+(A-W)*m<m+S+(A+I)*s){
      ans+=S+(A-W)*m;
    }
    else{
      ans+=m+S+(A+I)*s;
    }
  }
  return ans;
}

int main(){
  int i;

  scanf("%d",&n);
  s=M;
  for(i=O;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]<s){
      s=a[i];
    }
  }
  int ans=solve();
  printf("%d\n",ans);
  return O;
}

