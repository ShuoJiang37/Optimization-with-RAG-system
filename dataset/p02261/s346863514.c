#include <stdio.h>

struct card
{
	char suit;
	int num;
};

int bubbleSort(struct card C[], int num)
{
	struct card temp;
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = num - 1; j >= i + 1; j--)
		{
			if (C[j].num < C[j - 1].num)
			{
				temp = C[j - 1];
				C[j - 1] = C[j];
				C[j] = temp;
				cnt++;
			}
		}
	}
	return cnt;
}


int insertSort(struct card C[], int num)
{
	struct card temp;
	int cnt = 0, min = 0;
	for (int i = 0; i < num; i++)
	{
		min = i;
		for (int j = i; j < num; j++)
		{
			if (C[j].num < C[min].num)
			{
				min = j;
			}
		}
		if (i != min) cnt++;
		temp = C[i];
		C[i] = C[min];
		C[min] = temp;
	}

	return cnt;
}

int isstable(struct card C1[], struct card C2[], int num)
{
	for (int i = 0; i < num; i++)
	{
		if (C1[i].suit != C2[i].suit) return -1;
	}
	return 1;
}




int main()
{
	struct card C1[100];
	struct card C2[100];
	int num, temp_n,re = 0;
	char temp_c;

	scanf(" %d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf(" %c %d", &temp_c, &temp_n);
		C1[i].suit = temp_c;
		C1[i].num = temp_n;
		C2[i].suit = temp_c;
		C2[i].num = temp_n;
	}

	bubbleSort(C1, num);
	insertSort(C2, num);

	for (int i = 0; i < num; i++)
	{
		printf("%c%d", C1[i].suit, C1[i].num);
		if (i < num - 1) printf(" ");
	}
	printf("\nStable\n");

	for (int i = 0; i < num; i++)
	{
		printf("%c%d", C2[i].suit, C2[i].num);
		if (i < num - 1) printf(" ");
	}

	if ((re = isstable(C1, C2, num)) == -1) printf("\nNot stable\n");
	else printf("\nStable\n");

	return 0;
}


