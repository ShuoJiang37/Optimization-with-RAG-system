#include <stdio.h>

#define MAX 100


typedef struct {
	char sign;
	int value;
}Card;

void change_int(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void change_char(char *a, char *b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int selectionSort(Card a[], int n)
{
	int i,j;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		int minj = i;
		for (j = i; j < n; j++) {
			if (a[j].value < a[minj].value)
				minj = j;
		}
		if (minj != i) {
			change_int(&a[i].value, &a[minj].value);
			change_char(&a[i].sign, &a[minj].sign);
			cnt++;
		}
	}
	return cnt;
}

int bubbledSort(Card a[], int n)
{
	int flag = 1;
	int j;
	int cnt = 0;
	while (flag) {
		flag = 0;
		for (j = n - 1; j > 0; j--) {
			if (a[j].value < a[j - 1].value) {
				change_int(&a[j].value, &a[j - 1].value);
				change_char(&a[j].sign, &a[j - 1].sign);
				cnt++;
				flag = 1;
			}
		}
	}
	return cnt;
}


void print_a(Card a[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		printf("%c", a[i].sign);
		printf("%d ", a[i].value);
		
	}
	printf("%c%d\n",a[n-1].sign, a[n - 1].value);
}

void conversion(char s[][3],Card card[],int n) {
	int i;
	for (i = 0; i < n; i++) {
		card[i].sign = s[i][0];
		card[i].value = (int)s[i][1] - '0';
	}
}

int isStable(Card a[], Card b[],int n) {
	int i,flag;
	flag = 1;
	for (i = 0; i < n; i++) {
		if (a[i].sign != b[i].sign || a[i].value != b[i].value)
			flag = 0;
	}
	return flag;
}
int main()
{
	int n,i,cnt;

	char s[MAX][3];


	Card card1[MAX];

	Card card2[MAX];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	
	conversion(s, card1, n);
	bubbledSort(card1, n);
	print_a(card1, n);
	printf("Stable\n");
	conversion(s, card2, n);
	selectionSort(card2, n);
	print_a(card2, n);
	if (isStable(card1,card2,n))
		printf("Stable\n");
	else
		printf("Not stable\n");
	return 0;

}
