#include<stdio.h>
#include<string.h>

typedef struct Card{
	char type;
	int num;
}card;

int main(void)
{
	int i, s,  n, min, c;
	c = 0;
	
	scanf( "%d", &n );
	card a[n];
	card b[n];
	card x;
	for( i = 0; i < n; i++ ){
		scanf( " %c%d", &a[i].type, &a[i].num );
		b[i] = a[i];
	}
	
	for( i = 0; i < n; i++ ){
		for( s = n-1; s > i; s-- ){
			if( a[s].num < a[s-1].num ){
				x = a[s];
				a[s] = a[s-1];
				a[s-1] = x;
			}
		}
	}
	
	for( i = 0; i < n; i++ ){
		min = i;
		for( s = i; s < n; s++ ){
			if( b[s].num < b[min].num ){
				min = s;
			}
		}
		if( i != min ){
			x = b[i];
			b[i] = b[min];
			b[min] = x;
		}
	}
	
	printf( "%c%d", a[0].type, a[0].num );
	for( i = 1; i < n; i++ ){
		printf( " %c%d", a[i].type, a[i].num );
	}
	printf( "\nStable\n" );
	
	printf( "%c%d", b[0].type, b[0].num );
	for( i = 1; i < n; i++ ){
		printf( " %c%d", b[i].type, b[i].num );
	}
	
	for( i = 0; i < n; i++ ){
		if( a[i].type == b[i].type ){
			if( a[i].num == b[i].num ){
			}else{
				c = 1;
			}
		}else{
			c = 1;
		}
	}
	
	if( c == 0 ){
		printf( "\nStable\n" );
	}else{
		printf( "\nNot stable\n");
	}
	
	return 0;
}
