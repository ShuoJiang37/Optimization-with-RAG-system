#include <stdio.h>

void bubble(char cards[36][3], int n) {
	int i, j;
	char tmp[2];

	for (i = 0; i < n; i++) {
		for (j = n-1; j > i; j--) {
			if (cards[j][1] < cards[j-1][1]) {
				tmp[0] = cards[j][0];
				tmp[1] = cards[j][1];
				cards[j][0] = cards[j-1][0];
				cards[j][1] = cards[j-1][1];
				cards[j-1][0] = tmp[0];
				cards[j-1][1] = tmp[1];
			}
		}
	}
}


void selection(char cards[36][3], int n) {
	int i, j, mini;
	char tmp[2];

	for (i = 0; i < n; i++) {
		mini = i;
		for (j = i; j < n; j++) {
			if (cards[j][1] < cards[mini][1]) {
				mini = j;
			}
		}
		if (i != mini) {
			tmp[0] = cards[i][0];
			tmp[1] = cards[i][1];
			cards[i][0] = cards[mini][0];
			cards[i][1] = cards[mini][1];
			cards[mini][0] = tmp[0];
			cards[mini][1] = tmp[1];
		}
	}
}


int stable_test(char orders[9][4], char cards[36][3], int n) {
	int i, j, k, now, prev;

	for (i = 0; i < 9; i++) {
		if (!orders[i][0])
			continue;
		now = -1;
		for (j = 0; j < 4; j++) {
			prev = now;
			for (k = 0; k < n; k++) {
				if (cards[k][1]-'1' == i && cards[k][0] == orders[i][j]) {
					now = k;
					break;
				}
			}
			if (prev > now)
				return 0;
		}
	}
	return 1;
}


void print_result(char cards[36][3], int n, int stable) {
	int i;
	const char *fmt = "%s";

	for (i = 0; i < n; i++) {
		printf(fmt, cards[i]);
		fmt = " %s";
	}
	puts(stable ? "\nStable" : "\nNot stable");
}


int main(void) {
	int n, cnum, i, stable;
	char data1[36][3], data2[36][3];
	char orders[9][4] = {{0}};
	int state[9] = {0};

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %s", data1[i]);
		data2[i][0] = data1[i][0];
		data2[i][1] = data1[i][1];
		data2[i][2] = '\0';
		cnum = data1[i][1] - '1';
		orders[cnum][state[cnum]] = data1[i][0];
		state[cnum] += 1;
	}

	bubble(data1, n);
	stable = stable_test(orders, data1, n);
	print_result(data1, n, stable);

	selection(data2, n);
	stable = stable_test(orders, data2, n);
	print_result(data2, n, stable);
	return 0;
}