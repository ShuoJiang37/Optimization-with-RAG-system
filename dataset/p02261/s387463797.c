#define N 40
#include <stdio.h>
struct poker {
    char suit;
    int value;
};

void showArray(struct poker a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%c%d", a[i].suit, a[i].value);
    }
    printf("\n");
}

void bubbleSort(struct poker a[], int n) {
    int flag = 1;
    while (flag) {
        flag = 0;
        int i = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].value > a[j + 1].value) {
                struct poker tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                flag = 1;
            }
        }
        i++;
    }
}

void selectionSort(struct poker a[], int n) {
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].value < a[minj].value) {
                minj = j;
            }
        }
        if (minj != i) {
            struct poker tmp = a[minj];
            a[minj] = a[i];
            a[i] = tmp;
        }
    }
}

int isStable(struct poker a[], struct poker b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].suit != b[i].suit) {
            return 0;
        }
    }
    return 1;
}

int main() {
    struct poker p1[N], p2[N];
    int n = 0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            getchar();
        }
        scanf("%C%d", &p1[i].suit, &p1[i].value);
        p2[i] = p1[i];
    }
    bubbleSort(p1, n);
    selectionSort(p2, n);
    showArray(p1, n);
    printf("Stable\n");
    showArray(p2, n);
    if (isStable(p1, p2, n)) {
        printf("Stable\n");
    }
    else {
        printf("Not stable\n");
    }
    return 0;
}
