#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	scanf("%d",&n);
	char cardA[n][2];
	char cardB[n][2];
	for(int i = 0; i < n; i++)scanf("%s",&cardA[i][0]);
    strcpy(cardB, cardA);
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(cardA[j][1] > cardA[j+1][1]){
				int temp		= cardA[j][0];
				cardA[j][0]		= cardA[j+1][0];
				cardA[j+1][0]	= temp;
				temp			= cardA[j][1];
				cardA[j][1]		= cardA[j+1][1];
				cardA[j+1][1]	= temp;
			}
		}
	}
	for(int i = 0; i < n-1; i++){
		int minj = i;
		for(int j = i; j < n; j++){
			minj = (cardB[minj][1] > cardB[j][1])?j:minj;
		}
		int temp		= cardB[i][0];
		cardB[i][0]		= cardB[minj][0];
		cardB[minj][0]	= temp;
		temp			= cardB[i][1];
		cardB[i][1]		= cardB[minj][1];
		cardB[minj][1]	= temp;
	}
	printf("%c%c",cardB[0][0],cardB[0][1]);
	for(int i = 1; i < n; i++)printf(" %c%c",cardA[i][0],cardA[i][1]);
	printf("\n");
	printf("Stable\n");
	printf("%c%c",cardB[0][0],cardB[0][1]);
	for(int i = 1; i < n; i++)printf(" %c%c",cardB[i][0],cardB[i][1]);
	printf("\n");
	for(int i = 0; i < n; i++){
		if(cardA[i][0]==cardB[i][0]){
			continue;
		}
		printf("Not stable\n");
		return 0;
	}
	printf("Stable\n");
	return 0;
}

