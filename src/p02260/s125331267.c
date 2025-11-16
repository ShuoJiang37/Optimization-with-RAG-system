#include<stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int array[100];

int selection(int *A, int N){
    int i,j;
    int minj;
    int change = 0;
    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[minj] > A[j]) minj = j;
        }
        if(minj != i){
            change++;
            swap(&A[minj], &A[i]);
        }
    }
    return change;
}

int main(void){
    int n;
    int i;
    int ans;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%d", &array[i]);
    }
    
    ans = selection(array, n);
    
    for(i=0;i<n;i++){
        if(i < n-1) printf("%d ", array[i]);
        else printf("%d\n", array[i]);
    }
    printf("%d\n", ans);
    
    return 0;
}