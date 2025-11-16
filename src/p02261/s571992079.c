#include <memory.h>
#include <stdbool.h>
#include <stdio.h>

#define arr_print_card(a, n) for(int i=0;i<(n);++i)printf(i==(n)-1?"%c%d\n":"%c%d ",(a)[i].symbol, (a)[i].num)

typedef struct Card {
    char symbol;
    int num;
} Card;
bool card_lt(const Card l, const Card r) {
    return l.num < r.num;
}
bool card_neq(const Card l, const Card r) {
    return l.symbol != r.symbol || l.num != r.num;
}

void bubble_sort(Card *a, const int N) {
    for(int i = 0; i < N; ++i) {
        for(int j = N - 1; j > i; --j) {
            if(card_lt(a[j], a[j - 1])) {
                Card tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}
void selection_sort(Card *a, const int N) {
    for(int i = 0; i < N; ++i) {
        int minj = i;
        for(int j = i + 1; j < N; ++j) {
            if(card_lt(a[j], a[minj])) minj = j;
        }
        if(i != minj) {
            Card tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
        }
    }
}
bool arr_cmp(Card *a, Card *b, const int N) {
    for(int i = 0; i < N; ++i) {
        if(card_neq(a[i], b[i])) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d\n", &n);
    Card a[n], b[n];
    for(int i = 0; i < n; ++i) {
        scanf(" %c%d", &a[i].symbol, &a[i].num);
    }
    memcpy(b, a, sizeof(b));
    // a-arr -> bubble sort
    bubble_sort(a, n);
    // b-arr -> selection sort
    selection_sort(b, n);

    arr_print_card(a, n);
    // bubble sort is always stable
    printf("Stable\n");
    arr_print_card(b, n);
    // cmp with bubble sorted array
    printf(arr_cmp(a,b,n)?"Stable\n":"Not stable\n");
    return 0;
}

