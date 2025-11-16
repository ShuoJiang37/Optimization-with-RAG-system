#include <stdio.h>
 struct C {
    char suit;
    int number;
};
int main() {
    int i, j, n, fl = 0, minj;
    char s[5];
    struct C cap1[36], cap2[36], v;
  
    scanf("%d", &n);
    for (i = 0; i < n; i++) { 
        scanf("%s", s);
        cap1[i].suit = s[0];
        cap1[i].number = atoi(s + 1);
        cap2[i] = cap1[i];
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            if (cap1[j].number < cap1[j - 1].number) {
                v = cap1[j];
                cap1[j] = cap1[j - 1];
                cap1[j - 1] = v;
            }
        }
    }
    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            if (cap2[j].number < cap2[minj].number){
                minj = j;
            }
        }
        v = cap2[i];
        cap2[i] = cap2[minj];
        cap2[minj] = v;
    }
    for (i = 0; i < n; i++) {
        printf("%c%d", cap1[i].suit, cap1[i].number);
        if (i != n - 1){
            printf(" ");
        }
    }
    printf("\nStable\n");
    for (i = 0; i < n; i++) {
        printf("%c%d", cap2[i].suit, cap2[i].number);
        if (i != n - 1){
            printf(" ");
        }
    }
    for (i = 0; i < n; i++) {
        if ((cap1[i].suit != cap2[i].suit) || (cap1[i].number != cap2[i].number)) { 
            fl = 1;
            break;
        }
    }
    if (fl == 1){
        printf("\nNot stable\n");
    }
    else printf("\nStable\n");
    return 0;
}