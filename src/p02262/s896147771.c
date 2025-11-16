#include<stdio.h>
int main()
{
  int n,i=0,j,g,cnt=0,k,h;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  cnt=0;
  int m=0;
  int G[10]={0};
  for(i=0;i<n;i++){
    if(i==0){G[0]=1; m++; continue;}
    g=(3*G[i-1]+1);
    if(g>n)break;
    G[i]=g;
    m++;
    }
  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
  printf("%d",G[i]);
  if(i!=0)printf(" ");
  }
  for(h=m-1;h>=0;h--){
    for(i=G[h];i<n;i++){
      int v=a[i];
      j=i-G[h];
      while(j>=0 && a[j]>v){
        a[j+G[h]]=a[j];
        j=j-G[h];
        cnt++;
      }
      a[j+G[h]]=v;
    }
  }
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
  return 0;
}
