// AOJ ALDS1_6_A Counting Sort
// 2018.4.27 bal4u

#include <stdio.h>

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
	do n = (n<<3)+(n<<1) + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

char buf[20]; int w;
void mypr(int n)
{
	int i;
	if (!n) { putchar('0'); return; }
	w = 0; while (n) buf[w++] = n%10 + '0', n/=10;
	i = w; while (i--) pc(buf[i]);
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
		x = a[i], b[--f[x]] = x;
	}
}

int a[2000002], b[2000002];

int main()
{
	int N, i, j;

	N = in();
	for (i = 0; i < N; i++) a[i] = in();
	counting_sort(N, a, b, 10000);
	if (!b[0]) putchar('0'); else mypr(b[0]);
	for (i = 1; i < N; i++) {
		pc(' ');
		if (!b[i]) putchar('0');
		else if (b[i] == b[i-1]) {
			j = w; while (j--) pc(buf[j]);
		} else mypr(b[i]);
	}
	pc('\n');
	return 0;
}

