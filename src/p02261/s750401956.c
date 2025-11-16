#include <stdio.h>
#include <stdlib.h>

struct card {
    char mark;
    int val;
    int index;
};

int
bubble_sort(struct card *C, int N)
{
    int i, j;
    struct card tmp;

    for (i = 0; i < N; i++) {
        for (j = N -1; j > i; j--) {
            if (C[j].val < C[j - 1].val) {
                tmp = C[j];
                C[j] = C[j - 1];
                C[j - 1] = tmp;
            }
        }
    }
    return 0;
}

int
selection_sort(struct card *C, int N)
{
    int i, j, minj;
    struct card tmp;

    for (i = 0; i < N; i++) {
        minj = i;
        for (j = i; j < N; j++) {
            if (C[j].val < C[minj].val)
                minj = j;
        }
        if (C[i].val != C[minj].val) {
            tmp = C[i];
            C[i] = C[minj];
            C[minj] = tmp;
        }
    }
    return 0;
}

void
print_card(struct card *c, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%c%d", c[i].mark, c[i].val);
        if (i != (n - 1))
            printf(" ");
    }
    printf("\n");
}

int
chk_stable(struct card *c, int n) {
    int i;

    for (i = 0; i < n - 1; i++) {
        if (c[i].val == c[i + 1].val) {
            if (c[i].index > c[i + 1].index)
                return 1;
        }
    }
    return 0;
}

int
main()
{
    int N, i, res;
    struct card cb[36], cs[36];
    char str[4];

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%s", str);
        cb[i].mark = str[0];
        cs[i].mark = str[0];
        cb[i].val = atoi(&str[1]);
        cs[i].val = atoi(&str[1]);
        cb[i].index = i;
        cs[i].index = i;
    }

    bubble_sort(cb, N);
    print_card(cb, N);
    res = chk_stable(cb, N);
    if (res)
        printf("Not stable\n");
    else
        printf("Stable\n");

    selection_sort(cs, N);
    print_card(cs, N);
    res = chk_stable(cs, N);
    if (res)
        printf("Not stable\n");
    else
        printf("Stable\n");

    return 0;
}
