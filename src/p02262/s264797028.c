#include<stdio.h>

int n,cnt=0;
void sort(int a[],int g)
{
	int i,j,v;
	for(i=g+1;i<n+1;i++)
	{
		v=a[i];
		j=i-g;
		while(j>=1&&a[j]>v)
		{
			a[j+g]=a[j];
			j-=g;
			cnt++;
		}
		a[j+g]=v;
	}
}



int main()
{
	int i,head=1;
	int G[500];
	
	scanf("%d",&n);
	int A[n];
	G[1]=1;
	
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&A[i]);
	}
	
	while(G[head]*3+1<n)
	{
		head++;
	G[head]=G[head-1]*3+1;
	}
	for(i=head;i>=1;i--)
	{
		sort(A,G[i]);
	}
	printf("%d\n",head);
	for(i=head;i>=1;i--)
	{
		printf("%d ",G[i]);
	}
	printf("\n");
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
	{
		printf("%d\n",A[i]);
	}
	return 0;
}
