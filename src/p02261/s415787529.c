#include <stdio.h>

struct card{
	char mark[1];
	int value;
};

int main(){

	int N, min_j, flag=1, i, j;
	struct card c[36];
	struct card d[36];
	struct card temp;

	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%1s%d", c[i].mark, &c[i].value);
		d[i] = c[i];
	}

	//Bubble
	while(flag){
		flag = 0;
		for(i=N-1; i>=1; i--){
			if(c[i].value<c[i-1].value){
				temp = c[i];
				c[i] = c[i-1];
				c[i-1] = temp;
				flag = 1;
			}
		}

	}

	for(i=0; i<N; i++){
		if(i!=0){
			printf(" ");
		}
		printf("%s%d", c[i].mark, c[i].value);
	}
	printf("\nStable\n");


	//Select
	for(i=0; i<N; i++){
		min_j = i;
		for(j=i; j<N; j++){
			if(d[j].value<d[min_j].value){
				min_j = j;
			}
		}
		if(i!=min_j){
			temp = d[min_j];
			d[min_j] = d[i];
			d[i] = temp;
		}
	}

	flag = 0;

	for(i=0; i<N; i++){
		if(i!=0){
			printf(" ");
		}
		printf("%s%d", d[i].mark, d[i].value);
		if(c[i].mark[0]!=d[i].mark[0]){
			flag = 1;
		}
	}
	printf("\n");

	if(flag==0){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}

	return 0;
}