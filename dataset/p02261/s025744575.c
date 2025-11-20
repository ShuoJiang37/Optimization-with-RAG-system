#include <stdio.h>
int main()
{
    struct cards{
        char suit;
        int value;
    } C1[100], C2[100], f;

    int i, j, n, mini, x=0;
    char ch;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        ch = getchar();
        C1[i].suit = getchar();
        scanf("%d", &C1[i].value);
        C2[i] = C1[i];
    }
    for(i = 0; i < n; i++){
        for(j = (n - 1); j > i; j--){
            if(C1[j].value < C1[j - 1].value){
                f = C1[j];
                C1[j] = C1[j - 1];
                C1[j - 1] = f;
            }
        }
    }
    for(i = 0; i < n; i++){
        mini = i;
        for(j = i; j < n; j++){
            if(C2[j].value < C2[mini].value){
                mini = j;
            }
        }
        f = C2[i];
        C2[i] = C2[mini];
        C2[mini] = f;
    }
    for(i = 0; i < n; i++){
        if(i == n-1){
            printf("%c%d\n", C1[i].suit, C1[i].value);
            printf("Stable\n");
        } else {
            printf("%c%d ", C1[i].suit, C1[i].value);
        }
    }
    for(i = 0; i < n; i++){
        if(C1[i].suit != C2[i].suit) x = 1;
        if(i == n-1){
            printf("%c%d\n", C2[i].suit, C2[i].value);
            if(x == 1){
                printf("Not stable\n");
            } else {
                printf("Stable\n");
            } 
        } else {
            printf("%c%d ", C2[i].suit, C2[i].value);
        }
    }
    return 0;
}