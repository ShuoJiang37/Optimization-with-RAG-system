#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int32_t isPrime(int32_t n) {
    int i;
    double sq = sqrt(n);

    for ( i = 2; i <= (int)sq; i += 1 ) {
        if ( (n % i) == 0 ) {
            return 0;
        }
    }

    return 1;
}

static void printArray(const uint32_t A[], uint32_t n) {
    uint32_t i;

    for ( i = 0; i < n; i++ ) {
        printf("%u%s", A[i], i == n -1 ? "" : " ");
    }
    printf("\n");

    return;
}

static int insersionSort(uint32_t A[], uint32_t n, uint32_t g) {
    int i, j;
    uint32_t v;
    int c = 0;

    for (i = g; i < n; i++) {
        v = A[i];
        j = i - g;
        while ( (j >= 0) && A[j] > v ) {
            A[j + g] = A[j];
            j = j - g;
            c++;
        }
        A[j+g] = v;
    }
    
    return c;
}

#if 0
static uint32_t* makeGbyPrime(uint32_t n, uint32_t* m) {
    int i, j;
    uint32_t* G;
    uint32_t t;
    
    t = sqrt(n);
    G = malloc(sizeof(uint32_t) * t);
    assert( G != NULL );
    for ( j = 0, i = sqrt(n); i > 0; i--) {
        if ( isPrime(i) ) {
            G[j++] = i;
        }
    }
    *m = j;

    return G;
}
#endif

static uint32_t* makeGby3nPlusOne(uint32_t n, uint32_t* m) {
    int i;
    uint32_t* G;
    uint32_t t;
    
    G = malloc(sizeof(uint32_t) * 100);
    assert( G != NULL );

    G[0] = 1;
    for ( i = 1; i < 100; i++ ) {
        G[i] = G[i-1] * 3 + 1;
        if ( G[i] > n ) {
            break;
        }
    }
    *m = i;
    
      /* change order */
    for ( i = 0; i < *m / 2; i++ ) {
        t = G[i];
        G[i] = G[*m - i - 1];
        G[*m - i - 1] = t;
    }
    
    return G;
}

static inline uint32_t* makeG(uint32_t n, uint32_t* m) {
    return makeGby3nPlusOne(n, m);
}

int main(int argc, char* argv[]) {
    int ret;
    int i;
    int count = 0;
    uint32_t n, d;
    uint32_t* A;
    uint32_t m;
    uint32_t* G;

    ret = fscanf(stdin, "%u\n", &n);
    assert( ret == 1 );
    assert( (1 <= n) && n <= 1000000 );

      /* read line number */
    A = malloc(sizeof(uint32_t) * n);
    assert( A != NULL );

      /* read input data */
    memset(A, 0x00, sizeof(uint32_t) * n);
    i = 0;
    while ( (ret = fscanf(stdin, "%u\n", &d)) == 1 ) {
        A[i++] = d;
    }
    assert( i == n);

    G = makeG(n, &m);

    printf("%d\n", m);          /* line: 1 */
    printArray(G, m);           /* line: 2 */

    for ( i = 0; i < m; i++ ) {
        count += insersionSort(A, n, G[i]);
    }

    printf("%d\n", count);      /* line: 3 */

    assert( (double)count < pow(n, 1.5) );
    
    for ( i = 0; i < n; i++ ) {
        printf("%d\n", A[i]);
    }

    free(A);
    free(G);
    
    return 0;
}

