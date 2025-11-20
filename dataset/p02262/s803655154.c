#include <stdio.h>

long long cnt;
int l = 0;
int a[1000000];
int n;
int g[1000000];

void insertionSort(int a[],int n,int g);
void shellSort(int a[],int n);

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int a[n];
	int i;
	for( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	cnt = 0;
	shellSort(a,n);
	
	printf("%d\n",l);
	for( int i = l-1; i >= 0; i--)
	{
		printf("%d",g[i]);
		if(i)printf(" ");
	}
	printf("\n");
	printf("%d\n",cnt);
	for( int i = 0; i < n; i++)printf("%d\n",a[i]);
	
	
	return 0;
}

void insertionSort(int a[], int n , int g)
{
	for( int i = g; i < n; i++)
	{
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v)
		{
			a[j+g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = v;
	}
}

void shellSort(int a[], int n)
{
	int i = 0;
	for( int h = 1;;)
	{
		if( h > n) break;
		g[i] = h;
		h = 3*h+1;
		i++;
		l++;
	}
	for( int j = i -1; j >= 0; j--)
	{
		insertionSort(a,n,g[j]);
	}
}

