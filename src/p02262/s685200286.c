#include<stdio.h>


int insertionsort(int a[], int n, int g, int cnt)
{
	int v, j, i;
	for(i=g; i<n; i++){
		v = a[i];
		j = i-g;
		while (j>=0 && a[j]>v){
			a[j+g] = a[j];
			j=j-g;
			cnt++;
		}
		a[j+g] = v;
	}
	return cnt;
}


void shellsort(int a[], int n)
{
	int i;
	int cnt = 0;
	int g[n];
	int m = 0;
	
	for(int h=1; ;){
		if(h > n) break;
		g[m] = h;
		h = 3*h+1;
		m++;
	}
	
	printf("%d\n", m);
	
	for(i=m-1; i>=0; i--){
		if(i != m-1) printf(" ");
		printf("%d", g[i]);
	}
	printf("\n");
	
	for(i=m-1; i>=0; i--){
		cnt = insertionsort(a, n, g[i],cnt);
	}
	printf("%d\n", cnt);
	for(i=0; i<n; i++){
		printf("%d\n", a[i]);
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	int a[n];
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	shellsort(a, n);
	
	
	return 0;
}

