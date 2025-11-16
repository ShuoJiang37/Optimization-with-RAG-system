#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int insection_sort(int *A, int n, int g){
	int cnt = 0;
	int i,j,v;

	for(i=g;i<=n-1;i++){
		v = A[i];
		j = i - g;
		while( j>=0 && A[j]>v ){
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}

	return cnt;
}

int shell_sort(int *A, int n, int *G, int m){
	int total_cnt = 0;
	int i,cnt;

	for(i=0;i<=m-1;i++){
		cnt = insection_sort(A, n, G[i]);
		total_cnt += cnt;
	}

	return total_cnt;
}

int is_sorted(int *A, int n){
	int i;

	for(i=0;i<n-1;i++){
		if( A[i] > A[i+1] ){
			return 0;
		}
	}

	return 1;
}

int main(int argc, char** argv){
	int *A,n,*G,m,total_cnt;
	int i,j;

	// Create A
	scanf("%d",&n);
	A = malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",A+i);
	}

	// Create G
	j = 1;
	m = 0;
	while( j <= n ){
		m++;
		j = j * 3 + 1;
	}
	G = malloc(sizeof(int)*m);
	j = 1;
	for(i=0;i<m;i++){
		G[m-i-1] = j;
		j = j * 3 + 1;
	}

	// Sort
	total_cnt = shell_sort(A,n,G,m);
	// Output
	printf("%d\n",m);
	for(i=0;i<m;i++){
		if( i > 0 ){
			putchar(' ');
		}
		printf("%d",G[i]);
	}
	putchar('\n');
	printf("%d\n",total_cnt);
	for(i=0;i<n;i++){
		printf("%d\n",A[i]);
	}

	// Delete G
	free(G);

	// Delete A
	free(A);

	return 0;
}