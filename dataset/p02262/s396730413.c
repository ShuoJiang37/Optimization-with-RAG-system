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
		while (a[j] > key) {
			a[j+g] = a[j];
			j -= g;
cnt++;
			if (j < 0) break;
		}
		a[j+g] = key;
	}
}

int m;
int g[102];

void shell_sort(int n, int *a)
{
	int i, lim;

	lim = n / 9;		// 要素数/9
	if (lim < 40) lim = 40;
	g[0] = 1;
	for (m = 1; ; m++) {
		g[m] = 3*g[m-1]+1;
		if (g[m] >= n || g[m] > lim) break;
	}

	cnt = 0;
	for (i = m-1; i >= 0; i--) insertion_sort(n, a, g[i]);
}

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

char buf[20];
void mypr(int n, int ln)
{
	int i = 0;
	if (n == 0) buf[i++] = '0';
	else while (n) buf[i++] = n%10 + '0', n/=10;
	while (i) pc(buf[--i]);
	if (ln) pc('\n');
}

int a[1000002];

int main()
{
	int N, i;

	N = in();
	for (i = 0; i < N; i++) a[i] = in();
	shell_sort(N, a);
	mypr(m, 1);
	mypr(g[m-1], 0);
	for (i = m-2; i >= 0; i--) pc(' '), mypr(g[i], 0);
	pc('\n');
	mypr(cnt, 1);
	for (i = 0; i < N; i++) mypr(a[i], 1);
	return 0;
}
