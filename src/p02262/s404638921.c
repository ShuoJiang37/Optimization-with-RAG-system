#include <stdio.h>
#include <stdlib.h>
long int cnt = 0;

void shellSort(int *A, int n, int g){
    int v;
    int j;
    int i;
    for (i = g; i < n; i++){
        v = A[i];
        j = i - g;
        while (A[j] > v && j >= 0){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

int main(void){
    int n;
    int *A;
    int *G;
    int m;
    int i, j;

    A = (int *)malloc(sizeof(int) * 1000000);
    G = (int *)malloc(sizeof(int) * 1000000);

    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    m = 0;
    j = 0;

    if (n == 1){
        G[0] = 1;
        m = 1;
    }
    
    if (n > 1 ){
        m = 0;
        for (i = n/2; i >= 1; i = i/2){
            G[m] = i;
            m++;
            if (m == 100){
                G[m] = 1;
                break;
            }
        }
    }

    for (i = 0; i < m; i++){
        shellSort(A, n, G[i]);
    }
    
    printf("%d\n", m);
   
    for (i = 0; i < m - 1; i++){
            printf("%d ", G[i]);
    }
    printf("%d\n", G[m-1]);
    
    printf("%ld\n", cnt);

    for (i = 0; i < n; i++){
        printf("%d\n", A[i]);
    }

    free(A);
    return 0;

}