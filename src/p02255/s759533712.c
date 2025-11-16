#include<stdio.h>
int main(void){
	int i,j,A[101],N,v,count;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		printf("%d",A[i]);
		if(i == N-1){
			printf("\n");
		}
		else{
			printf(" ");
		}
	}
	for(i=0;i<N-1;i++){
		j=i+1;
		count=0;
		while(A[i]>A[j]){
			v=A[j];
			A[j]=A[i];
			A[i]=v;
			i--;
			j--;
			count++;
			if(i == -1){
				break;
			}
		}
		i+=count;
		for(j=0;j<N;j++){
			printf("%d",A[j]);
			if(j == N-1){
				printf("\n");
			}
			else{
				printf(" ");
			}
		}
	}
	return 0;
}