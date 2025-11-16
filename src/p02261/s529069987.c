#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100

struct card {
	char suite;
	int number;
	int order;
};

int check = 1;

int
card_key(void *arg)
{
	return ((struct card *)arg)->number;
}

void
print_card(struct card *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s%c%d", i ? " " : "", a[i].suite, a[i].number);
	printf("\n");
}

int
bubble_sort(struct card *a, int n, int (*key)(void *))
{
	int i, flag = 1;
	struct card v;

	while (flag) {
		flag = 0;
		for (i = n - 1; i > 0;i--) {
			if (key(&a[i]) < key(&a[i - 1])) {
				v = a[i];
				a[i] = a[i - 1];
				a[i - 1] = v;
				flag = 1;
			}
		}
	}
}

void
selection_sort(struct card *a, int n, int (*key)(void *))
{
	int i, j, minj;
	struct card v;

	for (i = 0; i < n; i++) {
		if (i &&
		    (key(&a[i]) == key(&a[i - 1])) &&
		    (a[i].order < a[i-1].order))
			check = 0;
		minj = i;
		for (j = i + 1; j < n; j++)
			if (key(&a[j]) < key(&a[minj]))
				minj = j;
		if (i != minj) {
			v = a[i];
			a[i] = a[minj];
			a[minj] = v;
		}
	}
}

int
main(void)
{
	int p0, n = 0;
	struct card a[N_MAX];
	struct card b[N_MAX];
	char name[8];

	scanf("%d", &p0);

	if (p0 < 1 || N_MAX < p0)
		return 1;

	for (n = 0; n < p0; n++) {
		scanf("%s", name);
		a[n].suite = name[0];
		sscanf(name+1, "%d", &a[n].number);
		a[n].order = n;
	}
	memcpy(b, a, sizeof(a));

	bubble_sort(a, n, card_key);
	print_card(a, n);
	printf("%s\n", "Stable");

	selection_sort(b, n, card_key);
	print_card(b, n);
	printf("%s\n", check ? "Stable" : "Not stable");

	return 0;
}

