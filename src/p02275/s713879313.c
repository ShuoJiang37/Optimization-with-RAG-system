#include<stdio.h>
#define N 100001
int i,n,in[2000001],tmp[N],out[2000001];
int main()
{
  scanf("%d",&n);
  for(i=1;i<n+1;i++){
    scanf("%d",&in[i]);
  }
  for(i=0;i<N;i++) tmp[i]=0;
  for(i=1;i<n+1;i++)tmp[in[i]]+=1;
  for(i=0;i<N;i++)  tmp[i]+=tmp[i-1];
  for(i=n+1;i>0;i--){
    out[tmp[in[i]]]=in[i];
    tmp[in[i]]-=1;
  }
  for(i=1;i<n;i++){
    printf("%d ",out[i]);
  }
  printf("%d\n",out[i]);
  return 0;
}

