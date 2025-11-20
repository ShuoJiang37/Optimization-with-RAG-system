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
    int temp;

    int ppp=0;
    for (i = 0; i < length - 1; i++)
	for (j = 0; j < length - 1 - i; j++)
            if (A[j] > A[j + 1]) {
		temp = A[j];
		A[j] = A[j + 1];
		A[j + 1] = temp;
                ppp = ppp+1;
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
    printf("%d\n", ppp);
    return 0;

}
