#include <stdio.h>
 
#define Max 1000000
 
void printA(int A[Max], int N) {
    int i;
 
    for (i = 0; i < N - 1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[i]);
}
 
int insertionSort(int A[Max], int N, int g) {
    int i, j, v;
    int cnt = 0;
 
    for (i = g; i < N; i++) {
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
 
    return cnt;
}
 
void shellSort(int A[Max], int N) {
    int i = 0;
    int cnt = 0;
    int m = 0;
    int box[20];
    int G[Max];
 
 
    box[0] = 1;
    for (i = 1; i < 20; i++) box[i] = 3 * box[i - 1] + 1;
 
    for (i = 20 - 1; i >= 0; i--) {
        if (box[i] <= N) G[m++] = box[i];
    }
 
    printf("%d\n", m);
 
    printA(G, m);
 
    for (i = 0; i < m; i++) cnt += insertionSort(A, N, G[i]);
 
    printf("%d\n", cnt);
 
    for (i = 0; i < N; i++) printf("%d\n", A[i]);
}
 
int main( ) {
    int N, i, j;
    int A[Max];
 
    scanf("%d", &N);
 
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
 
    shellSort(A, N);
 
    return 0;
}