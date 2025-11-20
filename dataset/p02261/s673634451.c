#include <stdio.h>
#include <stdlib.h>

struct card {
    char suit;
    int num;
};

void swap (struct card *, struct card *);
void print_a (struct card *, int);
int equal_a (struct card *, struct card *, int);
void bubble_sort (struct card *, int);
void selection_sort (struct card *, int);

int main (void) {
    int n;
    struct card *a, *b;
    char ch;

    scanf ("%d%c", &n, &ch);
    a = (struct card *) malloc (sizeof(struct card) * n);
    b = (struct card *) malloc (sizeof(struct card) * n);
    for (int i=0; i<n; i++) {
        scanf ("%c%d%c", &a[i].suit, &a[i].num, &ch);
        b[i].suit = a[i].suit;
        b[i].num = a[i].num;
    }

    bubble_sort (a, n);
    selection_sort (b, n);

    print_a (a, n);
    printf ("Stable\n");
    print_a (b, n);
    if (equal_a (a, b, n)) printf ("Stable\n");
    else printf ("Not stable\n");

    free(a);
    free(b);

    return 0;
}

void swap (struct card *a, struct card *b) {
    struct card t;
    t.suit = a->suit;
    t.num = a->num;
    a->suit = b->suit;
    a->num = b->num;
    b->suit = t.suit;
    b->num = t.num;
}

void print_a (struct card *a, int n) {
    for (int j=0; j<n; j++) {
        if (j==n-1) printf ("%c%d\n",a[j].suit, a[j].num);
        else printf ("%c%d ", a[j].suit, a[j].num);
    }
}

int equal_a (struct card *a, struct card *b, int n) {
    int i=0;
    int res=0;
    for (; i<n; i++) {
        if (!(a[i].suit==b[i].suit && a[i].num==b[i].num)) break;
    }
    if (i==n) res=1;
    return res;
}

void bubble_sort (struct card *a, int n) {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            if (a[j].num<a[j-1].num) {
                swap (a+j, a+j-1);
            }
        }
    }
}

void selection_sort (struct card *a, int n) {
    for (int i=0; i<n; i++) {
        int mini=i;
        for (int j=i; j<n; j++) {
            if (a[j].num<a[mini].num) mini=j;
        }
        if (i!=mini) {
            swap (a+i, a+mini);
        }
    }
}

