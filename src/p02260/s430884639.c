#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    
    int length;
    
    scanf("%d", &length );
    
    int A[100];
    int i;
    
    for(i=0;i<length;i++)
    {
        scanf("%d", &A[i]);
    }

    int j;
    int t;
    int p = 0;
    
    for(i=0;i<length-1;i++)
    {
        int min=i;
        for(j=i+1;j<length;j++)
            if(A[min]>A[j])
                min=j;
                
        if(min!=i)
        {
            t=A[min];
            A[min]=A[i];
            A[i]=t;
            p = p + 1;
        }
    }
    
    for(int n=0; n<length; n++){
        printf("%d", A[n]);
        if(n!=length-1)
            printf(" ");
        else
        {
            printf("\n");
        }     
    }
    printf("%d\n", p);

    return 0;
}
