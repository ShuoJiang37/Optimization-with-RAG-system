#include<stdio.h>
#include<string.h>

void trace( char A[][3], int n )
{
	int i=0;
	while( i<n ) {
		printf( "%s", A[i++] );
		if( i != n ) { printf( " " ); }
	}
	printf( "\n" );
	
	return;
}

void BubbleSort( char A[][3], int n ) 
{
	int i,j;
	char tmp[3];

	for( i=0; i<n; i++ ) {
		for( j=n-1; i<j; j-- ) {
			if( A[j][1]-'0' < A[j-1][1]-'0' ) {
				strncpy( tmp, A[j-1], 3 );
				strncpy( A[j-1], A[j], 3 );
				strncpy( A[j], tmp, 3 );
			}
		}
	}
	
	trace( A, n );
	
	return;
}

void SelectionSort( char A[][3], int n ) 
{
	int i,j;
	char tmp[3];
	int mini;
	
	for( i=0; i<n; i++ ) {
		mini=i;
		for( j=i; j<n; j++ ) {
			if( A[j][1]-'0' < A[mini][1]-'0' ) {
				mini=j;
			}
		}
		if( mini != i ) {
			strncpy( tmp, A[i], 3 );
			strncpy( A[i], A[mini], 3 );
			strncpy( A[mini], tmp, 3 );
		}
	}
	
	trace( A, n );
	
	return;
}

int main( void ) 
{
	int n;
	char cards[37][3];
	char cards2[37][3];	
	int i;

	scanf( "%d", &n );
	for( i=0; i<n; i++ ) {
		scanf( "%s", cards[i] );
		strncpy( cards2[i], cards[i], 3 );
	}
	
	BubbleSort( cards, n );
	printf( "Stable\n" );

	SelectionSort( cards2, n );
	for( i=0; i<n; i++ ) {
		if( cards[i][0] != cards2[i][0] ) {
			break;
		}
	}
	if( n != i ) {
		printf( "Not stable\n" );
	} else {
		printf( "Stable\n" );
	}
	
	return 0;
}