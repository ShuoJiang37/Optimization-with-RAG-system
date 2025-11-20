#include <stdio.h>

int selection_sort(int A[], int N)
{
    int minj;
    int count = 0;
    for (int i = 0; i < N; ++i) {
         minj = i;
         for (int j = i + 1; j < N; j++) {
             if (A[j] < A[minj])
                minj = j;
         }
         if (minj != i) {
            int temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            count++;
         }
    }
    
    return count;
}

int main(int argc, char const *argv[])
{
    // int A[] = {5, 6, 4, 2, 1, 3};
    int A[100];
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    
    int count = selection_sort(A, N);

    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", count);
    
    return 0;
}

