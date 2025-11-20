#include <stdio.h>
#define N 36

typedef struct {
	char v;
	
	int n;}
	tmp;
	
int main () {
	int num, i, j, a, mini;
	tmp b[N], c[N], t;
	
	scanf("%d", &num);
	
	for ( i = 0; i < num; i++ ) {
		scanf("%c%c%d", &b[i].v, &b[i].v, &b[i].n);
		c[i] = b[i];
		}
		
	for ( i = 0; i < num; i++ ) {
		for ( j = num - 1; j >= i + 1; j-- ) {
			if ( b[j].n < b[j-1].n ) {
				t = b[j];
				b[j] = b[j-1];
				b[j-1] = t;
				}
			}
		}
			
			
	 for ( i = 0; i < num; i++ ) {
		mini = i;
		for ( j = i; j < num; j++ )
		if ( c[j].n < c[mini].n )
		mini = j;
		t = c[i];
		c[i] = c[mini];
		c[mini] = t;
		}
		
	for ( i = 0; i < num - 1; i++ ) {
		printf("%c%d ", b[i].v, b[i].n);
		}
	printf("%c%d\n", b[num-1].v, b[num-1].n);
	printf("Stable\n");
	
	for ( i = 0; i < num - 1; i++ ) {
		printf("%c%d ", c[i].v, c[i].n);
		}
	printf("%c%d\n", c[num-1].v, c[num-1].n);
	
	a = 1;
	
	for ( i = 0; i < num; i++ )
	if ( b[i].v != c[i].v )
	a = 0;
	
	if ( a == 1 )
	printf("Stable\n");
	
	else
	printf("Not stable\n");
	
	return 0;
}
