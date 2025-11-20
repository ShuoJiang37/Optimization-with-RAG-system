#include<stdio.h>
#define N 1000000

int main(){
  int n,i,j,k,l,x,c=0,m=0;
  int a[N],g[N];

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&a[i]);

  g[0]=1;
  for(i=1;g[i-1]<=n;i++){
    m++;
    g[i]=g[i-1]*3+1;
    if(m>100)break;
  }

  for(i=0;i<m/2;i++){
    x=g[i];
    g[i]=g[m-i-1];
    g[m-i-1]=x;
  }

  for(i=0;i<m;i++){
    for(j=g[i];j<n;j++){
      l=a[j];
      k=j-g[i];

      while(k>=0 && a[k]>l){
	a[k+g[i]]=a[k];
	k=k-g[i];
	c++;
      }
      a[k+g[i]]=l;
    }
  }

  printf("\n%d\n",m);
  for(i=0;i<m;i++){
    printf("%d ",g[i]);
    
  }
  printf("\n%d\n",c);

  for(i=0;i<n;i++)printf("%d\n",a[i]);

  return 0;
}

