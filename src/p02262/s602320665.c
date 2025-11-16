#include <stdio.h>

#define N 1000000

int divide(int, int *);
void shellsort(int *, int);
void insertionsort(int *, int, int, int *);

int main() {
    int Arrlength, Array[N]; 

    scanf("%d", &Arrlength);
    for(int i=0; i<Arrlength; ++i) {
        scanf("%d", (Array+i));
        //printf("%d\n", *(Array+i));
    }

    shellsort(Array, Arrlength);
    return 0;
}

int divide(int length, int *G) {
    //const int limitlen = 5;
    //length = limitlen;
    int i, divide = 0;
    for(i=0; 3*divide < length; ++i) {
        *(G+i) = divide = 3*divide + 1;
        //printf("%d : %d\n", i+1, *(G+i));
    }
    return i;
}

void shellsort(int *Array, int length) {
    int cnt = 0, m = 0;
    int G[9];
    int *Gtail, *p;
    m = divide(length, G);
    p = Gtail = &G[m-1];
    
    printf("%d\n", m);
    //printf("*Gtail = %d\n", *Gtail);
    
    for(int i=0; i<m; ++i) {
        if(i) printf(" ");
        printf("%d", *(p-i));
    }
    printf("\n");
    for(int i=0; i<m; ++i) {
        insertionsort(Array, length, *(Gtail-i), &cnt);
    }
    printf("%d\n", cnt);
    for(int i=0; i<length; ++i) {
        printf("%d\n", *(Array+i));
    }
    
}

void insertionsort(int *Array, int length, int divide, int *cnt) {
    int i, j, v;
    for(i=divide; i<length; ++i) {
        v = Array[i];
        j = i - divide;
        while(j>=0 && Array[j] > v) {
            Array[j+divide] = Array[j];
            j = j - divide;
            *cnt += 1;
        }
        Array[j+divide] = v;
    }
}
