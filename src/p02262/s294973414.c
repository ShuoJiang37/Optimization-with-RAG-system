#include <stdio.h>
 
int cnt;
 
void insertionSort(int A[], int n, int g)
{
    int i;
    for (i = g; i < n; i++) {
        int v, j;
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}
 
void shellSort(int A[], int n)
{
    int i, m = 0;
    int G[10] = {262913, 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1};
 
    for (i = 0; i < 10; i++) {
        if (G[i] <= n) {
            m++;
            insertionSort(A, n, G[i]);
        }
    }
 
    printf("%d\n", m);
     
    i = 10 - m;
 
    printf("%d", G[i]);
    for (i++; i < 10; i++) printf(" %d", G[i]);
    putchar('\n');
}
 
int main(void)
{
    int n;
    scanf("%d", &n);
 
    int A[n];
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
 
    shellSort(A, n);
 
    printf("%d\n", cnt);
 
    for (i = 0; i < n; i++)
        printf("%d\n", A[i]);
 
    return 0;
}