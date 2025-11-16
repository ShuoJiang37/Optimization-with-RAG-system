#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_a (int *, int);
void insertion_sort (int *, int, int, int *);
void shell_sort (int *, int);

int main (void) {
    int n;
    int *a;

    scanf ("%d", &n);

    a = (int *) malloc (sizeof(int) * n);
    for (int i=0; i<n; i++) scanf ("%d", a+i);

    shell_sort (a, n);

    free (a);
    return 0;
}

void print_a (int *a, int n) {
    for (int j=0; j<n; j++) {
            if (j==n-1) printf ("%d\n", a[j]);
            else printf ("%d ", a[j]);
        }
}

void insertion_sort (int *a, int n, int g, int *cnt) {
    for (int i=g; i<n; i++) {
        int v = a[i];
        int j = i-g;
        for (; j>=0 && a[j]>v; j-=g) {
            a[j+g] = a[j];
            *cnt=*cnt+1;
        }
        a[j+g] = v;
    }
}

void shell_sort (int *a, int n) {
    int cnt = 0;
    int m;
    int *g;

    if (n>pow(2, 100)) m=100;
    else if (n%2!=0) m=log2(n)+1;
    else m=log2(n);

    g = (int *) malloc (sizeof(int)*m);

    for (int i=m-1, h=1; i>=0; h*=2, i--) g[i] = h;

    for (int i=0; i<m; i++) insertion_sort (a, n, g[i], &cnt);

    printf ("%d\n", m);
    print_a (g, m);
    printf ("%d\n", cnt);
    for (int i=0; i<n; i++) printf ("%d\n", a[i]);

    free(g);
}

