#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct card {
    char string;
    int number;
};

int main() {
    struct card input[100], bubble[100], selection[100], Tmp;
    int i = 0, j, k, n, m, l, key, minj, count;

    // カードの枚数
    scanf("%d", &n);
    key = n;

    while ( key-- ) {
        scanf(" %c%d", &input[i].string, &input[i].number);
        bubble[i].string = input[i].string;
        selection[i].string = input[i].string;
        bubble[i].number = input[i].number;
        selection[i].number = input[i].number;
        i++;
    }

    // bubble sort
    int flag = 1;

    while (flag) {
        flag = 0;
        for (j = n-1; j > 0; j--) {
            if (bubble[j].number < bubble[j-1].number){
                Tmp = bubble[j];
                bubble[j] = bubble[j-1];
                bubble[j-1] = Tmp;
                flag = 1;
                count++;
            }
        }
        i++;
    }

    // 選択ソート
    count = 0;
    flag = 0;
    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            // 配列要素の中で最小値を見つけ、indexをminjに保持
            if (selection[j].number < selection[minj].number) {
                minj = j;
            }
        }

        if (minj != i) {
            // 要素を交換する
            Tmp = selection[i];
            selection[i] = selection[minj];
            selection[minj] = Tmp;

            // 交換回数をカウントアップ
            count++;
        }
    }

    // 結果を表示

    // bubble
    printf("%c%d", bubble[0].string, bubble[0].number);
    for (i = 1; i < n; i++) {
        printf(" %c%d", bubble[i].string, bubble[i].number);
    }
    printf("\nStable\n");

    // selection
    printf("%c%d", selection[0].string, selection[0].number);
    for (i = 1; i < n; i++) {
        printf(" %c%d", selection[i].string, selection[i].number);
    }
    for (i = 0; i < n; i++) {
        if (bubble[i].string != selection[i].string){
            printf("\nNot stable\n");
            break;
        }
    }
    if (i == n) printf("\nStable\n");

    return 0;
}

