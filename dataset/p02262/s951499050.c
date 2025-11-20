#include<stdio.h>
#include<math.h>
#define MAX 1000000
int count=0;
int S[MAX];
int n,k,l;
int G[MAX];
int Glen=0;

void insertSort()
{
  int i,j;
  int u;
  for(i=0;i<Glen;i++)
    {
      for(j=G[i];j<n;j++)
	{
	  u=S[j];
	  l=j-G[i];
	  while(l>=0 &&S[l]>u)
	    {
	      S[l+G[i]]=S[l];
	      l=l-G[i];
	      count++;
	    }
	  S[l+G[i]]=u;
	}
    }
}
void shellSort(int S[],int n)
{
  int i,j;
  int t;
  for(i=1;G[i-1]<=n;i++)
    {
      Glen++;
      G[i]=3*G[i-1]+1;
      if(Glen>100)break;
    }

  for(i=0;i<Glen/2;i++)
    {
      t=G[i];
      G[i]=G[Glen-i-1];
      G[Glen-i-1]=t;
    }
  insertSort();
}

int main()
{
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  G[0]=1;
  shellSort(S,n);
  printf("%d\n",Glen);
  for(i=0;i<Glen;i++)
    {
      printf("%d ",G[i]);
    }
  printf("\n");
  printf("%d\n",count);
  for(i=0;i<n;i++)printf("%d\n",S[i]);
  return 0;
}