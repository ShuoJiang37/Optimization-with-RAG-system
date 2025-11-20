#include <stdio.h>

struct Card {
    int value;
    char type;
};
typedef struct Card card_t;


void swap(card_t A[], int a, int b)
{
    card_t t = A[a];
    A[a] = A[b];
    A[b] = t;
}

void bubbleSort(card_t A[], int n)
{
    int i, j;
    for (i=1; i<n; i++) {
        for (j=i; j>0; j--) {
            if (A[j-1].value > A[j].value) {
                swap(A, j-1, j);
            }
        }
    }
}

void selectionSort(card_t A[], int n)
{
    int i, j, min;
    for (i=0; i<n; i++) {
        min = i;
        for (j=i; j<n; j++) {
            if (A[j].value < A[min].value) {
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
    card_t A[40], B[40];
    
    scanf("%d", &N); 
    getchar(); //??????
    for (i=0; i<N; i++) {
        scanf("%c", &A[i].type);
        scanf("%d", &A[i].value);
        getchar(); // ??????
        B[i] = A[i];
    }
    
    bubbleSort(A, N);
    selectionSort(B, N);
    
    // bubbleSort
    for (i=0; i<N-1; i++) {
        printf("%c", A[i].type);
        printf("%d ", A[i].value);
    }
    printf("%c", A[i].type);
    printf("%d\n", A[i].value);
    puts("Stable");
    
    
    // selectionSort
    int isStable = 1;
    for (i=0; i<N-1; i++) {
        printf("%c", B[i].type);
        printf("%d ", B[i].value);
        if (A[i].type != B[i].type) {
            isStable = 0;
        }
    }
    printf("%c", B[i].type);
    printf("%d\n", B[i].value);
    puts(isStable? "Stable" : "Not stable");
    
    return 0;
}