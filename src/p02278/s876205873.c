#include <stdio.h>
#include <limits.h>

#define MAX 1000
#define MIN(a, b) ((a) < (b) ? (a) : (b))


int A[MAX] = {0};
int B[MAX] = {0};
int T[10000 + 1];
int n, s;

int partition(int A[], int p, int r) {
	int x, i, j, tmp;
	x = A[r];
	i = p - 1;

	for (j = p; j < r; ++j) {
		if (A[j] <= x) {
			++i;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;
	return i + 1;
}

void quicksort(int A[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int solve() {
	int ans = 0;
	int i, cur, S, m, an, v;
	short V[MAX] = {0};

	for (i = 0; i < n; ++i) {
		B[i] = A[i];
		V[i] = 0;
	}
	quicksort(B, 0, n-1);
	/* for (i = 0; i < n; ++i) { */
	/* 	printf("%d ", B[i]); */
	/* } */
	//printf("\n");

	for (i = 0; i < n; ++i) T[B[i]] = i;
	for (i = 0; i < n; ++i) {
		if (V[i]) continue;
		cur = i;
		S = 0;
		m = INT_MAX;
		an = 0;
		while (1) {
			V[cur] = 1;
			an++;
			v = A[cur];
			m = MIN(m, v);
			S += v;
			cur = T[v];
			//	printf("i = %d, cur = %d, v = %d, S = %d, an = %d, ans = %d\n", i, cur, v, S, an, ans);
			if (V[cur]) break;
		}
		ans += MIN(S + (an - 2) * m, m + S + (an + 1) * s);
	}

	return ans;
}

int main(void) {
	int i;
	scanf("%d", &n);
	s = INT_MAX;
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
		if (s > A[i]) s = A[i];
	}

	printf("%d\n", solve());
	
	return 0;
}