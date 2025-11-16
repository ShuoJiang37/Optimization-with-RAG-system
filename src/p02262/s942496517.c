#include <stdio.h>

int insertionSort(int A[], int n, int g) {
	int i, j, v, cnt;
	cnt = 0;
	for(i=g;i<n;i++) {
		v = A[i];
		j = i - g;
		while(j>=0 && A[j] > v) {
			A[j+g] = A[j];
			j = j - g;
			cnt ++;
		}
		A[j+g] = v;
	}
	
	return cnt;
}

int shellSort(int A[], int n) {
	int i, h, m, cnt;
	int G[120000];
	cnt = 0;
	m = 0;
	
    h = 1; m = 0;
    G[m] = h;
    m ++;
    if(n > 100) {
	    while( h < (n/9.0) ) {
	        h = h*3 + 1;
	        G[m] = h;
	        m++;
	    }
    } else {
	    while( h < (n/3.0) ) {
	        h = h*3 + 1;
	        G[m] = h;
	        m++;
	    }
    }
	
	printf("%d\n", m);
	for(i=0;i<m;i++) {
		cnt += insertionSort(A, n, G[m-i-1]);
		printf("%d", G[m-i-1]);
		if(i<m-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	
	return cnt;
}

int list[1000000];

int main(void) {
	int n, i, cnt;
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d\n", &list[i]);
	}
	cnt = shellSort(list, n);
	printf("%d\n", cnt);
	
	for(i=0;i<n;i++) {
		printf("%d\n", list[i]);
	}
	
	return 0;
}