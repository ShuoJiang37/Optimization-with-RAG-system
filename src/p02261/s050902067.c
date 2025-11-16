#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void BubbleSort(int A[],int n, char *p);
void SelectionSort(int A[],int n, char *p);

int main(){
	int *A, *B, n, i;
	char m1[37]="",m2[37]="",*p1,*p2;
	scanf("%d", &n);
	A = (int *)malloc(sizeof(int)*n);
	B = (int *)malloc(sizeof(int)*n);
	p1 = m1; p2 = m2;
	for (i = 0; i < n; ++i) {
		scanf("%1s%d", p1+i,A + i);
		*(B + i) = *(A + i);
		*(p2 + i) = *(p1 + i);
	}
	BubbleSort(A, n,p1);
	if (strcmp(p1, p1) == 0)printf("Stable\n");
	else printf("Not stable\n");
	SelectionSort(B, n,p2);
	if (strcmp(p1, p2) == 0)printf("Stable\n");
	else printf("Not stable\n");
	free(A);
	free(B);
	return 0;
}

void BubbleSort(int A[], int n, char *p)
{
	int i, j, tmp;
	char ctmp[2];
	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (*(A + j - 1) > *(A + j)) {
				tmp = *(A + j); *(A + j) = *(A + j - 1); *(A + j - 1) = tmp;
				ctmp[0] = *(p + j); *(p + j) = *(p + j - 1); *(p + j - 1) = ctmp[0];
			}
		}
	}
	for (i = 0; i < n; i++) printf("%c%d%c", p[i], A[i], i < n - 1 ? ' ' : '\n');
}

void SelectionSort(int A[],int n, char *p)
{
	int i,j,iMin,iTmp,tmp;
	char ctmp[2];
	for (i = 0; i < n - 1; i++) {
		iMin = iTmp = i;
		for (j = i; j < n; j++) {
			if (*(A + iMin) > *(A + j)) {
				iMin = j;
			}
		}
		if (iTmp != iMin) {
			tmp = *(A + i); *(A + i) = *(A + iMin); *(A + iMin) = tmp;
			ctmp[0] = *(p + i); *(p + i) = *(p + iMin); *(p + iMin) = ctmp[0];
		}
	}
	for (i = 0; i < n; i++) printf("%c%d%c", p[i], A[i], i < n - 1 ? ' ' : '\n');
	
}