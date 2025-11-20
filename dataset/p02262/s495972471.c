#include<stdio.h>

int cnt;

int insertionSort(int A[],int n,int g)
{
	int i,j;
	int v;
	
	for(i=g;i<n;i++)
	{
		v=A[i];
		j=i-g;
		while(j>=0&&A[j]>v)
		{
			A[j+g]=A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
	return cnt;
}

void shellSort(int A[], int n)
{
	int i;
	int h=1,m=0;
	int Gt[1000];
	int G[1000];
	
	for(i=0;;i++)
	{
		if(h>n)
		{
			m=i-1;
			break;
		}
		if(i==0)
		{
			h=3*i+1;
		}
		else
		{
			h=3*h+1;
		}
		
		Gt[i]=h;
	}
	printf("%d\n",m);
	
	for(i=0;i<m;i++)
	{
		G[i]=Gt[m-1-i];
	}
	
	for(i=0;i<m;i++)
	{
		if(i!=0){printf(" ");}
		printf("%d",G[i]);
	}printf("\n");
	
	for(i=0;i<m;i++)
	{
		cnt=insertionSort(A,n,G[i]);
	}
	printf("%d\n",cnt);
}

int main(void)
{
	int i;
	int n;
	
	scanf("%d",&n);
	
	int A[n];
	
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
