

#include <stdio.h>
#include <string.h>

struct card{
	char	s;
	int	v;
	int	i;
};
typedef struct card CARD;


int swap( CARD *c1, CARD *c2 ){

	CARD t;

	t.s = c1->s;
	t.v = c1->v;
	t.i = c1->i;

	c1->s = c2->s;
	c1->v = c2->v;
	c1->i = c2->i;

	c2->s = t.s;
	c2->v = t.v;
	c2->i = t.i;

	return 0;
}

int main(){

	CARD c1[37], c2[37], t_card;
	int n, i, j;
	int stable;
	int mini;
	char t;


	//input
	scanf( "%d\n", &n );

	for( i=0; i<n; i++ ){
		scanf( "%c%d", &c1[i].s, &c1[i].v );
		c1[i].i = i;
		memcpy( &c2[i], &c1[i], sizeof(CARD) );
		scanf( "%c", &t );
	}

	
	//bubble sort
	for( i=0; i<n; i++ ){
	for( j=(n-1); j>i; j-- ){

		if( c1[j].v < c1[j-1].v )
			swap( &c1[j], &c1[j-1] );

	}}


	//output
	for( i=0; i<n; i++ )
		printf( "%c%d%c", c1[i].s, c1[i].v, i!=(n-1)?' ':'\n' );

	//stable?
	stable=0;
	for( i=1; i<n; i++ ){
		if( c1[i-1].v == c1[i].v ){
			if( c1[i-1].i > c1[i].i ){
				stable++;
				break;
			} 
		}
	}
	if(stable) printf( "Not stable\n" );
	else printf( "Stable\n" );



	//selection sort
	for( i=0; i<n; i++ ){
		mini=i;
		for( j=i; j<n; j++ ){
			if( c2[j].v < c2[mini].v ) 
				mini = j;
		}
		
		swap( &c2[i], &c2[mini] );
	}


	//output
	for( i=0; i<n; i++ )
		printf( "%c%d%c", c2[i].s, c2[i].v, i!=(n-1)?' ':'\n' );

	//stable?
	stable=0;
	for( i=1; i<n; i++ ){
		if( c2[i-1].v == c2[i].v ){
			if( c2[i-1].i > c2[i].i ){
				stable++;
				break;
			} 
		}
	}
	if(stable) printf( "Not stable\n" );
	else printf( "Stable\n" );



	return 0;

}