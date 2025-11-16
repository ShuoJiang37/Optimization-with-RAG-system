#include<stdio.h>

int bubbleSort(int A[], int n){
    int flag = 1;
    int i = 0;
    int cnt = 0;
    int j;

    while(flag == 1){
        flag = 0;
        for(j=n-1;j>i;j--){
            if(A[j-1] > A[j]){
                int swap = A[j];
                A[j]=A[j-1];
                A[j-1]=swap;
                flag = 1;
                cnt++;
            }
        }
        i++;
    }
    return cnt;
}


int main(){
    int i, n, ans;
    int A[100];

    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    ans = bubbleSort(A, n);

    for(i=0;i<n;i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", ans);

    return 0;
}
