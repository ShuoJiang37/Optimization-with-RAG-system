#include<stdio.h>

typedef struct{
	char mark;
	int number;
}card;

void bubblesort( card c[] , int n );
void selectionsort( card c[] , int n );
int stablesort( card c1[] , card c2[] , int n );

int main( void ){
	
	card c1[36] , c2[36];
	int n;
	int i;
	
	scanf( "%d" , &n );
	
	for( i = 0; i < n; i++ ){
		scanf( " %c%d" , &c1[i].mark , &c1[i].number );
	}
	
	for( i = 0; i < n; i++ ){
		c2[i] = c1[i];
	}
	
	bubblesort( c1 , n );
	for( i = 0; i < n; i++ ){
		if( i > 0 ){ printf( " " ); } 
		printf( "%c%d" , c1[i].mark , c1[i].number );
	}
	printf( "\n" );
	printf( "Stable\n" );

	selectionsort( c2 , n );
	for( i = 0; i < n; i++ ){
		if( i > 0 ){ printf( " " ); } 
		printf( "%c%d" , c2[i].mark , c2[i].number );

	}
	printf( "\n" );
	
	if( stablesort( c1 , c2 , n ) == 1 ){
		printf( "Stable\n" );
	}else{
		printf( "Not stable\n" );
	}
	
	return 0;
}

void bubblesort( card c[] , int n ){
	
	card temp;
	int i , j;
	
	for( i = 0; i < n; i++ ){
		
		for( j = n - 1; j > i; j-- ){
			
			if( c[j].number < c[ j - 1 ].number ){
				temp = c[j];
				c[j] = c[j - 1];
				c[j - 1] = temp;
			}
		}
	}
}

void selectionsort( card c[] , int n ){
	
	card temp;
	int i , j;
	int min;
	
	for( i = 0; i < n; i++ ){
		
		min = i;
		
		for( j = i; j < n; j++ ){
			
			if( c[j].number < c[min].number ){
				min = j;
			}
		}
			
		temp = c[i];
		c[i] = c[min];
		c[min] = temp;
		
	}
}
	
int stablesort( card c1[] , card c2[] , int n ){
	
	int i;
	
	for( i = 0; i < n; i++ ){
		if( c1[i].mark != c2[i].mark ){ return 0; }
	}
	
	return 1;
}


