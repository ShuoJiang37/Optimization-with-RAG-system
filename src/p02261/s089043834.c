#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n;
    scanf("%d", &n);
    char a[n+1][3];
    char b[n+1][3];
    char c[n+1][3];
    getchar();
    for(int i = 0; i < n; i++){
        scanf("%s", a[i]);
        strcpy(b[i], a[i]);
        strcpy(c[i], a[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = n-1 ; j >= i+1; j--){
            if(b[j][1] < b[j-1][1]){
                char temp[3];
                strcpy(temp, b[j]);
                strcpy(b[j], b[j-1]);
                strcpy(b[j-1], temp);
            }
        }
    }

    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i; j < n; j++){
            if(c[j][1] < c[mini][1]){
                mini = j;
            }
        }
        char temp[3];
        strcpy(temp, c[i]);
        strcpy(c[i], c[mini]);
        strcpy(c[mini], temp);
    }
    for(int i = 0; i < n; i++){
        printf("%s", b[i]);
        if(i!=n-1) printf(" ");
        else printf("\n");
    }
    printf("Stable\n");

    for(int i = 0; i < n; i++){
        printf("%s", c[i]);
        if(i != n-1) printf(" ");
        else printf("\n");
    }

    int flag = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            if(b[i][j] != c[i][j]){
                flag = 0;
                break;
            }
        }
    }
    if(flag) printf("Stable\n");
    else printf("Not stable\n");
    return 0;
}
