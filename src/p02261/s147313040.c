#include<stdio.h>
 
int main(void)
{
	int n, C[10000], A[10000], B[10000];
	char a[10000];
	char b[10000];
	char c[10000];
	char tmpc;
	int i, j, k, l, tmp, minj = 0;
	int flag = 0;

	scanf("%d", &n);

	(void)getchar();

	for (i = 0;i < n;i++) {

		scanf("%c", &a[i]);
		scanf("%d", &A[i]);
		(void)getchar();
	}
	
	for (i = 0;i < n;i++) {
		B[i] = A[i];
		C[i] = A[i];
		b[i] = a[i];
		c[i] = a[i];
	}

	for (i = 1;i < n;i++) {
		for (j = n - 1;j >= 0;j--) {
			if (C[j] < C[j - 1]) {
				
				tmp = C[j];
				tmpc = c[j];
				C[j] = C[j - 1];
				c[j] = c[j - 1];
				C[j - 1] = tmp;
				c[j - 1] = tmpc;
			}
		}
	}

	for (k = 0;k < n;k++) {
		printf("%c%d", c[k], C[k]);
		if (k != n - 1) {
			printf(" ");
		}else {
			printf("\n");
		}
	}


		printf("Stable\n");
	

	for (i = 0;i <= n - 1;i++) {
		minj = i;
		for (j = i;j <= n - 1;j++) {
			if (B[j] < B[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			tmp = B[i];
			tmpc = b[i];
			B[i] = B[minj];
			b[i] = b[minj];
			B[minj] = tmp;
			b[minj] = tmpc;
		}
	}

	for (k = 0;k < n;k++) {
		printf("%c%d", b[k], B[k]);
		if (k != n - 1) {
			printf(" ");
		}
		else {
			printf("\n");
		}
	}

	for (i = 0; i < n - 1; i++) {
		if(c[i] != b[i]){
			flag++;
		}
	}

	if (flag != 0) {
		printf("Not stable\n");
	}
	else {
		printf("Stable\n");
	}




	return 0;
}
 

