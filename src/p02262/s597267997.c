#include <stdio.h>
int main()
{
    int A[1000000]={0}, n, i, j, k, v, cnt=0, m, G[100]={0};
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    i = 0;
    G[0] = 1;
    while(1){
        if(G[i] > n){
            m = i;
            break;
        } else {
            G[i+1] = (3 * G[i]) + 1;
            i++;
        }
    }
    for(i = 0; i < m; i++){
        for(j = G[m-1-i]; j < n; j++){
            v = A[j];
            k = j -G[m-1-i];
            while(k >= 0 && A[k] > v){
                A[k + G[m-1-i]] = A[k];
                k = k - G[m-1-i];
                cnt++;
            }
            A[k + G[m-1-i]] = v;
        }
    }
    printf("%d\n", m);
    for(i =0; i < m; i++){
        if(i == m-1){
            printf("%d\n", G[m-1-i]);
        } else {
            printf("%d ", G[m-1-i]);
        }
    }
    printf("%d\n", cnt);
    for(i = 0; i < n; i++){
        printf("%d\n", A[i]);
    } 
    return 0;
}