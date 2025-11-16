#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char suit;
    int val;
}Card;

void printArray(int, Card[]);
void bubbleSort(int, Card[]);
void selectionSort(int, Card[]);
int checkStable(int, Card[], Card[]);

int main(int argc, char** argv) {
    int size;
    scanf("%d\n", &size);
    if(size < 1 || size > 36)
        return (EXIT_FAILURE);
    Card array[size];
    
    for(int i = 0; i < size; i++){
        if(i == size - 1)
            scanf("%c%d", &array[i].suit, &array[i].val);
        else
            scanf("%c%d ", &array[i].suit, &array[i].val);
    }
    
    bubbleSort(size, array);
    selectionSort(size, array);
    
    
    return (EXIT_SUCCESS);
}

void printArray(int size, Card array[size]){
    for(int i = 0; i < size; i++){
        if(i == size - 1)
            printf("%c%d\n", array[i].suit, array[i].val);
        else
            printf("%c%d ", array[i].suit, array[i].val);
    }
}

void bubbleSort(int size, Card array[size]){
    Card tempA[size];
    for(int i = 0; i < size; i++)
        tempA[i] = array[i];
    Card temp;
    for(int i = 0; i < size; i++){
        for(int j = size - 1; j > i; j--){
            if(tempA[j].val < tempA[j-1].val){
                temp = tempA[j];
                tempA[j] = tempA[j-1];
                tempA[j-1] = temp;
            }
        }
    }
    printArray(size, tempA);
    if(checkStable(size, array, tempA))
        printf("Not stable\n");
    else
        printf("Stable\n");
}

void selectionSort(int size, Card array[size]){
    Card tempA[size];
    for(int i = 0; i < size; i++)
        tempA[i] = array[i];
    int minLoc;
    Card temp;
    for(int i = 0; i < size; i++){
        minLoc = i;
        for(int j = i; j < size; j++)
            if(tempA[j].val < tempA[minLoc].val)
                minLoc = j;
        temp = tempA[i];
        tempA[i] = tempA[minLoc];
        tempA[minLoc] = temp;
    }
    printArray(size,tempA);
    if(checkStable(size, array, tempA))
        printf("Not stable\n");
    else
        printf("Stable\n");
}

int checkStable(int size, Card array[size], Card temp[size]){
    int returnVal = 0; 
    Card temp1;
    int count = 0;
    int count2 = 0;
    for(int i = 0; i < size; i++){
        temp1 = array[i];
        for(int j = i + 1; j < size; j++)
            if(array[j].val == array[i].val)
                count++;
//            if(array[i].val == array[j].val){
//                temp1 = array[i];
//                temp2 = array[j];
//                for(int i2 = 0; i2 < size; i2++)
//                    if(temp[i2].val == temp1.val && temp[i2].suit == temp1.suit)
//                        for(int j2 = 0; j2 < size; j2++)
//                            if(temp[j2].val == temp2.val && i2 > j2)
//                                returnVal = 0;
//            }
        for(int k = 0; k < size; k++){
            if(array[i].val == temp[k].val && array[i].suit == temp[k].suit && count != 0)
                for(int j = k + 1; j < size; j++)
                    if(temp[k].val == temp[j].val)
                        count2++;
        }
        returnVal = count - count2;
        if(returnVal)
            break;
        count = 0;
        count2 = 0;
    }
    return returnVal;
}

