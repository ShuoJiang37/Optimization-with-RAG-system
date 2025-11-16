#include <stdio.h>
#include <stdlib.h>

int Gsize=0;
int *G;
int cnt=0;

int ReadValue() {
    int value;
    scanf("%d",&value);
    return value;
}
void ReadArray(int *Array,int index) {
    int i;
    for (i=0; i<index; i++) {
        scanf("%d",&Array[i]);
    }
}
void insertionSort(int Array[],int index,int g) {
    int i;
    for (i=g; i<index; i++) {
        int v=Array[i];
        int j=i-g;
        while (j>=0 && Array[j]>v) {
            Array[j+g]=Array[j];
            j-=g;
            cnt++;
        }
        Array[j+g]=v;
    }
}
void shellSort(int *Array,int index) {
    G=(int *)malloc(index*sizeof(int));
    for (int h=1; ; ) {
        if (h>index) {
            break;
        }
        G[Gsize]=h;
        Gsize++;
        h=3*h+1;
    }
    int i;
    for (i=Gsize-1; i>=0; i--) {
        insertionSort(Array,index,G[i]);
    }
}
int main() {
    int n=ReadValue();
    int A[n]; ReadArray(A,n);
    shellSort(A,n);
    printf("%d\n",Gsize);
    int i;
    for (i=Gsize-1; i>=0; i--) {
        printf("%d",G[i]);
        if (i) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",cnt);
    for (i=0; i<n; i++) {
        printf("%d\n",A[i]);
    }
    return 0;
}
