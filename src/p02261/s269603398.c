#include <stdio.h>

struct card {
	char s;
	int n;
};


int main(void)
{
	struct card a[200], b[200], c[200], tmt;
	int num, i, j, flag, minj;

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf(" %c%d", &a[i].s, &a[i].n);
		b[i].s = a[i].s;
		c[i].s = a[i].s;
		b[i].n = a[i].n;
		c[i].n = a[i].n;
	}
	

	for (i = 0; i < num; i++) {
			for (j = num - 1; j > i; j--) {
				if (b[j].n < b[j - 1].n) {
					tmt = b[j];
					b[j] = b[j - 1];
					b[j - 1] = tmt;
				}
			}
		
	}

	for (i = 0; i < num; i++) {
		minj = i;
		for (j = i; j < num; j++) {
			if (c[j].n < c[minj].n) {
				minj = j;
			}
		}
		tmt = c[i];
		c[i] = c[minj];
		c[minj] = tmt;
	}

	for (i = 0; i < num; i++) {
		printf("%c%d", b[i].s, b[i].n);

		if (i != num - 1) {
			putchar(' ');
		}
		else {
			putchar('\n');
		}
	}

	printf("Stable\n");

	for (i = 0; i < num; i++) {
		printf("%c%d", c[i].s, c[i].n);

		if (i != num - 1) {
			putchar(' ');
		}
		else {
			putchar('\n');
		}
	}

	for (i = 0; i < num; i++) {
		if (b[i].s != c[i].s) {
			printf("Not stable\n");
			break;
		}
	}

	if (i == num) {
		printf("Stable\n");
	}

	return 0;	
}

