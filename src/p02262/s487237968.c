

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(){

	int i, j, k, t;
	int n;
	int a[1000000], g[1000000];
	int cnt, m, v;

	// input
	scanf( "%d", &n );
	for( i=0; i<n; i++ ){ 
		scanf( "%d", &a[i] );
	}


	// g = g[i+1] + pow(3,i)
	g[0]=1; m=1; i=0;
	while( g[i] <= n ){
		i++; m++;
		g[i] = pow(3,i) + g[i-1];
	}

	printf( "%d\n", m-1 );
	for( i=m-2; i>=0; i-- ) 
		printf( "%d%c", g[i], i!=0?' ':'\n' );


	//
	cnt=0;
	for( i=m-2; i>=0; i-- ){
		for( k=g[i]; k<n; k++ ){
			v = a[k];
			j = k - g[i];

			while( j>=0 && a[j]>v ){
				a[j+g[i]] = a[j];
				j = j - g[i];
				cnt++;
			}
	
			a[j+g[i]] = v;

		}
	}
	
	printf( "%d\n", cnt );


	//
	for( i=0; i<n; i++ ) 
		printf( "%d\n", a[i] );

	return 0;

}