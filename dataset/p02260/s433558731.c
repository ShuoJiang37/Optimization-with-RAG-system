#include <stdio.h>

int main(){

	int N, min_j, cnt=0, temp, i, j;
	int A[100];

	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	for(i=0; i<N; i++){
		min_j = i;
		for(j=i; j<N; j++){
			if(A[j]<A[min_j]){
				min_j = j;
			}
		}
		if(i!=min_j){
			temp = A[min_j];
			A[min_j] = A[i];
			A[i] = temp;
			cnt++;
		}
	}

	for(i=0; i<N; i++){
		if(i!=0){
			printf(" ");
		}
		printf("%d", A[i]);
	}
	printf("\n%d\n", cnt);

	return 0;
}