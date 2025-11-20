#include <stdio.h>

int main(int argc, const char * argv[]) {
    int flg = 1;
    int num;
    int i;
    int A[100];
    int temp;
    int j=0;
    int count = 0;
    
    scanf("%d", &num);
    
    for(i=0;i<num;i++){
        scanf("%d", &A[i]);
    }
    while(flg){
        flg = 0;
        for(i=num-1;i>j;i--){
            if(A[i] < A[i-1]){
                temp = A[i-1];
                A[i-1] = A[i];
                A[i] = temp;
                count ++;
                flg = 1;
            }
        }
        j++;
    }
    
    for(i=0;i<num;i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
    
    return 0;
}