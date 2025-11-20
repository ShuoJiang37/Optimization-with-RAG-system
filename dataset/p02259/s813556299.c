#include <stdio.h>

int main(){

	int N, flag=1, cnt=0, temp, i;
	int A[100];

	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	while(flag){
		flag = 0;
		for(i=N-1; i>=1; i--){
			if(A[i]<A[i-1]){
				temp = A[i];
				A[i] = A[i-1];
				A[i-1] = temp;
				cnt++;
				flag = 1;
			}
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