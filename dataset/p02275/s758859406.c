// AOJ ALDS1_6_A Counting Sort
// 2018.4.27 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void mypr(int n)
{
	int i = 0;
	if (n == 0) buf[i++] = '0';
	else while (n) buf[i++] = n%10 + '0', n/=10;
	while (i) pc(buf[--i]);
}

// 計数ソート（整数用）昇順
#define MAX_N 10002
int f[MAX_N];

void counting_sort(int n, int *a, int *b, int max)
{
	int i, x;
//	memset(f, 0, sizeof(f));
	for (i = 0; i < n; i++) f[a[i]]++;
	for (i = 1; i <= max; i++) f[i] += f[i-1];
	for (i = n-1; i >= 0; i--) {
		x = a[i], b[--f[x]] = a[i];
	}
}

int a[2000002], b[2000002];

int main()
{
	int N, i;

	N = in();
	for (i = 0; i < N; i++) a[i] = in();
	counting_sort(N, a, b, 10000);
	mypr(b[0]);
	for (i = 1; i < N; i++) pc(' '), mypr(b[i]);
	pc('\n');
	return 0;
}

