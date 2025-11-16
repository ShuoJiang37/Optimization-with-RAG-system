#include <stdio.h>

int main(void){
	int i, j, k, n, array[100];

	scanf("%d", &n);
	for(i = 0; i < n; i++)  scanf("%d", &array[i]);  
	for(i = 0; i < n; i++){
		j = i;
		while(j > 0 && array[j] < array[j-1]){
			k = array[j];
			array[j] = array[j-1];
			array[j-1] = k;
			j--;
		}
		for(j = 0; j < n-1; j++)  printf("%d ", array[j]);
		printf("%d\n", array[n-1]);
	}
	
	return 0;
}