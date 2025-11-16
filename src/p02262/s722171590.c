#include<stdio.h>

long long count;


void insertionSort(int n,int A[n],int g)
{
	int v;
	int j;
	for(int i=g;i<n;i++)
	{
		v = A[i];
		j = i-g;
		while(j>=0&&A[j]>v)
		{
			A[j+g]=A[j];
			j= j-g;
			A[j+g]=v;
			count++;
		}
	}
}
void shellSort(int n,int A[n])
{
	int m=0;
	int g[n];
	for(int h=1;;)
	{
		if(h>n)break;
		g[m]=h;
		m++;
		h=3*h+1;
	}
	printf("%d\n",m);
	printf("%d",g[m-1]);
	for(int i=m-2;i>=0;i--)
	{
		printf(" %d",g[i]);
	}
	printf("\n");
	count=0;
	for(int i=m-1;i>=0;i--)
	{
		insertionSort(n,A,g[i]);
	}
	printf("%d\n",count);

}
int main(void)
{
  int n;
  scanf("%d",&n);
	int a[n];
	count=0;

	for(int i=0;i<n;i++)
	{
    	scanf("%d",&a[i]);
	}
	int count =0;
	shellSort(n,a);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}

  return 0;
}

