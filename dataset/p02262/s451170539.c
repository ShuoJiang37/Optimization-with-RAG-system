#include<stdio.h>
#include<stdlib.h>

int insertionSort(int *a, int n, int g){
	int cnt = 0, i, j, key;

	for(i = g; i < n; i++){
		key = a[i];
		j = i - g;
		while( j >= 0 && a[j] > key){
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = key;
	}

	return cnt;
}

 int shellSort(int *a, int n){
 	int cnt = 0;
 	int h = 1, m = 1, i;
 	int G[1000];

 	G[0] = 1;
 	i = 1;
 	while(h < n / 3){
		h = 3 * h + 1;
		G[i] = h;
		i++;
		m++;
 	}
 	printf("%d\n", m);

 	//G[] output
 	for(i = m - 1; i >= 0; i--){
 		printf("%d", G[i]);
 		(i != 0) ? printf(" ") : printf("\n");
 	}

 	for(i = m-1; i >= 0; i--)
 		cnt += insertionSort(a, n, G[i]);
 	
 	return cnt;
}


int main(){
	int n, i, cnt = 0;
	int *a;

	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	cnt = shellSort(a, n);
	printf("%d\n", cnt);

	for(i = 0; i < n; i++)
		(i != n-1) ? printf("%d\n", a[i]): printf("%d", a[i]);

	return 0;
}