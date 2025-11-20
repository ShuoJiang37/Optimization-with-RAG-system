#include <stdio.h>
#include <string.h>

#define Num 40

int main(void){

    int a[Num], b[Num];
    char t[Num], u[Num];
    int i, j, l, n = 0, c = 1, min, count = 0;
    char s[2], str1[2], str[2];

    scanf("%d", &l); 

    for (i = 0; i <= l-1; i++) {
        scanf(" %c", &t[i]);
        scanf("%d", &a[i]); 
    }

    for (i = 0; i <= l-1; i++) {
        b[i] = a[i];
        u[i] = t[i];
    }

    while (c > 0) {
        c = 0;
        for (i = l-1; i >= 1; i--) {
            if(a[i-1] > a[i]){
                n = a[i-1];
                a[i-1] = a[i];
                a[i] = n;

                s[1] = t[i-1];
                t[i-1] = t[i];
                t[i] = s[1];

                c = 1;
            }
        }
    }
    for (i = 0; i <= l-2; i++) {
        printf("%c", t[i]);
        printf("%d ", a[i]);
    }
    printf("%c", t[i]);
    printf("%d\n", a[i]);
    printf("Stable\n");


    for (i = 0; i <= l-1; i++) {
        min = i;
        for (j = i+1; j <= l-1; j++) {
            if(b[j] < b[min]){
                min = j;
            }
        }
        if(min != i){
            n = b[min];
            b[min] = b[i];
            b[i] = n;

            s[1] = u[min];
            u[min] = u[i];
            u[i] = s[1];
        }
    }

    for (i = 0; i <= l-2; i++) {
        printf("%c", u[i]);
        printf("%d ", b[i]);
    }
    printf("%c", u[i]);
    printf("%d\n", b[i]);
    for (i = 0; i <= l-1; i++) {
        if(t[i] != u[i]){
            count++;
            break;
        }
    }
    if(count != 0){
        printf("Not stable\n");
    }else{
        printf("Stable\n");
    }

    return 0;
}
