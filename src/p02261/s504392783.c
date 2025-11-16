#include <stdio.h>
#include <string.h>
int main()
{
	int a = 0,b = 0,n, i, j, flag = 1, temp, minj,samecut = 0;
	char N1[36], B1[36], S1[36], strtemp;
	int N2[36], B2[36], S2[36];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %c", &N1[i]);
		S1[i] = N1[i];
		B1[i] = N1[i];
		scanf(" %d", &N2[i]);
		S2[i] = N2[i];
		B2[i] = N2[i];
	}
	while (flag) {
		flag = 0;
		for (j = n - 1; j > 0; j--) {
			if (B2[j] < B2[j - 1]) {
				strtemp = B1[j - 1];
				temp = B2[j - 1];
				B1[j - 1] = B1[j];
				B2[j - 1] = B2[j];
				B1[j] = strtemp;
				B2[j] = temp;
				flag = 1;
			}
		}
	}
	flag = 0;
	j = 0;
	for (i = 0; i < n; i++) {
		if (i)printf(" ");
		printf("%c%d", B1[i], B2[i]);
	}
	printf("\n");
	
	if (flag) {
		printf("Not stable\n");
	}
	else {
		printf("Stable\n");
	}
	for (i = 0; i <= n - 1; i++) {
		minj = i;
		for (j = i; j <= n - 1; j++) {
			if (S2[j] < S2[minj]) {
				minj = j;
			}
		}
		strtemp = S1[minj];
		temp = S2[minj];
		S1[minj] = S1[i];
		S2[minj] = S2[i];
		S1[i] = strtemp;
		S2[i] = temp;
	}
	for (i = 0; i < n; i++) {
		if (i)printf(" ");
		printf("%c%d", S1[i], S2[i]);
	}
	printf("\n");
	flag = 0;
	for (i = 0; i < n;i++) {
		if (B1[i] != S1[i]) {
			flag = 1;
		}
	}
	if (flag) {
		printf("Not stable\n");
	}
	else {
		printf("Stable\n");
	}
	return 0;
}
