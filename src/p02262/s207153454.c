#include <stdio.h>

#define MMAX 20
#define NMAX 1000000


int getData(int *data, int n)
{
	int i=0;

	for (i = 0; i<n; i++)
		scanf("%d", &(data[i]));
	return (i == n);
}

int M[MMAX];
int A[NMAX];
int cnt;

int initM(int n)
{

	int h=1, i=0, mmax;

	for (i = 0; i<MMAX; i++)
	{
		if (h > n) break;
		h = 3*h+1;
	}
	mmax = i;

	for (i = 0; i<mmax; i++)
	{
		h = (h-1)/3;
		M[i] = h;
	}	
	return mmax;
}


int insertionSort(int *data, int n, int g)
{
	int i, v;
	for (i = g; i < n; i++)
	{
		v = data[i];
		int j = i-g;
		while(j >= 0 && data[j]>v)
		{
			data[j+g] = data[j];
			j = j -g;
			cnt++;
		}
		data[j+g] = v;
	}
}

void printdata(int *data, int n)
{
	for(int i=0; i<n; i++)
		printf("%d\n",data[i]);
}

int shellSort(int *data, int n)
{
	int m = initM(n);

	for(int i = 0; i<m  ; i++)
	{
		insertionSort(data, n, M[i]);

	}
	
	printf("%d\n", m);
        for(int i=0; i<m; i++)
	{
		printf("%d%s", M[i], (i!=m-1)?" ":"\n");
	}
	printf("%d\n", cnt);
	printdata(data, n);

}

int main(int argc, char **argv)
{
	int n;
	cnt = 0;
	scanf("%d", &n);
	
	getData(A, n);
	shellSort(A, n);
	return 0;
}

