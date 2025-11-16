// 1_2_B
#include <stdio.h>

void SelectionSort(int [], int);
void Display(int [], int, int);

int main(){
    int length, i;
    int numbers[100] = {};

    scanf("%d", &length);
    for(i = 0; i < length; i++){
        scanf("%d", &numbers[i]);
    }

    SelectionSort(numbers, length);

    return 0;
}

void SelectionSort(int numbers[], int length){
    int i, minj, j, minimum, cnt = 0;

    for(i = 0; i < length; i++){
        minj = i;
        for(j = i; j < length; j++){
            if(numbers[j] < numbers[minj]){
                minj = j;
            }
        }

        if(minj != i){
            minimum = numbers[minj];
            numbers[minj] = numbers[i];
            numbers[i] = minimum;
            cnt++;
        }

    }

    Display(numbers, length, cnt);

    return;
}

void Display(int numbers[], int length, int cnt){
    int i;
    for(i = 0; i < length - 1; i++){
        printf("%d ", numbers[i]);
    }
    printf("%d\n", numbers[length - 1]);
    printf("%d\n", cnt);
    return;
}