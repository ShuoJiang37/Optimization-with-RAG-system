// AOJ ALDS1_2_C Stable Sort
// 2018.4.27 bal4u

#include <stdio.h>
#include <string.h>

typedef struct { char c; int a; int id; } data;

void bubble_sort(int n, data *a)
{
	int i, f;
	data x;

	do {
		f = 0;
		for (i = n-1; i > 0; i--) {
			if (a[i].a < a[i-1].a) {
				x = a[i], a[i] = a[i-1], a[i-1] = x;
				f = 1;
			}
		}
	} while (f);
}

void selection_sort(int n, data *a)
{
	int i, j, minj;
	data x;

	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (a[j].a < a[minj].a) minj = j;
		}
		if (i != minj) {
			x = a[i], a[i] = a[minj], a[minj] = x;
		}
	}
}


//#define getchar_ed()  getchar()
int in()
{
	int n = 0, c = getchar();
	do n = 10*n + (c & 0xf), c = getchar(); while (c >= '0');
	return n;
}

data a[102], b[102];

int main()
{
	int N, i, f;

	N = in();
	for (i = 0; i < N; i++) {
		a[i].c = getchar();
		a[i].a = getchar();
		a[i].id = i;
		getchar();			// skip
	}
	memcpy(b, a, sizeof(data)*N);

	bubble_sort(N, a);
	f = 0;
	putchar(a[0].c), putchar(a[0].a);
	for (i = 1; i < N; i++) {
		putchar(' ');
		putchar(a[i].c), putchar(a[i].a);
		if (a[i-1].a == a[i].a && a[i-1].id > a[i].id) f = 1;
	}
	putchar('\n');
	puts(f? "Not stable": "Stable");

	selection_sort(N, b);
	f = 0;
	putchar(b[0].c), putchar(b[0].a);
	for (i = 1; i < N; i++) {
		putchar(' ');
		putchar(b[i].c), putchar(b[i].a);
		if (b[i-1].a == b[i].a && b[i-1].id > b[i].id) f = 1;
	}
	putchar('\n');
	puts(f? "Not stable": "Stable");
	return 0;
}

