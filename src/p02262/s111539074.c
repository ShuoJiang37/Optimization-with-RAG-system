#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void insertionsort( int a[] , int n , int g );
void shellsort( int a[] , int n );
int distance( int n );
void sequence( int m , int g[] );

int cnt = 0;

int main( void ){
	
	int n , m;
	int *a;
	int i;
	int g[100];
	
	scanf( "%d" , &n );
	
	a = (int*)malloc( n * sizeof(int) );
	if( a == 0 ){
		fprintf( stderr , "メモリ確保エラー\n" );
		exit(1);
	}
	
	for( i = 0; i < n; i++ ){
		scanf( "%d" , &a[i] );
	}

	m = distance( n );
	printf( "%d\n" , m );
	
	sequence( m , g );
	for( i = 0; i < m; i++ ){
		printf( "%d " , g[i] );
	}
	printf( "\n" );
	
	shellsort( a , n );
	
	printf( "%d" , cnt );
	printf( "\n" );
	
	for( i = 0; i < n; i++ ){
		printf( "%d\n" , a[i] );
	}
	
	free(a);
	
	return 0;

}

void insertionsort( int a[] , int n , int g ){
	
	int i , j;
	int v;
	
	for( i = g;  i < n; i++ ){
		
		v = a[i];
		j = i - g;
		
		while( j >= 0 && a[j] > v ){
			a[j+g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j+g] = v;
	}
}

void shellsort( int a[] , int n ){
	
	int m;
	int g[100];
	int i;
	
	m = distance(n);
	sequence( m , g );
	
	for( i = 0; i < m; i++ ){
		insertionsort( a , n , g[i] );
	}
	
}

int distance( int n ){
	
	int m;
	
	m = (int)( log( 2 * n + 1 ) / log( 3 ) );
	
	return m;
}

void sequence( int m , int g[] ){
	
	int i;
	
	g[m-1] = 1;
	for( i = m - 2; i >= 0; i-- ){
		g[i] = g[i+1] * 3 + 1;
	}
	
}
