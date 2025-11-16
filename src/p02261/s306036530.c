#include <stdio.h>
#include <string.h>


int main(void){
    int n;
    char suit[36];
    int number[36];
    char suitc[36];
    int numberc[36];
    int i, j;
    int itmp;
    char ctmp;
    int flag;
    int minij;


    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf(" %c%d", &suit[i], &number[i]);
    }

    for (i = 0; i < n; i++){
        suitc[i] = suit[i];
        numberc[i] = number[i];
    }

    for (j = 0; j < n - 1; j++){
        flag = 0;
        for (i = n - 2; i >= j; i--){
            if(number[i] > number[i+1]){
                itmp = number[i];
                number[i] = number[i+1];
                number[i+1] = itmp;
                ctmp = suit[i];
                suit[i] = suit[i+1];
                suit[i+1] = ctmp;
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
    for (i = 0; i < n - 1; i++){
        printf("%c%d ", suit[i], number[i]);
    }

    printf("%c%d", suit[n-1], number[n-1]);

    printf("\nStable\n");

    for (i = 0; i < n; i++){
        minij = i;
        for (j = i; j < n; j++){
            if (numberc[minij] > numberc[j]){
                minij = j;
            }
        }
        itmp = numberc[minij];
        ctmp = suitc[minij];
        numberc[minij] = numberc[i];
        suitc[minij] = suitc[i];
        numberc[i] = itmp;
        suitc[i] = ctmp;
    }

    for (i = 0; i < n - 1; i++){
        printf("%c%d ", suitc[i], numberc[i]);
    }

    printf("%c%d", suitc[n-1], numberc[n-1]);

    flag = 0;

    for (i = 0; i < n; i++){
        if (number[i] != numberc[i] || suit[i] != suitc[i]){
            flag = 1;        
        }
    }

    if (flag){
        printf("\nNot stable\n");
    }else{
        printf("\nStable\n");
    }

    return 0;
}