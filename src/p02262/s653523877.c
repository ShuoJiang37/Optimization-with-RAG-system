#include<stdio.h>

int cnt=0,N,A[1000005],i,G[1000005],m=0;
void f(int g)
{
	int i,j,v;
	for(i=g;i<N;i++)
	{
		v=A[i];
		for(j=i-g;j>=0&&A[j]>v;j-=g)
		{
			A[j+g]=A[j];
			cnt++;
		}
		A[j+g]=v;
	}
}

int main()
{
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",A+i);
	for(m=0,G[0]=1;G[m]<=N;G[++m]=G[m-1]*3+1);
	printf("%d\n",m);
	for(i=0;i<m;i++)
	{
		printf("%d%c",G[m-i-1],i==m-1?'\n':' ');
		f(G[m-i-1]);
	}
	printf("%d\n",cnt);
	for(i=0;i<N;i++)printf("%d\n",A[i]);
	return 0;
}