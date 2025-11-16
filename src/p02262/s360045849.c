#include <stdio.h>

int cnt = 0;

//画面表示用
void printconsole(int *A,int n){
    for (int k = 0; k < n; k++) {
        printf("%d",A[k]);
        if(k != n-1)putchar(' ');
    }
    putchar('\n');
}


//挿入ソート
void insertionSort(int *A,int n,int g){
    int v,j;
    for (int i = g; i < n; i++) {
        v = A[i];
        j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

//シェルソート
void shellsort(int *A,int n){
    
    int m = 5;
    int cm = 0;
    int G[5] = {1000,100,10,4,1};
    for (int i = 0; i < m; i++) {
        insertionSort(A, n,G[i]);
        if(G[i] <= n){
            cm++;
        }
    }
    
    printf("%d\n",cm);
    for (int i = m - cm; i < m ; i++) {
        printf("%d",G[i]);
        if(i != m - 1 )printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);
    for (int i = 0; i < n; i++) {
        printf("%d\n",A[i]);
    }
}


int main(int argc, const char * argv[]) {
    
    int n;
    int A[1000000];
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
    
    shellsort(A, n);
    
    /*
    printf("%d\n",n);
    for (int i = 0; i < n; i++) {
        printf("%d\n",A[i]);
    }
     */

    return 0;
}

