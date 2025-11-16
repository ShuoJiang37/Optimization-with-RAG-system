#include <stdio.h>

struct a{
    char mark;
    int value;
};

void BubbleSort(struct a b[], int n) {
    
    int i, j, t1;
    char t2;
    
    for (i = 0; i < n; ++i) {
        for (j = n-1; j >= i+1; --j) {
            if(b[j].value < b[j-1].value) {
                t1 = b[j].value;
                b[j].value = b[j-1].value;
                b[j-1].value = t1;
                t2 = b[j].mark;
                b[j].mark = b[j-1].mark;
                b[j-1].mark = t2;
            }
        }
    }
}

void SelectionSort(struct a s[], int n) {
    
    int i, minj, j, t1;
    char t2;
    for (i = 0; i < n; ++i){
        minj = i;
        for (j = i; j < n; ++j) {
            if (s[j].value < s[minj].value) minj = j;
        }
        t1 = s[i].value;
        s[i].value = s[minj].value;
        s[minj].value = t1;
        t2 = s[i].mark;
        s[i].mark = s[minj].mark;
        s[minj].mark = t2;
    }
}

int main() {
    int n, i, t1;
    char t2;
    struct a b[36];
    struct a s[36];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; ++i) {
        scanf("%c",&t2);
        scanf("%c%d", &b[i].mark, &b[i].value);
        s[i].value = b[i].value;
        s[i].mark = b[i].mark;
    }
    
    BubbleSort(b,n);
    
    for (i = 0; i < n; ++i) {
        printf("%c%d", b[i].mark, b[i].value);
        if (i != n-1) {
            putchar(' ');
        }
        else{
            putchar('\n');
        }
    }
    
    printf("Stable\n");
    
    SelectionSort(s, n);
    
    for (i = 0; i < n; ++i) {
        printf("%c%d", s[i].mark, s[i].value);
        if (i != n-1) {
            putchar(' ');
        }
        else{
            putchar('\n');
        }
    }
    
    t1 = 0;
    for (i = 0; i < n; ++i) {
        if (b[i].mark != s[i].mark) {
            t1 = 1;
            break;
        }
    }
    
    if (t1 == 0) {
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
    
    return 0;
}