#include <stdio.h>

struct Card {
    char suit;
    int value;
};

void BubbleSort(struct Card C[], int N) {
    int i,j;
    struct Card dummy;
    for (i=0; i<N; i++) {
        for (j=N-1; j>=i; j--) {
            if(C[j].value < C[j-1].value) {
                dummy = C[j];
                C[j] = C[j-1];
                C[j-1] = dummy;
            }
        }
    }
}

void SelectionSort(struct Card C[], int N) {
    int i,j,minj;
    struct Card dummy;
    for (i=0; i<N; i++) {
        minj = i;
        for(j=i; j<N; j++) {
            if (C[j].value < C[minj].value) minj = j;
        }
        if (i != minj) {
            dummy = C[i];
            C[i] = C[minj];
            C[minj] = dummy;
        }
    }
}

void print(struct Card A[], int N) {
    int i;
    for (i=0; i<N; i++) {
        if(i>0) printf(" ");
        printf("%c%d",A[i].suit,A[i].value);
    }
    printf("\n");
}

int isStable(struct Card B[], struct Card S[], int N) {
    int i;
    for (i=0; i<N; i++) {
        if(B[i].suit != S[i].suit) return 0;
    }

    return 1;
}


int main(void) {
    struct Card B[36],S[36];
    int N,i;
    char dummy;
    scanf("%d\n",&N);
    for (i=0; i<N; i++) {
        scanf("%c%d",&B[i].suit, &B[i].value);
        scanf("%c",&dummy);
    }

    for (i=0; i<N; i++) S[i] = B[i];
    BubbleSort(B, N);
    SelectionSort(S, N);

    print(B, N);
    printf("Stable\n");
    print(S, N);

    if(isStable(B, S, N)) {
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

    return 0;
}