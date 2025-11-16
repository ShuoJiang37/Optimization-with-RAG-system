// AOJ ALDS1_2_D Shell Sort
// 2018.4.27 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt;

void insertion_sort(int n, int *a, int g)
{
	int i, j, key;

	for (i = g; i < n; i++) {
		key = a[i];
		j = i-g;
		while (j >= 0 && a[j] > key) {
			a[j+g] = a[j];
			j -= g;
cnt++;
		}
		a[j+g] = key;
	}
}

int m;
int g[102];

void shell_sort(int n, int *a)
{
	int i;

	g[0] = 1;
	for (m = 1; ; m++) {
		g[m] = 3*g[m-1]+1;
		if (g[m] >= n) break;
	}

	cnt = 0;
	for (i = m-1; i >= 0; i--) insertion_sort(n, a, g[i]);
}

// バッファを経ずstdinから数値を得る
//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int a[1000002];

int main()
{
	int N, i;

	N = in();
	for (i = 0; i < N; i++) a[i] = in();
	shell_sort(N, a);
	printf("%d\n", m);
	printf("%d", g[m-1]);
	for (i = m-2; i >= 0; i--) printf(" %d", g[i]);
	printf("\n%d\n", cnt);
	for (i = 0; i < N; i++) printf("%d\n", a[i]);
	return 0;
}
