#include <stdio.h>

void insertionSort(int A[], int n, int g);
void shellSort(int A[], int n);

static int cnt;

int main(void)
{
	int n, i;
	
	scanf("%d", &n);
	
	int A[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	shellSort(A, n);
	
	printf("%d\n", cnt);
	
	for(i=0; i<n; i++)
	{
		printf("%d\n", A[i]);
	}
	
	return 0;
}

void insertionSort(int A[], int n, int g)
{
	int i=0, v=0, j=0;
	
	for(i=g; i<n; i++)
	{
		v = A[i];
		j = i - g;
		
		while(j >= 0 && A[j] > v)
		{
			A[j+g] = A[j];
			j = j - g;
			cnt++;
			
//			printf("(46)%d %d %d\n", i, j ,cnt);
		}
		A[j+g] = v;
	}
}
void shellSort(int A[], int n)
{
	int cnt=0, m, h=1, i=0, j=0;
	int G[100];
	
	for(i=0, h=1; ; i++)
	{
		if(h > n) break;
		G[i] = h;
		h = h * 3 + 1;
	}
	
	printf("%d\n", i);
	cnt=0;
	for(j=i-1; j>=0; j--)
	{
		if(j==0)
		{
			printf("%d\n", G[j]);
		}
		else
		{
			printf("%d ", G[j]);
		}
		insertionSort(A, n, G[j]);
	}
	
/*	for(j=0; j<i; j++)  //逆順にG[i]=gを指定
	{
		insertionSort(A, n, G[j]);
	}
*/
}
