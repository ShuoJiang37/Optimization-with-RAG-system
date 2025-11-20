#include<stdio.h>

#define MAX 1000
#define VMAX 10000

int A[MAX],B[MAX],T[VMAX+1];
int n,s;
int merge(int A[],int left,int mid,int right)
{
	int L[500000],R[500000];
	int n1,n2,i,j,k;
	n1=mid-left;
	n2=right-mid;
	for(i=0;i<n1;i++)
	{
		L[i]=A[left+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=A[mid+i];
	}
	L[n1]=999999999;
	R[n2]=999999999;
	i=0;
	j=0;
	for(k=left;k<right;k++)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i=i+1;
		}
		else
		{
			A[k]=R[j];
			j=j+1;
		
		}
	}
}
int mergesort(int A[],int left,int right)
{
	int mid;
	if(left+1<right)
	{
		mid=(left+right)/2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A,left,mid,right);
	}
	else
	{
		return 0;
	}
}
int min(int a,int b)
{
	if(a<=b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}

int solve()
{
	int V[MAX];
	int result=0;
	int i;
	for(i=0;i<n;i++)
	{
		B[i]=A[i];
		V[i]=0;
	}
	mergesort(B,0,n);
	for(i=0;i<n;i++)
	{
		T[B[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		if(V[i])
		{
			continue;
		}
		int cur=i;
		int S=0;
		int m=VMAX;
		int a=0;
		while(1)
		{
			V[cur]=1;
			a++;
			int v=A[cur];
			m=min(m,v);
			S+=v;
			cur=T[v];
			if(V[cur])
			{
				break;
			}
		}
		result+=min(S+(a-2)*m,m+S+(a+1)*s);
	}
	return result;
}
int main(void)
{	
	int i;
	s=VMAX;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		s=min(s,A[i]);
	}
	int result=solve();
	
	printf("%d\n",result);
	
	return 0;
}
	
