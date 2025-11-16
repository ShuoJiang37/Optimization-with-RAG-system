#include <stdio.h>

struct trump {
    char s;
    int n;
    
};

int main(void)
{
    struct trump a[500], b[500], c[500], t;
    int m, i, j, min;
    
    scanf ("%d", &m);
    
    for ( i = 0; i < m; i++) {
        scanf ( " %c%d", &a[i] .s, &a[i] .n );
        b[i] .s = a[i] .s;
        c[i] .s = a[i] .s;
        b[i] .n = a[i] .n;
        c[i] .n = a[i] .n;
    }
    
    for ( i = 0; i < m; i++) {
        for ( j = m - 1; j > i; j--) {
            if ( b[j] .n < b[j - 1] .n) {
                t = b[j];
                b[j] = b[j - 1];
                b[j - 1] = t;
            }
            
        }
    }
    
    for ( i = 0; i < m; i++ ) {
        min = i;
        for ( j = i; j < m; j++) {
            if ( c[j] .n < c[min] .n){
                min = j;
            }
        }
        t = c[i];
        c[i] = c[min];
        c[min] = t;
    }
    
    for ( i = 0; i < m; i++) {
        printf ( "%c%d", b[i] .s, b[i] .n);
        if ( i != m - 1) {
            putchar ( ' ' );
        }
        else {
            putchar ( '\n');
        }
    }
    printf ( "Stable\n");
    
    for ( i = 0; i < m; i++) {
        printf ("%c%d", c[i] .s, c[i] .n);
        
        if ( i != m - 1 ) {
            putchar ( ' ' );
        }
        else {
            putchar ( '\n' );
        }
    }
    
    for ( i = 0; i < m; i++ ) {
        if (b[i] .s != c[i] .s ) {
            printf ( "Not stable\n" );
            break;
        }
    }
    
    if ( i == m ) {
        printf ( "Stable\n" );
    }
    return 0;
}
