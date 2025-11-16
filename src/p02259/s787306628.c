#include<stdio.h>

#define NUMBER 100

int main(){

    int i,n;
    int count = 0;
    int flag,stock;
    int A[NUMBER];

    scanf("%d",&n);

    for(i=0;i<n;i++){

        scanf("%d",&A[i]);
        
    }

    flag = 1;

    while(flag>0){

        flag = 0;

        for(i=n-1;i>=1;i--){

            if(A[i]<A[i-1]){

                stock = A[i];
                A[i] = A[i-1];
                A[i-1] = stock;
                count++;

                flag = 1;
            }
        }
    }

    for(i=0;i<n;i++){

        if(i != n && i != 0){
            printf(" ");
        }

        printf("%d",A[i]);

    }

    printf("\n");
    printf("%d\n",count);

    return 0;
}
