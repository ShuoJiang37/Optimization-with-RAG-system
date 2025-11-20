#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char alpa;
    int value;
}CARD;

void babul(int ,CARD *);
void sel(int, CARD *);
void output(int, CARD *, CARD *);

int main() {
    CARD *A,*B,*C;
    int n,i;

    scanf("%d", &n);

    A = malloc(n * sizeof(CARD));
    B = malloc(n * sizeof(CARD));
    C = malloc(n * sizeof(CARD));

    for(i = 0; i < n; i++) {
        scanf(" %c%d", &A[i].alpa, &A[i].value);
        B[i] = A[i];
        C[i] = A[i];
    }

    babul(n, B);
    sel(n, C);

    output(n, B, A);
    output(n, C, A);

    free(A);
    free(B);
    free(C);

    return 0;
}

void babul(int n, CARD *a) {
    int i,end = 0;
    CARD box;

    while(1) {
        for(i = n-1; i > end; i--) {
            if(a[i].value < a[i-1].value) {
                box = a[i];
                a[i] = a[i-1];
                a[i-1] = box;
            }
        }
        end++;
        if(end == n)break;
    }
}
void sel(int n,CARD *a) {
    int i,j,minj;
    CARD box;

    for(i = 0; i < n; i++) {
        minj = i;
        for(j = i; j < n; j++) {
            if(a[j].value < a[minj].value) {
                minj = j;
            }
        }
        if(a[i].value != a[minj].value) {
            box = a[i];
            a[i] = a[minj];
            a[minj] = box;
        }
    }
}

void output(int n, CARD *a, CARD *ans) {
    int i,j,flag = 0;

    for(i = 0; i < n-1; i++) {
        printf("%c%d ",a[i].alpa,a[i].value);
    }
    printf("%c%d\n",a[i].alpa,a[i].value);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[i].value == ans[j].value) {
                if(flag == j) break;
                if(a[i].alpa != ans[j].alpa) {
                    printf("Not stable\n");
                    return;
                }else {
                    flag = j;
                    break;
                }
            }
        }
    }
    printf("Stable\n");
}

