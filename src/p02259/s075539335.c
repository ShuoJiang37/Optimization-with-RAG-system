// 1_2_A
#include <stdio.h>

int BubbleSort(int [], int);

int main(){
    int length, i;
    int numbers[100] = {};

    scanf("%d", &length);
    for(i = 0; i < length; i++){
        scanf("%d", &numbers[i]);
    }

    BubbleSort(numbers, length);

    return 0;
}

int BubbleSort(int numbers[], int length){
    int flag = 1, cnt = 0, i = -1, j, tmp;

    while(flag){
        flag = 0;
        for(j = length - 1; j > i + 1; j--){
            if(numbers[j] < numbers[j - 1]){
                tmp = numbers[j - 1];
                numbers[j - 1] = numbers[j];
                numbers[j] = tmp;

                cnt++;
                flag = 1;
            }
        }
        i++;
    }

    for(i = 0; i < length - 1; i++){
        printf("%d ", numbers[i]);
    }
    printf("%d\n", numbers[length - 1]);
    printf("%d\n", cnt);
    return 0;
}