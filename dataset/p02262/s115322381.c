#include <stdio.h>
int count=0;
int m;
int G[11111];
int A[1000000];
void insertionsort(int A[],int n,int g)
{
	int i,j;
	int v;
	for(i=g;i<n;i++)
	{
	v=A[i];
	 j=i-g;	
		while(j>=0 && A[j]>v)
		{
			A[j+g] =A[j];
			j=j-g;
			count++;
		}
		A[j+g]=v;
	}
}

void shellsort(int A[],int n)
{
	int i;
	G[0]=1;
	for(i=1;;i++)
	{
		G[i]=3*G[i-1]+1;
		if(G[i]>n)
		{
			break;
		}
	
	}
		m=i;
	
	for(i=m-1;i>=0;i--)
	{
		insertionsort(A,n,G[i]);
	}
}

int main(void)
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	shellsort(A,n);
	printf("%d\n",m);
	for(i=m-1;i>=0;i--)
	{
		printf("%d",G[i]);
		printf(" ");
	}
	printf("\n");
	printf("%d\n",count);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
	return 0;
}
