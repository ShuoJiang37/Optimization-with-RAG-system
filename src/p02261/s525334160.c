#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char mark;
	char num;  //ここの数字が０のときはカード終端ということで
	char id;
} trumpcard;

trumpcard a[50], b[50];

int getn()
{
	int n = 0;
	char tmp;
	while ( '0' <= (tmp = getchar()))
		n =n * 10 + tmp - '0' ;

	return n;
}

void getcarddata(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i].mark = getchar();
		a[i].num = getchar();
		a[i].id = i;
		getchar();
	}
	a[i].num = 0;
}

void swapcard(trumpcard *d, int i, int j)
{
	trumpcard tmp;
	tmp = d[i];
	d[i] = d[j];
	d[j] = tmp;
}

void bubble_sort(trumpcard *d, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = n-1; i<j; j--)
			if (d[j].num < d[j-1].num)
				swapcard(d, j, j-1);
}

void selection_sort(trumpcard *d, int n)
{
	int i,j, minj;
	for (i = 0; i <n; i++){
		minj = i;
		for (j = i; j < n; j++)
			if (d[j].num < d[minj].num)
				minj = j;
		swapcard(d, i, minj);
	}
}

int check_stable(trumpcard *d, int n)
{
	int flag = -1;
	for (int i =0; i < n-1; i++)
		if ((d[i].num == d[i+1].num && d[i].id > d[i+1].id))
			flag = 0;
	return flag;
}

void print_card(trumpcard *d, int n)
{
	for (int i=0; i<n; i++)
	{
		if(i != 0)
			printf(" ");
		printf("%c%c", d[i].mark, d[i].num);
	}
	printf("\n");
}



int main(void)
{
	int n = getn();
	getcarddata(n);
	memcpy(b, a, sizeof(trumpcard)*n);

	bubble_sort(a, n);
	selection_sort(b,n);

	print_card(a,n);
	printf("%s\n", (check_stable(a, n))?"Stable":"Not stable");
	print_card(b,n);
	printf("%s\n", (check_stable(b, n))?"Stable":"Not stable");


	return 0;
}

