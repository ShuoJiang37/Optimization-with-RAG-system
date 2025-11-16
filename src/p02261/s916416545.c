#include <stdio.h>
#include <stdlib.h>

#define N 36

typedef struct {
    int value;
    char mark;
} TRUNP;

int main(){
    int n, i, j, cnt = 0, min, flg, stable_i[13]={}, stable_ti[13]={};
    char tmp[4], stable[13][N], stable_t[13][N];
    TRUNP C[N], RESULT[N], tmp_c;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%s", tmp);
        RESULT[i].mark = C[i].mark = tmp[0];
        RESULT[i].value = C[i].value = atoi(&tmp[1]);
        stable[C[i].value][stable_i[C[i].value]] = C[i].mark;
        stable_i[C[i].value]++;
    }
    
    
    for (i = 0; i < n; i++) {
        for (j = n - 1; j  > i; j--) {
            if (RESULT[j].value < RESULT[j-1].value) {
               tmp_c = RESULT[j];
               RESULT[j] = RESULT[j-1];
               RESULT[j-1] = tmp_c;
            }
        }
    }
    
    for (i = 0; i < n - 1; i++) {
        printf("%c%d ",RESULT[i].mark, RESULT[i].value);
    }
    printf("%c%d\n",RESULT[i].mark, RESULT[i].value);
    
    for (i = 0; i < n; i++) {
        stable_t[RESULT[i].value][stable_ti[RESULT[i].value]] = RESULT[i].mark;
        stable_ti[RESULT[i].value]++;
    }
    
    flg = 0;
    
    for (i = 0; i < 13; i++) {
        for (j = 0; j < stable_i[i]; j++) {
            if (stable[i][j] != stable_t[i][j]) flg = 1;
        }
    }
    if (flg) printf("Not stable\n");
    else printf("Stable\n");
    
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if (C[j].value < C[min].value) {
                min = j;
            }
        }
        tmp_c = C[i];
        C[i] = C[min];
        C[min] = tmp_c;
    }
    
    for (i = 0; i < n - 1; i++) {
        printf("%c%d ",C[i].mark, C[i].value);
    }
    printf("%c%d\n",C[i].mark, C[i].value);

    for (i = 0; i < 13; i++) {
        stable_ti[i]  = 0;
    }

    for (i = 0; i < n; i++) {
        stable_t[C[i].value][stable_ti[C[i].value]] = C[i].mark;
        stable_ti[C[i].value]++;
    }
    
    
    flg = 0;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < stable_i[i]; j++) {
            if (stable[i][j] != stable_t[i][j]) flg = 1;
        }
    }
    if (flg) printf("Not stable\n");
    else printf("Stable\n");
    
    return 0;
}

