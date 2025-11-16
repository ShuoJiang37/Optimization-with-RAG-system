#include <stdio.h>

struct Data {
    int a;
    char c;
};
typedef struct Data data_t;


void swap(data_t A[], int a, int b)
{
    data_t t = A[a];
    A[a] = A[b];
    A[b] = t;
}

void bubbleSort(data_t A[], int n)
{
    int i, j;
    for (i=1; i<n; i++) {
        for (j=i; j>0; j--) {
            if (A[j-1].a > A[j].a) {
                swap(A, j-1, j);
            }
        }
    }
}

void selectionSort(data_t A[], int n)
{
    int i, j, min;
    for (i=0; i<n; i++) {
        min = i;
        for (j=i; j<n; j++) {
            if (A[j].a < A[min].a) {
                min = j;
            }
        }
        swap(A, i, min);
    }
}

int main()
{
    int i;
    int N;
    data_t A[40], B[40];
    
    scanf("%d", &N);
    getchar();
    for (i=0; i<N; i++) {
        scanf("%c", &A[i].c);
        scanf("%d", &A[i].a);
        getchar();
        B[i] = A[i];
    }
    
    bubbleSort(A, N);
    selectionSort(B, N);
    
    for (i=0; i<N-1; i++) {
        printf("%c", A[i].c);
        printf("%d ", A[i].a);
    }
    printf("%c", A[i].c);
    printf("%d\n", A[i].a);
    puts("Stable");
    

    int isStable = 1;
    for (i=0; i<N-1; i++) {
        printf("%c", B[i].c);
        printf("%d ", B[i].a);
        if (A[i].c != B[i].c) {
            isStable = 0;
        }
    }
    printf("%c", B[i].c);
    printf("%d\n", B[i].a);
    puts(isStable? "Stable" : "Not stable");
    
    return 0;
}