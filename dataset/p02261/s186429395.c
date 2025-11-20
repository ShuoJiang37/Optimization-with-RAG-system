#include <stdio.h>

	struct card{
		char suit;
		int value;
	};
	
	int main() {
		int n, i, j, min, s;
		char k;
		struct card x[36],y[36],z;
		
		scanf("%d\n", &n);
		
		for( i = 0; i < n; i++) {
			scanf("%c%d", &x[i].suit, &x[i].value);
			scanf("%c",&k);
		}
		
		for( i = 0; i < n; i++) {
			y[i] = x[i];
		}
		
		for( i = 0; i < n; i++) {
			for( j = n-1; j > i; j--) {
				if( x[j].value < x[j-1].value) {
					z = x[j];
					x[j] = x[j-1];
					x[j-1] = z;
				}
			}
		}
		
		for( i = 0; i < n; i++) {
			min = i;
			for( j = i; j < n; j++) {
				
				if(y[j].value < y[min].value) {
					min = j;
				}
			}
			z = y[i];
			y[i] = y[min];
			y[min] = z;
		}
		
		for( i = 0; i < n-1; i++) {
			printf("%c%d ", x[i].suit,x[i].value);
		}
		printf("%c%d\n", x[n-1].suit,x[n-1].value);
		printf("Stable\n");
		
		for( i = 0; i < n-1; i++) {
			printf("%c%d ", y[i].suit, y[i].value);
		}
		printf("%c%d\n", y[n-1].suit, y[n-1].value);
		
		s = 1;
		
		for( i = 0; i < n; i++) {
			if( x[i].suit != y[i].suit) {
				s = 0;
			}
		}
		if( s == 0) {
			printf("Not stable\n");
		}else{
			printf("Stable\n");
		}
		
		return 0;
		
	}
	