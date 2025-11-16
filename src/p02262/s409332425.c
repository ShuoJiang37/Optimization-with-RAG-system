#include <stdio.h>



int insertionSort(int A[], int n, int g){
    int i, v, j, cnt;
    cnt = 0;
    for(i = g; i < n; i++){
        v = A[i];
        j = i - g;
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }

        A[j + g] = v;
        
    }

    return cnt;

}


void shellsort(int A[], int n){
    int cnt = 0;
    int i;
    int m = 0;
    int h = 1;
    int g[n + 1];

    for(i = 0; ;i++){
        if(h > n || m > 100) break;
        g[i] = h;
        h = 3*h + 1;
        m++;
    }

    printf("%d\n",m);

    for(i =  m - 1; i >= 0; i--){
        printf("%d ", g[i]);
        cnt += insertionSort(A, n, g[i]);
    }

    printf("\n");


    printf("%d\n", cnt);

}

int main(){
    int A[1000000], n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    shellsort(A, n);
    for(i = 0; i < n; i++) printf("%d\n", A[i]);
    return 0;
}
