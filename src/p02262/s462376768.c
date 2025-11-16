#include<stdio.h>
#define N 1000000
int main()
{
  int n,i,j,k,v,cnt=0,m=0,A[N],G[N];


  scanf("%d",&n);
   
  for(i = 0;i < n;i++)
    scanf("%d",&A[i]);
   
  G[0]=1;
  for(i = 1;G[i-1] <= n;i++)
  {
    m++;
    G[i]=G[i-1]*3+1;
    if(m>100)break;
  }

  for(i = m-1;i >= 0;i--)
  {
    for(j = G[i];j < n;j++)
    {
      v = A[j];
      k = j - G[i];
      while(k >= 0 && A[k] > v)
      {
        A[k+G[i]] = A[k];
        k -= G[i];
        cnt++;
      }
      A[k+G[i]] = v;
    }
  }
   
  printf("%d\n",m);
  for(i = m - 1;i > 0 ;i--)
    printf("%d ",G[i]);

  printf("%d\n%d\n",G[i],cnt);

  for(i = 0;i < n;i++)
    printf("%d\n",A[i]);

  return 0;
}
   
