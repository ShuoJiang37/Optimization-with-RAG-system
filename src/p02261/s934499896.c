#include <stdio.h>
#define true 1
#define false 0
#define N 100
int judge(char *,char *,int kei);
    int main()
{
  int kei,i,j,k[N],g[N],t,m,mini,minim,r,h,w;
  char s,a[N],n[N];
  scanf("%d",&kei);
  for(i=0;i<kei;i++){
    scanf(" %c%d",&a[i],&k[i]);
  }
  for(i=0;i<kei;i++)
    {
    n[i]=a[i];
    g[i]=k[i];
  }
  for(i=0;i<kei;i++)
    {
    for(j=kei-1;j>i;--j){
      if(k[j]<k[j-1]){
	m=a[j-1];
	t=k[j-1];
	a[j-1]=a[j];
	k[j-1]=k[j];
	a[j]=m;
	k[j]=t;
	
      }
    }
  }
  
  for(i=0;i<kei-1;i++)
    {
    mini=g[i];
    minim=n[i];
    r=i;
    for(j=i+1;j<kei;j++)
      {
	if(g[j]<mini)
	  {
      mini=g[j];
    minim=n[j];
    r=j;
	}
      }
      if(i != r){
	h=g[i];
	w=n[i];
	g[i]=g[r];
	n[i]=n[r];
	g[r]=h;
	n[r]=w;
      }
    }
  
  for(i=0;i<kei;++i){
    if(i>0)printf(" ");
    printf("%c%d",a[i],k[i]);
  }
  printf("\n");
  printf("Stable\n");
  for(i=0;i<kei;++i)
    {
    if(i>0)printf(" ");
    printf("%c%d",n[i],g[i]);
  }
  printf("\n");
  if(judge(a,n,kei)==1)printf("Stable\n");
  else printf("Not stable\n");
    return 0;
}

int judge(char x[],char y[],int kei)
{
  int i;
  for(i=0;i<kei;i++)
    {
      if(x[i] != y[i])return false;
    }
  return true;
}
  

