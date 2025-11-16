#include <stdio.h>

int insertion_sort(int A[], int n, int g){
    int i, j, v, cnt;
    cnt = 0;
    for(i = g; i < n; i++){
        v = A[i];
        j = i - g;
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
    return cnt;
}

int shell_sort(int A[], int n, int G[], int m){    //mはG[]の要素数
    int i;
    int cnt = 0;
    for(i = 0; i < m; i++){
        cnt = cnt + insertion_sort(A,n,G[i]);
    }
    return cnt;
}

int main( void ){
    int n, i, cnt, temp;
    int G[100];
    scanf("%d", &n);
    int A[n];
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    G[0] = 1;
    for(i = 1; G[i - 1] * 3 + 1 < n; i++){
        G[i] = G[i - 1] * 3 + 1;
    }
    int m = i;
    for(i = 0; i < m / 2; i++){ //G[]を逆順に入れ替える
        temp = G[i];
        G[i] = G[m - 1 - i];
        G[m - 1 - i] = temp;
    }
    cnt = shell_sort(A, n, G, m);

    printf("%d\n", m);
    for(i = 0; i < m; i++){
        printf("%d", G[i]);
        if(i < m - 1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", cnt);
    for(i = 0; i < n; i++){
        printf("%d\n", A[i]);
    }

    return 0;
}

