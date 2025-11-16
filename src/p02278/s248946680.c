#include<stdio.h>
#define MAX 1000
#define VMAX 10000
#define TRUE 1
#define FALSE 0
 
int n,A[MAX],s;
int B[MAX],T[VMAX+1];
void sort(){
  int j,i,v;
  for(i=1;i<n;i++){
    v=B[i];
    j=i-1;
    while(j>=0 && B[j]>v){
      B[j+1]=B[j];
      j--;
    }
    B[j+1]=v;
  }
}
int smini(int x,int y){
  if(x>y)return y;
  else return x;
}
int solve(){
  int ans=0,V[MAX],i;
  int cur,S,m,an,v;
  for(i=0;i<n;i++){
    B[i]=A[i];
    V[i]=FALSE; // 0
  }
  sort();
  for(i=0;i<n;i++)T[B[i]]=i;
  for(i=0;i<n;i++){
    if(V[i])continue;
    cur=i;
    S=0;
    m=VMAX;
    an=0;
    while(1){
      V[cur]=TRUE;
      an++;
      v=A[cur];
      m=smini(m,v);
      S+=v;
      cur=T[v];
      if(V[cur])break;
    }
    ans+=smini(S+(an-2)*m,m+S+(an+1)*s);
}
  return ans;
}



int main(){
  int i,ans;
  scanf("%d",&n);
  s=VMAX;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    s=smini(s,A[i]);//minimam
}
  ans=solve();
  printf("%d\n",ans);

  return 0;
}