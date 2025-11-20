#include <stdio.h>
#define N 1000000
 
int cnt = 0;
int a[N];
 
void insertionSort(int a[], int n, int g)
{
    int v;
    int i, j;
 
    for(i = g; i < n; i++) {
        v = a[i];
        j = i - g;
        while(j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j + g] = v;
    }
}
 
void shellSort(int a[], int n)
{
    int i,m = 14;
    int G[] = {1, 4, 14, 56, 131, 544, 2093, 4580, 10383, 29224, 98572, 332242, 898323,1267543};
    cnt = 0;
    
    while(G[m-1] > n) m--;
    printf("%d\n",m);
    printf("%d", G[m-1]);
    for(i = m - 2; i >= 0; i--) printf(" %d", G[i]);
    printf("\n");
    for(i=m-1; i>=0; i--) {
        insertionSort(a, n, G[i]);
    }
}
 
int main()
{
    int i, n;
 
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\n");
    shellSort(a, n);
    printf("%d\n", cnt);
    for(i=0; i<n; i++) printf("%d\n", a[i]);
    return 0;
}
