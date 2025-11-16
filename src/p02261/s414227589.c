#include <stdio.h>

#define N 36

typedef struct {
	char mark;
	int num;
} trump;

void BubbleSort(trump *C, int n) {
	int i,j;
	trump tmp;

	for (i = 0; i < n; i++)  {
		for (j = n-1; j > i; j--){
			if (C[j].num < C[j-1].num) {
				tmp = C[j];
				C[j] = C[j-1];
				C[j-1] = tmp;
			}
		}
	}
	for (i = 0; i < n-1; i++) 
		printf("%c%d ", C[i].mark, C[i].num);
	printf("%c%d\n", C[i].mark, C[i].num);
	printf("Stable\n");
}

void SelectionSort(trump *C, int n) {
	int i,j;
	int min_index;
	trump tmp;

	for (i = 0; i < n; i++) {
		min_index = i;
		for(j = i; j < n; j++) {
			if (C[j].num < C[min_index].num) min_index = j;
		}
		tmp = C[i];
		C[i] = C[min_index];
		C[min_index] = tmp;
	}

	for (i = 0; i < n-1; i++) 
		printf("%c%d ", C[i].mark, C[i].num);
	printf("%c%d\n", C[i].mark, C[i].num);
}

int isStable(trump *C1, trump *C2, int n) {
	int i;

	for (i = 0; i < n; i++) {
		if(C1[i].mark == C2[i].mark && C1[i].num == C2[i].num) continue;
		
		return 0;
	}

	return 1;
}

int main() {
	int i,n;
	trump C1[N], C2[N];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf(" %c%d", &C1[i].mark, &C1[i].num);
		C2[i] = C1[i];
	}

	BubbleSort(C1, n);
	SelectionSort(C2, n);
	if(isStable(C1, C2, n) == 0) printf("Not stable\n"); 
	else printf("Stable\n");

	return 0;
}