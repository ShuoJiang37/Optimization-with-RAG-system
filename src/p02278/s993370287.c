#include<stdio.h>
 
#define MAX 1000
#define MAXWEIGHTIJ 20000
 
struct MCS {
    int cost;
    int order;
};
 
void exchange( struct MCS *pa, struct MCS *pb )
{
    struct MCS t;
      
    t=*pa;
    *pa=*pb;
    *pb=t;
      
     return;
}
  
int Partition( struct MCS A[], int p, int r )
{
    struct MCS x;
    int i,j;
  
    x=A[r];
    i=p-1;
    for( j=p; j<r; j++ ) {
        if( A[j].cost < x.cost ) {
            i++;
            exchange( &A[i], &A[j] );
         }
    }
    exchange( &A[i+1], &A[r] );
 
    return i+1;
}
void QuickSort( struct MCS A[], int p, int r )
{
    int q;
      
    if( p < r ) {
        q=Partition( A, p, r );
        QuickSort( A, p, q-1 );
        QuickSort( A, q+1, r );
    }
    return;
}
 
int tryChange( int n, struct MCS W[] )
{
    int cnt;
    int fixedcost,profit;
    int from, to, togoal;
     
    int cost,lowestCost;
    int i,j;
    int lowW,lowestW;
    int low,high,lowest;
 
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
    } else if( low != lowest ) {   
        fixedcost = W[low].cost + W[lowest].cost;
        profit = W[low].cost - W[lowest].cost;
        from=high;
        to=low;
        togoal = W[low].order;
        cnt=0;
        while( 1 ) {
            if( W[from].order == to ) {
                if( togoal == to ) { break; }
                to=from;
                cnt++;
            } else {
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
        profit = ( profit * cnt ) - ( 2 * fixedcost );
        if( 0 < profit ) {
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
    } else {
        lowestCost=0;
    }
    return lowestCost;
}
 
int main( void )
{  
    int n,i;
    struct MCS W[MAX+1];
    int cost;
         
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