#include<stdio.h>

int main(void)
{
	int n, i, c1, c2, s, t, x, y;
	c1 = 0;
	c2 = 0;
	scanf( "%d", &n );
	int a[n];
	int g[100];
	g[0] = 1;
	
	for( i = 0; i < n; i++ ){
		scanf( "%d", &a[i] );
	}
	
	for( c2 = 0; g[c2]*3+1 < n; c2++ ){
		g[c2+1] = g[c2] * 3 + 1;
	}
	
		for( s = c2; s >= 0; s-- ){
			for( t = g[s]; t < n; t++ ){
				x = a[t];
				y = t - g[s];
				while( y >= 0 && a[y] > x ){
					a[y+g[s]] = a[y];
					y = y - g[s];
					c1++;
				}
				a[y+g[s]] = x;
			}
		}
	
	printf( "%d\n", c2+1 );
	for( i = c2; i > 0; i-- ){
		printf( "%d ", g[i] );
	}
	printf( "%d\n%d\n", g[0], c1 );
	
	for( i = 0; i < n; i++ ){
		printf( "%d\n", a[i] );
	}
	
	return 0;
}
