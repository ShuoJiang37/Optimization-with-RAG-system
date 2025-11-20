#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int n, a[MAX], b[MAX];
char c[MAX][3], d[MAX][3];
char *s;
char t[256];

 

void swap_str(char *sx, char *sy)
{
	char tmp[MAX];
	
	strcpy(tmp,sx);
	strcpy(sx,sy);
	strcpy(sy,tmp);
}
void swap_int(int *x, int *y)
{
	int tmp = *x;
	*x =*y ;
	*y = tmp;
}

void print1()
{
	int i;
	
	for (i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%s",c[i]);
	}
	printf("\n");
}

void print2()
{
	int i;
	
	for (i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%s",d[i]);
	}
	printf("\n");
}

void bubbleSort()
{
	int i, tmp, flag;

	flag = 1;
	while (flag) 
	{
		flag = 0;
		for (i = n - 1; i > 0; i--) 
		{
			if (a[i] < a[i - 1]) 
			{
				swap_str(c[i], c[i-1]);
				swap_int(&a[i], &a[i-1]);
				flag = 1;
			}
		}
	}
}
void selectionSort()
{
	int i, j, tmp, minj;
	
	for (i = 0; i < n; i++) {
		minj = i;
		
		for (j = i; j < n; j++) {
			if (b[j] < b[minj]) {
				minj = j;
			}
		}
		if(i != minj)
		{
			swap_str(d[i], d[minj]);
			swap_int(&b[i], &b[minj]);
		}
		
	}
	
}

int main()
{
	int i;
	
	scanf("%d",&n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%s", &c[i]);
		b[i] = a[i] = (int)(c[i][1] - '0');
		strcpy(d[i], c[i]);
	}
	
	bubbleSort();
	print1();
	printf("Stable\n");
	selectionSort();
	print2();
	
	for (i = 0; i < n; i++)
	{
		if (c[i][0] != d[i][0])
		{
			printf("Not stable\n");
			return 0;
		}
	}
	printf("Stable\n");
	

return 0;
}
