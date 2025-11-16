#include<stdio.h>

void insertionSort(int *,int ,int);
void shellSort(int *,int);
int cnt;
int main()
{
  int n,i,A[1000000];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  shellSort(A,n);
  for(i=0;i<n;i++)
    {
      printf("%d\n",A[i]);
    }

  return 0;
}
  void insertionSort(int *A,int n,int g)
  {
    int i,j,v;
    for(i=g;i<n;i++)
      {
	v=A[i];
	j=i-g;
	while(j>=0 && A[j]>v)
	  {
	    A[j+g]=A[j];
	    j=j-g;
	    cnt++;
	  }
	A[j+g]=v;
      }
 
      }

  void shellSort(int *A,int n)
  {
    int m=0,G[n],i;
    G[0]=1;
    
    for(i=0;;i++)
      {	
	if(G[i]>n)break;
	G[i+1]=3*G[i]+1;
	m++;
      }
    printf("%d\n",m);
        for(i=m-1;i>=0;i--)
      {
	printf("%d ",G[i]);
	insertionSort(A,n,G[i]);
      }
    printf("\n%d\n",cnt);

  }