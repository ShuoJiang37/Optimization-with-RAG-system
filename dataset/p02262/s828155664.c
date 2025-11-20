#include<stdio.h>

int main(){
  int n,i,g[1000000],m,a[1000000],v,cnt=0,j,k,maxg=1;
  g[0]=1;
    scanf("%d",&n);
  for(i=0;maxg<n;i++){
    m=i+1;
    maxg=3*maxg+1;
  }
  if(i==0){m=1;}
  for(j=1;j<=m-1;j++){
     g[j]=3*g[j-1]+1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(k=m-1;k>=0;k--){
  for(i=g[k];i<=n-1;i++){
    v=a[i];
    j=i-g[k];
    while(j>=0 && a[j] >v){
      a[j+g[k]]=a[j];
      j=j-g[k];
      cnt++;
      a[j+g[k]]=v;
    }
  }
  }
  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
    if(i==0)printf("%d\n",g[i]);
    else printf("%d ",g[i]);
  }
  printf("%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
  return 0;
}
    

