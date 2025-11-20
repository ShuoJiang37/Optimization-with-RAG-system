#include<stdio.h>
#include<stdlib.h>

struct sample {
	char suit;
	char value;
} A[100], B[100];

int isStable(struct sample A[], struct sample B[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (A[i].suit != B[i].suit || A[i].value != B[i].value) {
			return 0;
		}
	}
	return 1;
}

void sSort(struct sample A[], int N) {
	int i, j;
	int min;
	for (i = 0; i < N; i++) {
		min = i;
		for (j = i; j < N; j++) {
			if (A[j].value < A[min].value) {
				min = j;
			}
		}
		if (i != min) {
			struct sample temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
}

void bSort(struct sample A[], int N) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = N - 1; j >= i; j--) {
			if (A[j].value < A[j - 1].value) {
				struct sample v = A[j];
				A[j] = A[j - 1];
				A[j - 1] = v;
			}
		}
	}
}

int main() {
	int N;
	int i;
	char s[5];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", s);
		A[i].suit = s[0];
		A[i].value = atoi(s + 1);
		B[i] = A[i];
	}
	bSort(A, N);
	for (i = 0; i < N; i++) {
		if (i > 0)
			printf(" ");
		printf("%c%d", A[i].suit, A[i].value);
	}
	printf("\nStable\n");
	sSort(B, N);
	for (i = 0; i < N; i++) {
		if (i > 0)
			printf(" ");
		printf("%c%d", B[i].suit, B[i].value);
	}
	if (isStable(A, B, N)) {
		printf("\nStable\n");
	} else {
		printf("\nNot stable\n");
	}
	return 0;
}

