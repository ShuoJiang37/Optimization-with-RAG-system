#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void insertionSort(int R[], int n,int g,int *cnt) {
	int i, v, j;
	
	for (i = g; i < n; i ++) {					
		v = R[i];
		j = i - g;
		while (j >= 0 && R[j] > v) {				
			R[j + g] = R[j];
			j = j - g;
			(*cnt)++;	//()をつける！！
		}
		R[j + g] = v;
	}
}

void shellSort(int R[], int n) {
	int cnt = 0;
	int m = 0;
	int h = 0;
	int *G, i;
	
	G = (int*)malloc(sizeof(int)*2*n);
	while (cnt == 0) {
		h = 3 * h + 1;
		if (h > n){
			break; }
		G[m] = h;
		m++;
	}

	printf("%d\n", m);
	for (i = 0; i < m ; i++) {
		printf("%d ", G[m-i-1]);
		if (i == m - 1) {
			printf("\n");
		}
	}

	for (i = 0; i < m ;i++ ) {
		insertionSort(R, n, G[m-i-1],&cnt);
	}
	printf("%d\n",cnt);
}

int main(void){
	
	char nc[20],Rc[20];
	int n, *R,i;

	fgets(nc,sizeof(nc),stdin);
	n = atoi(nc);									//nの取得
	
	//Rc = (char *)malloc(sizeof(char)* (11*n));
	R = (int *)malloc(sizeof(int)* n);				//R,Rc配列を作成(文字列の配列は不安定なのでバツ）

	for (i = 0; i < n; i++) {
		fgets(Rc,sizeof(Rc),stdin);
		if (Rc == NULL) {
			printf("errorです");
		}
		else {
			R[i] = atoi(Rc);
		}
	}

	shellSort(R, n);

	for (i = 0; i < n; i++) {
		printf("%d\n", R[i]);
	}
	free(R);

	


	return 0;
}
