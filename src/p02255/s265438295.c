#include <stdio.h>
 
int main(){
	int i = 0, j, k, n, array[100];

	scanf("%d", &n);
	while(i < n)scanf("%d", &array[i++]);
	for(i = 0; i < n; i++){
		j = i;
		k = array[j];
		while(j > 0 && k < array[j-1]){
			array[j] = array[j-1];
			j--;
		}
		array[j] = k;
		
		for(j = 0; printf("%d", array[j]), j < n-1; j++)printf(" ");
		printf("\n");
	}
	return 0;
}