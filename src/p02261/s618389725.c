#include <stdio.h>

void BubbleSort(char a[][3], int n)
{
	int i, j;
	char temp[5];
	int cnt = 0;

	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j][1] < a[j - 1][1]) {
				strcpy(temp, a[j - 1]);
				strcpy(a[j - 1], a[j]);
				strcpy(a[j], temp);
			}
		}
	}
}

void SelectionSort(char a[][3], int n)
{
	int i, j, minj;
	char temp[5];
	int cnt = 0;

	for (i = 0; i < n - 1; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (a[j][1] < a[minj][1]) {
				minj = j;
			}
		}
		if (minj != i) {
			strcpy(temp, a[minj]);
			strcpy(a[minj], a[i]);
			strcpy(a[i], temp);
		}
	}
}

int main(void) {
	int n;
	char line[36][3], line_copy[36][3];
	int i;
	int stable = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", &line[i]);
	}

	for (i = 0; i < n; i++) {
		strcpy(line_copy[i], line[i]);
	}

	BubbleSort(line, n);
	SelectionSort(line_copy, n);

	for (i = 0; i < n; i++) {
		printf("%s", line[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");
	printf("Stable\n");

	for (i = 0; i < n; i++) {
		printf("%s", line_copy[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");

	for (i = 0;i < n;i++) {
		if(strcmp(line_copy[i], line[i]) != 0){
			stable = 1;
			}
	}
	if (stable != 0) {
		printf("Not stable\n");
	}
	else {
		printf("Stable\n");
	}

	return 0;
}
