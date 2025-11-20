#include <stdio.h>

int insertion_sort(long *A, int N, int g)
{
    int i, cnt = 0;
    for (i = g; i < N; i++) {
        long v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
           A[j + g] = A[j];
           j = j - g;
           cnt++;
        }
        A[j + g] = v;
    }
    return cnt;
}

int shell_sort(long *A, int N, int *G, int m)
{
    int i, cnt = 0;
    for (i = m - 1; i >= 0; i--) {
       cnt += insertion_sort(A, N, G[i]);
    }
    return cnt;
}

int main(int argc, char** argv)
{
    int i, num, g[100], m = 0; 
    long arr[1000000];
 
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%ld", &arr[i]);
    }

    g[0] = 1;
    for (i = 1; i < 100; i++) {
        g[i] = 3 * g[i - 1] + 1;
        if (num < g[i]) {
            m = i;
            break;
        }
    }
    
    int cnt = shell_sort(arr, num, g, m);

    printf("%d\n", m);
    for (i = m - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d\n", g[i]);
        }
        else {
            printf("%d ", g[i]);
        }
    }
    printf("%d\n", cnt);

    for (i = 0; i < num; i++) {
        printf("%ld\n", arr[i]);
    }
    return 0;
}