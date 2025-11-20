#include <stdio.h>

int is_Stable(char b[36][2], char s[36][2], int n){
	int i;
	int stable = 1;

	for (i = 0; i < n; i++) {
		if (b[i][1] == s[i][1] && b[i][0] != s[i][0]) {
			stable = 0;
		}
	}

	return stable;
}

int main(void){
	int n, i, j, k, rec,  min;
	char a[36][2], b[36][2], s[36][2], tmp[2];
	int stable = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
		for (k = 0; k < 2; k++) {
			b[i][k] = a[i][k];
			s[i][k] = a[i][k];
		}
	}

	//Bubble_Sort
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (b[j][1] < b[j - 1][1]) {
				for (k = 0; k < 2; k++) {
					tmp[k] = b[j][k];
					b[j][k] = b[j - 1][k];
					b[j - 1][k] = tmp[k];
				}
			}
		}
	}

	//Selection_Sort
	for (i = 0; i < n - 1; i++) {
		min = s[i][1];
		rec = i;
		for (j = i; j < n; j++) {
			//Min
			if (min > s[j][1]) {
				min = s[j][1];
				rec = j;
			}
		}
		//Change
		if (i != rec) {
			for (k = 0; k < 2; k++) {
				tmp[k] = s[i][k];
				s[i][k] = s[rec][k];
				s[rec][k] = tmp[k];
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%c%c", b[i][0], b[i][1]);
		if (i != n - 1) {
			putchar(' ');
		}
	}
	putchar('\n');

	printf("Stable\n");

	stable = is_Stable(b, s, n);

	for (i = 0; i < n; i++) {
		printf("%c%c", s[i][0], s[i][1]);
		if (i != n - 1) {
			putchar(' ');
		}
	}
	putchar('\n');

	if (stable == 1) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}
	
	return 0;
}

