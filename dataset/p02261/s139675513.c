#include<stdio.h>
struct card {
    char s;
    int n;
};
int main(void) {
    struct card a[100], b[100], c[100], Key;
    int i = 0, j, k, n, m, l, key, minj;
    scanf("%d", &n);
    key = n;
    while ( key-- ) {
        scanf(" %c%d", &a[i].s, &a[i].n);
        b[i].s = a[i].s;
        c[i].s = a[i].s;
        b[i].n = a[i].n;
        c[i].n = a[i].n;
        i++;
    }
    /*BubbleSort*/
    for ( i = 0; i < n; i++ ) {
        for ( j = n - 1; j > i; j-- ) {
            if ( b[j].n < b[j - 1].n ) {
                Key = b[j];
                b[j] = b[j - 1];
                b[j - 1] = Key;
            }
        }
    }
    /*SelectionSort*/
    for ( i = 0; i < n; i++ ) {
        minj = i;
        for ( j = i; j < n; j++ ) {
            if ( c[j].n < c[minj].n ) minj = j;
        }
        Key = c[i];
        c[i] = c[minj];
        c[minj] = Key;
    }
 
    key = n; i = 0;
    /*while ( key-- ) {
        if ( b[i].s != c[i].s ) break; 
        i++;
    }*/
    printf("%c%d", b[0].s, b[0].n);
    for (i = 1; i < n; i++ ) {
        printf(" %c%d", b[i].s, b[i].n);        
    }
    printf("\n");
    printf("Stable\n");
    printf("%c%d", c[0].s, c[0].n);
    for (i = 1; i < n; i++ ) {
        printf(" %c%d", c[i].s, c[i].n);        
    }
    printf("\n");
    for ( i = 0; i < n; i++ ) {
        if ( b[i].s != c[i].s) { printf("Not stable\n"); break; }
    }
    if ( i == n ) printf("Stable\n");
}