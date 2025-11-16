#include<stdio.h>

int selectionSort(int A[], int n){
    int i, j, minj, swap;
    int cnt = 0;
    for(i=0;i<n;i++){
        minj = i;
        
        for(j=i;j<n;j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        swap = A[i]; A[i] = A[minj]; A[minj] = swap;  //swap
        if(i != minj)   cnt++;                        //swap回数を記録
    }
    return cnt;
}

int main(){
    int i, n, ans;
    int A[100];

    scanf("%d", &n);                //nと数列Aを入力
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    ans = selectionSort(A, n);      //ソートを実行

    for(i=0;i<n;i++){               //ソートした数列とswap回数を出力
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", ans);

    return 0;
}
