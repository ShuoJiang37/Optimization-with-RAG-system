#include <stdio.h>
#include <stdlib.h>

#define NOT_CHECK 0
#define CHECK 1

typedef struct element_ {
	int idx, val;
} element;

int element_sort(void *a, void *b) {
	return (*(element*)a).val - (*(element*)b).val;
}

int main(void) {
	int i, n, costs, m;
	int A[1005];
	int W[10005];
	int chk[1005];
	element sortedA[1005];

	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d\n", &A[i]);
		sortedA[i].idx = i;
		sortedA[i].val = A[i];
		W[A[i]] = i;
		chk[i] = NOT_CHECK;
	}

	qsort((void*)sortedA, n, sizeof(element), element_sort);

	m = sortedA[0].val;
	costs = 0;
	for(i=0;i<n;i++) {
		int p, cost, lt, cnt, t;
		p = i;

		t = 0;
		cnt = 0;
		lt = 10005;
		while(chk[p]==NOT_CHECK) {
			chk[p] = CHECK;
			t += A[p];
			cnt++;
			if(lt > A[p]) lt = A[p];
			p = W[sortedA[p].val];
		}
		if(cnt<2) continue;	// 入れ替えが発生し始めるのはcntが2以上になってから
		
		// 入れ替え中に見つかった最小値を入れ替えに使った方がコストが低いか
		// 回り道して最小の値を使って入れ替えに使った方がコストが低いか
		cost = t+m*(cnt+1)+lt;	// lt -> m ・・ m -> A[k] ・・ m -> lt
		if(cost>t+lt*(cnt-2)) cost = t+lt*(cnt-2);
		costs += cost;
	}

	printf("%d\n", costs);
	return 0;
}