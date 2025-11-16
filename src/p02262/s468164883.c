#include<stdio.h>
#include<stdlib.h>

int insertionSortCount(int*, int, int);
void shellSort(int*, int);

int main(void){
	int n, *a, i;
	
	scanf("%d\n", &n);
	a = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		scanf("%d\n", &a[i]);
	}
	shellSort(a, n);
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}
	free(a);
	
	return 0;
}

int insertionSortCount(int* arr, int len, int h){
	int i, j, v, cnt = 0;
	for(i = h; i < len; i++){
		v = arr[i];
		j = i-h;
		while(j >= 0 && arr[j] > v){
			arr[j+h] = arr[j];
			j -= h;
			cnt++;
		}
		arr[j+h] = v;
	}
	return cnt;
}

void shellSort(int* arr, int len){
	int cnt = 0, m = 1, i = 0, j, g[100];
	while(len >= m){
		g[i] = m;
		m = m*3 + 1;
		i++;
	}
	printf("%d\n", i);
	for(j = i-1; j >= 0; j--){
		j == 0 ? printf("%d\n", g[j]) : printf("%d ", g[j]);
		cnt += insertionSortCount(arr, len, g[j]);
	}
	printf("%d\n", cnt);
}
