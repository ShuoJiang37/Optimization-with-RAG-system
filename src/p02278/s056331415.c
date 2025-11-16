#include <stdio.h>
#include <stdbool.h>
#define true 1
#define false 0
#define MAX 1000
#define VMAX 10000

int n,A[MAX],s;
int B[MAX],T[VMAX+1];

void sort(int C[])
{
	
	int tmp;
	int flag = 1;
	while(flag == 1)
	{
		flag = 0;
		for( int j = n-1; j >= 1; j--)
		{
			if(C[j] < C[j-1])
			{
				tmp = C[j];
				C[j] = C[j-1];
				C[j-1] = tmp;
				flag = 1;
			}
		}
	}
}

int min(int a , int b)
{
	if(a < b) return a;
	else return b;
}

int solve()
{
	int ans = 0;
	
	bool V[MAX];
	for( int i = 0; i < n; i++)
	{
		B[i] = A[i];
		V[i] = false;
	}
	sort(B);
	for( int i = 0; i < n; i++) T[B[i]] = i;
	for( int i = 0; i < n; i++) 
	{
		if(V[i])continue;
		int cur = i;
		int S = 0;
		int m = VMAX;
		int count = 0;
		while(1)
		{
			V[cur] = true;
			count++;
			int v = A[cur];
			m = min(m,v);
			S += v;
			cur = T[v];
			if(V[cur])break;
		}
		ans += min(S+(count-2)*m,m+S+(count+1)*s);
	}
	return ans;
}

int main(void)
{
	scanf("%d",&n);
	s = VMAX;
	for( int i = 0; i < n; i++)
	{
		scanf("%d",&A[i]);
		s = min(s,A[i]);
	}
	int ans = solve();
	printf("%d\n",ans);
}

