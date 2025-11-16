#include <stdio.h>
#include <stdbool.h>

#define M 1000
#define VM 10000

int n,l;
int a[M],b[M],T[VM+1];

int sol(){
  int i,ans=0,an1,cur,s,m,v;
  bool V[M];

  for(i=0;i<n;i++){
    b[i]=a[i];
    V[i]=false;
  }

  asort(b);

  for(i=0;i<n;i++) T[b[i]]=i;
  for(i=0;i<n;i++){
    if(V[i]) continue;
    cur=i;
    s=0;
    m=VM;
    an1=0;
    while(1){
      V[cur]=true;
      an1++;
      v=a[cur];
      m=min(m,v);
      s+=v;
      cur=T[v];
      if(V[cur]) break;
    }
    ans+=min(s+(an1-2)*m,m+s+(an1+1)*l);
  }
  return ans;
}

int min(int a,int b){
  if(a>b) return b;
  else return a;
}
      
void asort(int b[]){
    int i,j,tmp;
    
    for (i=0;i<n;i++) {
    for (j=i+1;j<n;j++) {
      if (b[i]>b[j]) {
        tmp=b[i];
        b[i]=b[j];
        b[j]=tmp;
      }
    }
  }

  }

int main(){
  int i,ans;
  
  scanf("%d",&n);

  l=VM;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    l=min(l,a[i]);
	  }

  ans=sol();
  printf("%d\n",ans);
  
  return 0;
  
}