#include<stdio.h>

int main(){
    char s[36][3], bobble_s[36][3], selection_s[36][3];
    int i, j, k, l, n, c, flag, minj, stability = 1;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%s", s[i]);
        for (j = 0; j < 3; j++){
            selection_s[i][j] = bobble_s[i][j] = s[i][j];
        }
    }

    i = 0;
    flag = 1;
    while(flag != 0){
        flag = 0;
        for (j = n -1; j > i; j--){
            if(bobble_s[j][1] < bobble_s[j-1][1]){
                for (l = 0; l < 2; l++){
                    c = bobble_s[j][l];
                    bobble_s[j][l] = bobble_s[j-1][l];
                    bobble_s[j-1][l]  = c;
                    flag = 1;
                }
            }
        }
        i++;
    }
    
    printf("%s", bobble_s[0]);
    for(k = 1; k < n; k++){
        printf(" %s", bobble_s[k]);
    }
    printf("\n");

    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            for (k = 0; k < n; k++){
                for(l = k + 1; l < n; l++){
                    if(s[i][1] == s[j][1] && s[i][0] == bobble_s[l][0] && s[j][0] == bobble_s[k][0] && s[i][1] == bobble_s[l][1] && s[j][1] == bobble_s[k][1]){
                        stability = 0;
                    }
                }
            }
        }
    }

    if(stability == 1){
        printf("Stable\n");
    } else if (stability == 0){
        printf("Not stable\n");
    }

    stability = 1;
    for (i = 0; i < n; i++){
        minj = i;
        for (j = i; j < n; j++){
            if(selection_s[j][1] < selection_s[minj][1]){
                minj = j;
            }
        }
        if(minj != i){
            for (k = 0; k < 2; k++){
                c = selection_s[i][k];
                selection_s[i][k] = selection_s[minj][k];
                selection_s[minj][k] = c;
            }
        }
    }

    printf("%s", selection_s[0]);
    for (i = 1; i < n; i++){
        printf(" %s", selection_s[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            for (k = 0; k < n; k++){
                for(l = k + 1; l < n; l++){
                    if(s[i][1] == s[j][1] && s[i][0] == selection_s[l][0] && s[j][0] == selection_s[k][0] && s[i][1] == bobble_s[l][1] && s[j][1] == bobble_s[k][1]){
                        stability = 0;
                    }
                }
            }
        }
    }

    if(stability == 1){
        printf("Stable\n");
    } else if (stability == 0){
        printf("Not stable\n");
    }
    
    return 0;
}
