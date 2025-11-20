#include<stdio.h>
int main() {
	int n;				/*要素数*/
	long int A[1000000];/*配列*/
	int i, j, k;		/*ループ用変数*/
	long int v;			/*ソート用変数*/
	int m = 0;			/*間隔の数*/
	int G[100];			/*間隔の配列*/
	int g;				/*間隔*/
	int cnt = 0;		/*要素が移動させられた回数*/

	/*要素数の入力*/
	scanf("%d", &n);

	/*間隔の作成*/
	int x = 1;
	for (i = 0; x <= n; i++) {
		/*mを増やす*/
		m++;
		/*配列に間隔を格納*/
		G[i] = x;
		/*4,13,40...*/
		x = x * 3 + 1;
	}
	
	/*要素の入力*/
	for (i = 0; i < n; i++) {
		scanf("%ld", &A[i]);
	}

	/*シェルソート*/
	for (i = 0; i < m; i++) {
		g = G[m - i - 1];
		/*挿入ソート*/
		for (j = g; j < n; j++) {
			v = A[j];
			k = j - g;
			/*入れ替え処理*/
			while (k >= 0 && A[k] > v) {
				A[k + g] = A[k];
				k = k - g;
				cnt++;
			}
			A[k + g] = v;
		}
	}

	/*mの出力*/
	printf("%d\n", m);

	/*Gの出力*/
	for (i = m - 1; i >= 0; i--) {
		if (i == 0) {
			printf("%d\n", G[i]);
		}
		else {
			printf("%d ", G[i]);
		}
	}

	/*cntの出力*/
	printf("%d\n", cnt);

	/*配列（ソート済み）の出力*/
	for (i = 0; i < n; i++) {
		printf("%d\n", A[i]);
	}

	return 0;
}

