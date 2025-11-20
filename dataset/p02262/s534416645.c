/*
 * Shell Sort
 *
 */
#include<stdio.h>
int A[1000000], G[100];
int cnt=0, m;

void InsertionSort(int, int);
void shellSort(int);

int main(void){
    int key=0, length, i, j;

    scanf("%d", &length);
    for(i=0; i<length; i++){
        scanf("%d",&A[i]);
    }

    shellSort(length);

    printf("%d\n", m);

    for(i=m-1;i>=0;i--){
        printf("%d ", G[i]);
    }
    printf("\n");

    printf("%d\n", cnt);

    for(i=0;i<length;i++){
        printf("%d\n", A[i]);
    }

    return 0;
}

void shellSort(int n) {
    cnt = 0;
    int i, h=1;

    m=0;
    while (h <= n)
    {
        G[m] = h;
        h = 3 * h + 1;
        m++;
    }

    for(i=m;i>=0;i--){
        InsertionSort(n, G[i]);
    }
}

void InsertionSort(int n, int g) {
    int j, i, key;
    //Insertion Sort Algo
    for(i=g; i<=n-1; i++){

        key = A[i];
        j = i - g;

        while(j>=0 && A[j]>key){
            A[j+g] = A[j];
            j = j - g;
            // j--;
            cnt++;
        }

        A[j+g] = key;
    }
}

