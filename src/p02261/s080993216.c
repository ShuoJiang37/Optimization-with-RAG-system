#include <stdio.h>

typedef struct {
    char design; 
    char value;
} Data;

void Copy(Data Array1[],Data Array2[],int index) {
    int i; 
    for (i=0; i<index; i++) {
        Array2[i]=Array1[i];
    }
}
int ReadValue() {
    int value; 
    scanf("%d",&value); 
    return value;
}
void ReadStruct(Data Array[],int index) {
    int i; 
    for (i=0; i<index; i++) {
        scanf(" %c",&Array[i].design);
        scanf(" %c",&Array[i].value);
    }
}
void swap(Data *a,Data *b) {
    Data temp; 
    temp=*a; 
    *a=*b; 
    *b=temp;
}
void bubbleSort(Data Array[],int index) {
    int flag=1; 
    while (flag) {
        flag=0; 
        int j; 
        for (j=index-1; j>=1; j--) {
            if (Array[j].value<Array[j-1].value) {
                swap(&Array[j],&Array[j-1]);
                flag=1;
            }
        }
    }
}
void selectionSort(Data Array[],int index) {
    int i;
    for (i=0; i<index; i++) {
        int minj=i,j; 
        for (j=i; j<index; j++) {
            if (Array[j].value<Array[minj].value) {
                minj=j;
            }
        }
        swap(&Array[i],&Array[minj]);
    }
}
int CompareData(Data Array1[],Data Array2[],int index) {
    int i; 
    for (int i=0; i<index; i++) {
        if (Array1[i].design!=Array2[i].design) {
            return 0;
        }
    }
    return 1;
}
void Display(Data Array1[],Data Array2[],int index) {
    for (int i=0; i<index; i++) {
        if (i>0) {
            printf(" ");
        }
        printf("%c%c",Array1[i].design,Array1[i].value);
    }
    printf("\n");
    printf("Stable\n");
     for (int i=0; i<index; i++) {
        if (i>0) {
            printf(" ");
        }
        printf("%c%c",Array2[i].design,Array2[i].value);
    }
    printf("\n");
    if (CompareData(Array1,Array2,index)) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
}
int main() {
    int N=ReadValue();
    Data bubbleSortData[N]; ReadStruct(bubbleSortData,N);
    Data selectionSortData[N]; Copy(bubbleSortData,selectionSortData,N);
    bubbleSort(bubbleSortData,N); selectionSort(selectionSortData,N);
    Display(bubbleSortData,selectionSortData,N);
    return 0;
}
