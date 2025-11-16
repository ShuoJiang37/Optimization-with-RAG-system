#include <stdio.h>
#include <stdlib.h>
#define VMAX 100000

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int C[VMAX];
    for (int i = 0; i < VMAX; i++) {
        C[i] = 0;
    }
    
    unsigned short *A, *B;
    A = (unsigned short*)malloc(sizeof(unsigned short)*n + 1);
    B = (unsigned short*)malloc(sizeof(unsigned short)*n + 1);

    for (int i = 1; i <= n; i++) {
        scanf("%hu", &A[i]);
        C[A[i]]++;
    }
    
    for (int i = 1; i < VMAX; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}


