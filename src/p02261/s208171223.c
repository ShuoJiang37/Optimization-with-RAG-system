#include<stdio.h>
struct Card{
	char s, v;
};
void bubbleSort(struct Card A[], int N) {
        int i,j;
        struct Card t;
	for (i = 0; i < N; i++) {
		for ( j = N - 1; j > i; j--) {
			if (A[j-1].v > A[j].v) {
				t=A[j-1];
				A[j-1]=A[j];
				A[j]=t;
			}
		}
	}
}
void selectSort(struct Card A[], int N) {
	int minj,i,j;
	struct Card t;
	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j].v < A[minj].v) {
				minj = j;
			}
		}
		t=A[minj];
                A[minj]=A[i];
                A[i]=t;
	}
}

void print(struct Card A[], int N) {
        int i;
	for (i = 0; i < N; i++) {
		if (i != 0) printf(" ");
		printf("%c%c",A[i].s,A[i].v);
	}
}
int isstable(struct Card C1[], struct Card C2[], int N) {
	int tag = 1,i;
	for (i = 0; i < N; i++) {
		if (C1[i].s != C2[i].s||C1[i].v!=C2[i].v) {
			tag = 0;
		}
	}
	return tag;
}
int main() {
	struct Card C1[100],C2[100];
	int N,i;
	char ch;

	scanf("%d",&N);
	for (i = 0; i < N; i++) {
		scanf(" %c%c",&C1[i].s,&C1[i].v);
	}
	for (i = 0; i < N; i++) {
		C2[i] = C1[i];
	}
	bubbleSort(C1, N);
	selectSort(C2, N);
	print(C1, N);
	printf("\n");
	printf("Stable\n");
	print(C2, N);
	if (isstable(C1,C2,N)){
                        printf("\n");
		printf("Stable\n");
	}
	else {
	         printf("\n");
		printf("Not stable\n");
	}
	return 0;
}

