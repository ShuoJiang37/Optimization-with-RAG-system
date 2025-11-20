#include <stdio.h>

long long k;
int l=0;
int a[1000000];
int n;
int g[1000000];

void insertionsort(int a[], int n, int g)
{
	int i, v, j;
	for(i = g; i < n; i++){
		v = a[i];
		j = i - g;
		while(j >= 0 && a[j] > v){
			a[j+g] = a[j];
			j-=g;
			k++;
		}
		a[j+g] = v;
	}
}

void shellsort(int a[], int n)
{
	int h, j;
	for(h = 1; ;){
		if(h > n)break;
		g[l] = h;
		h = 3*h+1;
		l++;
	}
	for(j = l-1; j >= 0; j--){
		insertionsort(a, n, g[j]);
	}
}

int main(void)
{
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	k = 0;
	
	shellsort(a, n);
	
	printf("%d\n", l);
	
	for(i = l-1; i >= 0; i--){
		printf("%d", g[i]);
		if(i!=0)printf(" ");
	}
	printf("\n");
	printf("%d\n", k);
	
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}
	
	return 0;
}

