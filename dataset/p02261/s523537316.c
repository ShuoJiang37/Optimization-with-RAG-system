#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort_(int A[], int N)
{
    int flag;
    int j;

    flag = 1;
    while(flag) {
        flag = 0;
        for(j = N-1; j >= 1; j--) {
            //if(A[j]%4 < A[j-1]%4 && A[j]/4 < A[j-1]/4) {
            if(A[j]/4 < A[j-1]/4) {
                swap(&A[j], &A[j-1]);
                flag = 1;
            }
        }
    }
}

void bubbleSort(int A[], int N)
{
    int flag;
    int j;

    flag = 1;
    while(flag) {
        flag = 0;
        for(j = N-1; j >= 1; j--) {
            if((A[j]/4) < (A[j-1]/4)) {
                swap(&A[j], &A[j-1]);
                flag = 1;
            }
        }
    }
}

void selectionSort(int A[], int N)
{
    int i;
    int j;
    int minj;

    for(i = 0; i < N; i++) {
        minj = i;
        for(j = i; j < N; j++) {
            if((A[j]/4) < (A[minj]/4)) {
                minj = j;
            }
        }
        if(i != minj) {
            swap(&A[i], &A[minj]);
        }
    }
}

int main()
{
    int N;
    int i;
    int *original;
    int *original_sort;
    int *copy;
    char mark;
    int value;

    scanf("%d%*c", &N);
    original = (int *)malloc(sizeof(int) * N);
    original_sort = (int *)malloc(sizeof(int) * N);
    copy = (int *)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++) {
        scanf("%c%d%*c", &mark, &value);
        original[i] = value * 4;
        if(mark == 'S') {
            original[i] += 0;
        } else if(mark == 'H') {
            original[i] += 1;
        } else if(mark == 'C') {
            original[i] += 2;
        } else {
            original[i] += 3;
        }
    }

    for(i = 0; i < N; i++) {
        original_sort[i] = original[i];
    }
    bubbleSort_(original_sort, N);

    for(i = 0; i < N; i++) {
        copy[i] = original[i];
    }
    bubbleSort(copy, N);

    /* 1行目 */
    for(i = 0; i < N-1; i++) {
        if(copy[i]%4 == 0) {
            mark = 'S';
        } else if(copy[i]%4 == 1) {
            mark = 'H';
        } else if(copy[i]%4 == 2) {
            mark = 'C';
        } else {
            mark = 'D';
        }
        printf("%c%d ", mark, copy[i]/4);
    }
    if(copy[N-1]%4 == 0) {
        mark = 'S';
    } else if(copy[N-1]%4 == 1) {
        mark = 'H';
    } else if(copy[N-1]%4 == 2) {
        mark = 'C';
    } else {
        mark = 'D';
    }
    printf("%c%d\n", mark, copy[N-1]/4);

    /* 2行目 */
    for(i = 0; i < N; i++) {
        if(copy[i] != original_sort[i]) {
            break;
        }
    }
    if(i == N) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    for(i = 0; i < N; i++) {
        copy[i] = original[i];
    }
    selectionSort(copy, N);

    /* 3行目 */
    for(i = 0; i < N-1; i++) {
        if(copy[i]%4 == 0) {
            mark = 'S';
        } else if(copy[i]%4 == 1) {
            mark = 'H';
        } else if(copy[i]%4 == 2) {
            mark = 'C';
        } else {
            mark = 'D';
        }
        printf("%c%d ", mark, copy[i]/4);
    }
    if(copy[N-1]%4 == 0) {
        mark = 'S';
    } else if(copy[N-1]%4 == 1) {
        mark = 'H';
    } else if(copy[N-1]%4 == 2) {
        mark = 'C';
    } else {
        mark = 'D';
    }
    printf("%c%d\n", mark, copy[N-1]/4);

    /* 4行目 */
    for(i = 0; i < N; i++) {
        if(copy[i] != original_sort[i]) {
            break;
        }
    }
    if(i == N) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    return 0;
}
