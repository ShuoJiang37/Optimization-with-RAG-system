// 1_1_A
#include <stdio.h>
#include <stdlib.h>

void PrintSequence(int numbers[], int length){
    int i;
    for(i = 0; i < length - 1; i++){
        printf("%d ", numbers[i]);
    }
    printf("%d\n", numbers[i]);
    return;
}

void InsertionSort(int numbers[], int length){
    int i, j, v;
    for(i = 0; i < length; i++){
        v = numbers[i];
        j = i - 1;
        while(j >= 0 && numbers[j] > v){
            numbers[j+1] = numbers[j];
            j--;
        }
        numbers[j+1] = v;
        PrintSequence(numbers, length);
    }
    return;
}

int main(){
    int n, i, *numbers;
    scanf("%d", &n);

    numbers = (int*) malloc(sizeof(int)*n);

    for(i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    InsertionSort(numbers, n);
    free(numbers);
    return 0;
}