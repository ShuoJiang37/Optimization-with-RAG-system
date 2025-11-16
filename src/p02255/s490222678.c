#include<stdio.h>

void insersionSort(int A[1000], int n){
    int i, j, k, v;
 
    for(i=1; i<n; i++){
        v = A[i];
        j =i - 1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printf("%d", A[0]);
        for(k=1; k<n; k++){
             printf(" %d", A[k]);
        }
        printf("\n");
    }

}

int main(){
    int N, i, j, k;
    int A[1000];

    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    printf("%d", A[0]);
    for(k=1; k<N; k++){
         printf(" %d", A[k]);
    }
   printf("\n");

    insersionSort(A, N);

    return 0;
}