#include<stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 200001

#define MAX 1000
#define MAXWEIGHTIJ 20000

struct MC {
	int cost,order;
};

void exchange( struct MC *px, struct MC *py )
{
  struct MC t;
	t=*px;
	*px=*py;
	*py=t;
}

int Partition( struct MC A[], int p, int r )
{

    struct MC x;
    int i=p-1;
    x=A[r];

    int j;

    for( j=p; j<r; j++ ) {
        if( A[j].cost < x.cost ) {
            i++;
            exchange( &A[i], &A[j] );
         }
    }
    exchange( &A[i+1], &A[r]);
    return i+1;
}
void QuickSort( struct MC A[], int p, int r )
{
    int q;
    if( p < r ) {
        q=Partition( A, p, r );
        QuickSort( A, p, q-1 );
        QuickSort( A, q+1, r );
    }
    return;
}

int tryChange( int n, struct MC W[] )
{
	int cnt, fixedcost,pro, from, to, togoal,cost,lowestCost,i,j,lowW,lowestW,low,high,lowest;
	lowestW=lowW=lowestCost=cost=MAXWEIGHTIJ;
	lowest=high=low=-1;
	for( i=0; i<n; i++ ) {
		if( i != W[i].order && W[i].cost < lowW ) {
			lowW=W[i].cost;
			low=i;
			for( j=0; j<n; j++ ) {
				if( low == W[j].order ) {
					high=j;
					break;
				}
			}
		}
		if( W[i].cost < lowestW ) {
			lowestW=W[i].cost;
			lowest=i;
		}
	}

	if( W[high].order == low && W[low].order == high ) {
		lowestCost = W[low].cost + W[high].cost;
	  }
    else if( low != lowest ) {
		fixedcost = W[low].cost + W[lowest].cost;
		pro = W[low].cost - W[lowest].cost;
		from=high;
		to=low;
		togoal = W[low].order;
		cnt=0;
		while( 1 ) {
			if( W[from].order == to ) {
				if( togoal == to ) { break; }
				to=from;
				cnt++;
			}
      else {
				break;
			}
			for( i=0; i<n; i++ ) {
				if( i != W[i].order ) {
					if( to == W[i].order ) {
						from=i;
						break;
					}
				}
			}
		}
		pro = ( pro * cnt ) - ( 2 * fixedcost );

		if( 0 < pro ) {
			high=low;
			low=lowest;
			lowestCost = fixedcost;
		}
	}

	if( W[high].order == low ) {
		lowestCost = W[low].cost + W[high].cost;
	}

    if( MAXWEIGHTIJ != lowestCost ) {
		exchange( &W[low], &W[high] );
	  }
    else {
    	lowestCost=0;
    }
	return lowestCost;
}


int main( void )
{
    int n,i,cost;
    struct MC W[MAX+1];

    scanf( "%d", &n );
    for( i=0; i<n; i++ ) {
        scanf( "%d", &W[i].cost );
        W[i].order=i;
    }
	QuickSort( W, 0, n-1 );
	cost=i=0;
	while( (i = tryChange( n, W ) ) ) {
		cost+=i;
	}
	printf( "%d\n", cost );
    return 0;
}

