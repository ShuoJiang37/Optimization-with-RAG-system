#include <stdio.h>

#define MAX_N 1000000
#define MAX_M 100

void ShellSort( int*, int );
void InsertionSort( int*, int, int );
void print( int*, int*, int, int );

int cnt;

int main( void ){
	int i, n;
	
	scanf("%d", &n );
	
	int a[MAX_N];
	
	for( i = 0; i < n; i++ ){
		scanf("%d", &a[i] );
	}
	
	ShellSort( a, n );
	
	return 0;
}

void ShellSort( int a[], int N ){
	int i, m, p;
	int b[MAX_M];
	cnt = 0;
	
	for( m = 1; m*3+1<N; m = m*3+1){}
	
	p = 0;
	for(; m > 0; m /= 3){
		b[p++] = m;
	}
	
	if( p > 100 ){
		p = 100;
	}
	
	for( i = 0; i < p; i++ ){
		InsertionSort( a, N, b[i] );
	}
	print(a, b, N, p);
}

void InsertionSort( int a[], int N, int b ){
	int i, j, v;
	
	for( i = b; i < N; i++ ){
		v = a[i];
		j = i - b;
		while( j >= 0 && a[j] > v ){
			a[j+b] = a[j];
			j -= b;
			cnt++;
		}
		a[j+b] = v;
	}
}

void print( int a[], int b[], int N, int m ){
	int i;
	
	printf("%d\n", m );
	for( i = 0; i < m; i++ ){
		if( i != m-1 ){
			printf("%d ", b[i] );
		}
		else{
			printf("%d\n", b[i] );
		}
	}
	printf("%d\n", cnt );
	for( i = 0; i < N; i++ ){
		printf("%d\n", a[i] );
	}
}

