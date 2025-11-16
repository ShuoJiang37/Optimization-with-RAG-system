#include <stdio.h>

long long cnt;
int N;
int A[1000000];
int G[20];
int m = 0;

void insertionSort(int A[], int N, int g)
{
    for (int i = g; i < N; i++) {
        int v = A[i];
        int j = i-g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int N)
{
    int h = 1;
    for (int i = 0; ; i++) {
        if (h > N) break;
        G[i] = h;
        h = 3*h + 1;
        m++;
    }

    for (int i = m; i >= 0; i--) {
           insertionSort(A, N, G[i]);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    cnt = 0;

    shellSort(A, N);

    printf("%d\n", m);
    for (int i = m-1; i>= 0; i--) {
        printf("%d", G[i]);
        if (i) printf(" ");
    }
    printf("\n");
    printf("%lld\n", cnt);
    for (int i = 0; i < N; i++) printf("%d\n", A[i]);

    return 0;
}
