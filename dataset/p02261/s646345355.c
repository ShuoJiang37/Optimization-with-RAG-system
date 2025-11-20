#include <stdio.h>
#include <string.h>

#define DEF_ELM_MAX 36

typedef	struct	_CARD {
	char	mark;
	int		value;
} CARD;

	CARD R1[DEF_ELM_MAX];
	CARD R2[DEF_ELM_MAX];

////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void swap(CARD *x, CARD *y)
{
	CARD tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void bubbleSort(CARD *A, int N) // N ??????????´?????????? 0-????????????????????? A
{
	int flag = 1; // ????????£??\????´?????????¨??????
	int i;
	int j;

	i = 0;
	while (flag) {
		flag = 0;
		for ( j = N-1 ; j > i ; j-- ) {
			if (A[j].value < A[j-1].value) {
				swap(&A[j], &A[j-1]);
				flag = 1;
			}
		}
		i++;
	}
	return;
}

////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void selectionSort(CARD *A, int N) // N??????????´??????????0-?????????????????????A
{
	int i;
	int j;
	int minj;
	int flag;

	for ( i = 0 ; i < N ; i++ ) {
		minj = i;
		flag = 0;
		for ( j = i ; j < N ; j++ ) {
			if ( A[j].value < A[minj].value ) {
				minj = j;
				flag = 1;
			}
		}
		if (flag) {
			swap(&A[i], &A[minj]);
		}
	}
	return;
}

////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void printStable(CARD *A1, CARD *A2, int N)
{
	int i;
	int cnt = 0;
	for ( i = 0 ; i < N ; i++ ) {
		if (A1[i].mark == A2[i].mark) {
			cnt++;
		}
	}
	printf("%s\n", ((cnt == N) ? "Stable" : "Not stable"));
}
////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void printout(CARD *A, int N)
{
	int i;
	for ( i = 0 ; i < N ; i++ ) {
		printf("%c%d", A[i].mark, A[i].value);
		if (i == N-1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	int N;
	int i;
//
	scanf("%d", &N);
	for ( i = 0 ; i < N ; i++ ) {
		scanf(" %c%d", &R1[i].mark, &R1[i].value);
		R2[i] = R1[i];
	}
//
	bubbleSort(R1, N);

	selectionSort(R2, N);

	printout(R1, N);
	printf("Stable\n");
	
	printout(R2, N);
	printStable(R1, R2, N);

	return 0;
}