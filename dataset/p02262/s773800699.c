// 1_2_D
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long cnt = 0;

void InsertionSort(long A[], long n, long g){
    long i, j, v;
    for(i = g; i < n; i++){
        v = A[i];
        j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
    return;
}

void ShellSort(long A[], long n){
    int m, i;
    m = ((pow(n, 1.25) > 100)? 100: pow(n, 1.25));
    long G[m];
    G[0] = 1;
    for(i = 1; i < m; i++){
        if((G[i] = 3 * G[i-1] + 1) > n) break;
    }
    m = i;

    printf("%d\n", m);

    for(i = m - 1; i > 0; i--){
        printf("%ld ", G[i]);
    }
    printf("%ld\n", G[i]);

    for(i = m - 1; i >= 0; i--){
        InsertionSort(A, n, G[i]);
    }
    return;
}

int main(){
    int i;
    long n, *A;
    scanf("%ld", &n);

    A = malloc(sizeof(long) * n);
    for(i = 0; i < n; i++){
        scanf("%ld", &A[i]);
    }

    ShellSort(A, n);
    printf("%ld\n", cnt);
    for(i = 0; i < n; i++){
        printf("%ld\n", A[i]);
    }

    free(A);
    return 0;
}