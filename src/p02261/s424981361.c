#include<stdio.h>

struct Card {
	char suit;
	int number;
};

int main() {
	int i, j, n, flag = 0, minj;
	char s[5];
	struct Card c1[36], c2[36], v;
	scanf("%d", &n);
	for (i = 0; i < n; i++) { 
		scanf("%s", s);
		c1[i].suit = s[0];
		c1[i].number = atoi(s + 1);
		c2[i] = c1[i];
	}

	for (i = 0; i < n; i++) {
		for (j = n - 1; j >= i; j--) {
			if (c1[j].number < c1[j - 1].number) {
				v = c1[j];
				c1[j] = c1[j - 1];
				c1[j - 1] = v;
			}
		}
	}

	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (c2[j].number < c2[minj].number)minj = j;
		}
		v = c2[i];
		c2[i] = c2[minj];
		c2[minj] = v;
	}

	for (i = 0; i < n; i++) {
		printf("%c%d", c1[i].suit, c1[i].number);
		if (i != n - 1)printf(" ");
	}
	printf("\nStable\n");
	for (i = 0; i < n; i++) {
		printf("%c%d", c2[i].suit, c2[i].number);
		if (i != n - 1)printf(" ");
	}
	for (i = 0; i < n; i++) {
		if ((c1[i].suit != c2[i].suit) || (c1[i].number != c2[i].number)) { 
			flag = 1;
			break;
		}
	}
	if (flag == 1)printf("\nNot stable\n");
	else printf("\nStable\n");
	return 0;
}