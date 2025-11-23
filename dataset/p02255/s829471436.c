#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int length;
    
    scanf("%d", &length );
    
    int i;
    int A[100];
    
    for(i=0;i<length;i++)
    {
        scanf("%d", &A[i]);
    }
    
    int key;
    int j;
    
    for(i=0; i<length; i++){
        key = A[i];
        
        for(j=i; j>0 && A[j-1]>key; j--){
            A[j]=A[j-1];
        }
        A[j]=key;
        
        for(int n=0; n<length; n++){
            printf("%d", A[n]);
            if(n!=length-1)
                printf(" ");
            else
                printf("\n");
        }
    } 
    return 0;
}
