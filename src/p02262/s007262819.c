#include<stdio.h>

void trace( int *A, int n )
{
	int i=0;
	while( i<n ) {
		printf( "%d\n", A[i++] );
	}
	
	return;
}

int insertionSort( int *A, int n, int g )
{
	int i,j;
	int v;
	int cnt;
	
	cnt=0;
  	for( i=g; i<n; i++ ) {
  		v=A[i];
  		j = i-g;
  		while( 0<=j && v<A[j] ) {
  			A[j+g] = A[j];
  			j=j-g;
  			cnt++;
  		}
  		A[j+g] = v;
   	}
  
	return cnt;
}

void shellSort( int *A, int n )
{
	int cnt;
	int m;
	int i;
	int G[101];

	m=n/3;
	if( m < 1 ) {
		G[0]=1;
		m=1;
	} else {
		G[0]=m*3;
		for( i=1; G[i-1]<=n; i++ ) {
			G[i]=G[i-1]/3;
			if( G[i] <= 1 ) {
				G[i]=1;
				m=i+1;
				break;
			}
		}
	}
  	printf( "%d\n", m );  	
	for( i=0; i<m; i++ ) {
	  	printf( "%d", G[i] );
	  	if( m-1 != i ) {
	  		printf( " " );
	  	}
	}
	printf( "\n" );	

  	cnt=0;
  	for( i=0; i<m; i++ ) {
  		cnt+=insertionSort( A, n, G[i] );
  	}
  	
  	printf( "%d\n", cnt );

	return;
}

int main( void ) 
{
	int n;
	int A[1000001];
	int i;

	scanf( "%d", &n );
	for( i=0; i<n; i++ ) {
		scanf( "%d", &A[i] );
	}
	
	shellSort( A, n );
	trace( A, n );
	
	return 0;
}