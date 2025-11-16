#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct card {
    char suit;
    int  value;
};

static void printOut(const struct card C[], int N) {
    int i;

    for ( i = 0; i < N; i++ ) {
        printf("%c%d%s", C[i].suit, C[i].value, i == N -1 ? "" : " ");
    }
    printf("\n");

    return;
}


static inline void swap(struct card C[], int a, int b) {
    struct card t;

    t = C[a];
    C[a] = C[b];
    C[b] = t;
}
    

static void bubbleSort(struct card C[], int N) {
    int i, j;

    for ( i = 0; i < N; i++) {
        for ( j = N - 1; j > i; j-- ) {
            if ( C[j].value < C[j-1].value ) {
                swap(C, j, j-1);
            }
        }
    }

    return;
}

static void selectionSort(struct card C[], int N) {
    int i, j, minj;

    for ( i = 0; i < N; i++) {
        minj = i;
        
        for ( j = i; j < N; j++) {
            if ( C[j].value < C[minj].value ) {
                minj = j;
            }
        }
//        if ( i != minj ) {
        {
            swap(C, i, minj);
        }
    }

    return;
}

/* 0: Not Stable, 1: Stable */
static int isStable(const struct card input[], const struct card sorted[], int N) {
    int i, j;

    for ( i = 1; i < N; i++ ) {
        if ( sorted[i - 1].value == sorted[i].value ) {
            int p = -1;
            int q = -1;
            for ( j = 0; j < N; j++ ) {
                if ( (sorted[i - 1].value == input[j].value) && (sorted[i - 1].suit == input[j].suit ) ) {
                    p = j;
                }
                if ( (sorted[i].value == input[j].value) && (sorted[i].suit == input[j].suit ) ) {
                    q = j;
                }
                if ( (p >= 0) && (q >= 0) ) {
                    break;
                }
            }
            if ( p > q ) {
                return 0;
            }
        }
    }

    return 1;
}

int main(int argc, char* argv[]) {
    int ret;
    int i;
    int N;
    struct card *input;
    struct card *sorted;
    int s, v;

    ret = scanf("%d\n", &N);
    assert( ret == 1 );
    assert( (1 <= N) && N <= 100 );

    input = malloc(sizeof(struct card) * N);
    assert( input != NULL );

    memset(input, 0x00, sizeof(struct card) * N);
    i = 0;
    while ( ((s = fgetc(stdin)) != EOF) && ((v = fgetc(stdin)) != EOF) && (i < N) ) {
        assert( (s == 'S') || (s == 'H') || (s == 'C') || (s == 'D' ) );
        assert( isdigit(v) );

        input[i].value = v - '0';
        input[i].suit  = s;

        int c = fgetc(stdin);
        if ( c == ' ' ) {
            i++;
        } else {
            break;
        }
    }

    sorted = malloc(sizeof(struct card) * N);
    assert( input != NULL );

    memcpy(sorted, input, sizeof(struct card) * N);
    bubbleSort(sorted, N);
    printOut(sorted, N);
    printf("%s\n", isStable(input, sorted, N) ? "Stable" : "Not stable");

    memcpy(sorted, input, sizeof(struct card) * N);
    selectionSort(sorted, N);
    printOut(sorted, N);
    printf("%s\n", isStable(input, sorted, N) ? "Stable" : "Not stable");

    free(input);
    free(sorted);    

    return 0;
}
    

