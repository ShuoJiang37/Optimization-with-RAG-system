#include <stdio.h>

#define SIZE_MIN ( ( int ) 1 )
#define SIZE_MAX ( ( int ) 100 )
#define ELEMENT_MIN ( ( int ) 0 )
#define ELEMENT_MAX ( ( int ) 1000 )

typedef enum
{
	kSuccess,
	kError
}Result;

Result checkNumRange( int num, int min, int max );
void showArray( int *pArray, int size );
void execInsertionSort( int *pArray, int size );

int main( void )
{
	int i;
	int size;
	int array[SIZE_MAX];

	scanf( "%d", &size );
	if( checkNumRange( size, SIZE_MIN, SIZE_MAX ) == kError )
	{
		return -1;
	}

	for( i = 0; i < size; i++ )
	{
		scanf( "%d", &array[i] );
		if( checkNumRange( array[i], ELEMENT_MIN, ELEMENT_MAX ) == kError )
		{
			return -1;
		}
	}

	showArray( &array[0], size );
	execInsertionSort( &array[0], size );

	return 0;
}

Result checkNumRange( int num, int min, int max )
{
	return ( ( num >= min ) && ( num <= max ) ) ? kSuccess : kError;
}

void showArray( int *pArray, int size )
{
	int i;

	for( i = 0; i < size - 1; i++ )
	{
		printf( "%d ", pArray[i] );
	}
	printf( "%d\n", pArray[size - 1] );
}

void execInsertionSort( int *pArray, int size )
{
    int i;
	int j;
	int work;

	for( i = 1; i < size; i++ )
	{
		work = pArray[i];
		j = i - 1;

		while( ( j >= 0 ) && ( pArray[j] > work ) )
		{
			pArray[j + 1] = pArray[j];
			j--;
		}
		pArray[j + 1] = work;

		showArray( pArray, size );
	}
}

