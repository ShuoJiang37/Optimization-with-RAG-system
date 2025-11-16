#include <stdio.h>

typedef struct {
	char kind;
	int value;
} card;

void print( card , int );

int main( void ){
	int i, j, n, minj, cnt;
	card tmp;
	
	scanf("%d", &n );
	
	card c1[n], c2[n];
	
	for( i = 0; i < n; i++ ){
		c1[i].kind = 't';
		c2[i].kind = 't';
		c1[i].value = 0;
		c2[i].value = 0;
	}
	
	for( i = 0; i < n; i++ ){
		scanf(" %c%d", &c1[i].kind, &c1[i].value );
		c2[i].kind = c1[i].kind;
		c2[i].value = c1[i].value;
	}

	for( i = 0; i < n; i++ ){
		for( j = n-1; j >= i+1; j-- ){
			if( c1[j].value < c1[j-1].value ){
				tmp = c1[j];
				c1[j] = c1[j-1];
				c1[j-1] = tmp;
			}
		}
	}
	
	for( i = 0; i < n; i++ ){
		if( i != n-1 ){
			printf("%c%d ", c1[i].kind, c1[i].value );
		}
		else{
			printf("%c%d\n", c1[i].kind, c1[i].value );
		}
	}
	printf("Stable\n");
	
	for( i = 0; i < n; i++ ){
		minj = i;
		for( j = i; j < n; j++ ){
			if( c2[j].value < c2[minj].value ){
				minj = j;
			}
		}
		
		tmp = c2[i];
		c2[i] = c2[minj];
		c2[minj] = tmp;
	}
	
	for( i = 0; i < n; i++ ){
		if( i != n-1 ){
			printf("%c%d ", c2[i].kind, c2[i].value );
		}
		else{
			printf("%c%d\n", c2[i].kind, c2[i].value );
		}
	}
	
	cnt = 0;
	for( i = 0; i < n; i++ ){
		if( c1[i].kind == c2[i].kind && c1[i].value == c2[i].value ){
			cnt++;
		}
	}
	if( cnt == n ){
		printf("Stable\n");
	}
	else{
		printf("Not stable\n");
	}
	
	return 0;
}

