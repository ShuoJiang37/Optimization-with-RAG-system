#include<stdio.h>
#include<string.h>
#define swap(a,b)({a ^= b; b ^= a; a ^= b;})

int main(){
    int n, i, j, a[101], mini;
    char dec[40][2], c;
    int bubble[40], selection[40], bubleStable, selectionStable;
    scanf("%d", &n);
    i=0;
    while(i<n){
        c = getchar();
        if(isupper(c)){
            dec[i][0] = c;
        }else if(isdigit(c)){
            dec[i][1] = c;
            bubble[i] = i;
            selection[i] = i;
            i++;
        }
    }

    for(i = 0; i<n; i++){
        for(j = n-1; j>= i+1; j--){
            if(dec[bubble[j]][1] < dec[bubble[j-1]][1]){
                swap(bubble[j], bubble[j-1]);
            }
        }
    }
    bubleStable = 1;
    for(i = 0; i<n-1; i++){
        if(dec[bubble[i]][1] == dec[bubble[i+1]][1]){
            if(bubble[i] > bubble[i+1]){
                bubleStable = 0;
            }
        }
        printf("%c%c ", dec[bubble[i]][0], dec[bubble[i]][1]);
    }printf("%c%c\n", dec[bubble[i]][0], dec[bubble[i]][1]);
    printf("%s\n", bubleStable? "Stable": "Not stable");

    for(i = 0; i<n; i++){
        mini = i;
        for(j=i+1;j<n;j++){
            if(dec[selection[j]][1] < dec[selection[mini]][1]) mini = j;
        }
        if(i != mini){
            swap(selection[i], selection[mini]);
        }
    }
    selectionStable = 1;
    for(i = 0; i<n-1; i++){
        if(dec[selection[i]][1] == dec[selection[i+1]][1]){
            if(selection[i] > selection[i+1]){
                selectionStable = 0;
            }
        }
        printf("%c%c ", dec[selection[i]][0], dec[selection[i]][1]);
    }printf("%c%c\n", dec[selection[i]][0], dec[selection[i]][1]);
    printf("%s\n", selectionStable? "Stable": "Not stable");

return 0;
}

