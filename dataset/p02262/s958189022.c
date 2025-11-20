// AOJ ALDS1_2_D Shell Sort
// 2018.4.27 bal4u

#include <stdio.h>

int cnt;

void insertion_sort(int n, int *a, int g)
{
	int i, j, key;

	for (i = g; i < n; i++) {
		key = a[i];
		j = i-g;
		while (a[j] > key) {
			a[j+g] = a[j];
			cnt++;
			j -= g;
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
	m = 0; do m++, g[m] = 3*g[m-1]+1;
	while (g[m] < n && g[m] <= lim);

	cnt = 0;
	i = m; while (i--) insertion_sort(n, a, g[i]);
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
void mypr(int n)
{
	int i;
	if (n == 0) { pc('0'); return; }
	i = 0; while (n) buf[i++] = n%10 +'0', n /= 10;
	while (i) pc(buf[--i]);
}

int a[1000002];

int main()
{
	int N, i;

	N = in(); for (i = 0; i < N; i++) a[i] = in();

	shell_sort(N, a);
	
	mypr(m), pc('\n');
	mypr(g[m-1]); for (i = m-2; i >= 0; i--) pc(' '), mypr(g[i]); pc('\n');
	mypr(cnt), pc('\n');
	for (i = 0; i < N; i++) mypr(a[i]), pc('\n');

	return 0;
}
