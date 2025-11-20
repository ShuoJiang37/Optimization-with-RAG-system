#include <stdio.h>

#define MAX 100

int main(){

    int A[MAX],N;
    int key;
    int i=0,j,k;

    scanf("%d",&N);

    while(i < N){
        scanf("%d",&A[i]);
        i++;
    }

    k = 0;
    while(k < (N -1)){
        printf("%d ",A[k]);
        k++;    
    }
    printf("%d\n",A[N-1]);

    // scanf("%d %d %d %d %d %d",&A[0],&A[1],&A[2],&A[3],&A[4],&A[5]);
    // printf("%d %d %d %d %d %d\n",A[0],A[1],A[2],A[3],A[4],A[5]);

    for(i=1; i<=(N-1);i++){
        key = A[i];
        
        /* insert A[i] into the sorted sequence A[0,...,i-1] */
        j = i - 1;
        while((j >= 0) & (A[j] > key)){
            A[j+1] = A[j];
            // printf("   j:A[j]:A[j+1] = %d,%d,%d\n",j,A[j],A[j+1]);
            j--;
        }

        A[j+1] = key;
        // printf("** j:A[j]:A[j+1] = %d,%d,%d\n",j,A[j],A[j+1]);
        
        /* output intermediate sequence for each step */
        k = 0;
        while(k < (N -1)){
            printf("%d ",A[k]);
            k++;    
        }
        printf("%d\n",A[N-1]);

    }

    // i = 0;
    // while(i < N){
    //     printf("%d ",A[i]);
    //     i++;    
    // }
    // printf("\n");

    return 0;

}
