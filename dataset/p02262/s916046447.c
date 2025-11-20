#include <stdio.h>
#define NMAX 1000000
 
int cnt = 0;
int A[NMAX];
 
void insertionSort(int A[], int n, int g)
{
    int v;
    int i, j;
 
    for(i=g; i<n; i++) {
        v = A[i];
        j = i - g;
        while(j>=0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}
 
void shellSort(int A[], int n)
{
    int i;
    int m = 13;
    int G[13] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161};
    cnt = 0;
 
    while(G[m-1] > n) m--;
    printf("%d\n%d", m, G[m-1]);
    for(i=m-2; i>=0; i--) printf(" %d", G[i]);
    putchar('\n');
 
    for(i=m-1; i>=0; i--) {
        insertionSort(A, n, G[i]);
    }
}
 
int main()
{
    int i, n;
 
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    shellSort(A, n);
    printf("%d\n", cnt);
    for(i=0; i<n; i++) printf("%d\n", A[i]);
    return 0;
}