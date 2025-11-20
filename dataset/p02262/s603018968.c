// Shell Sort
#include <stdio.h>

int cnt;
int len;
int g[101];

void shellSort(int a[], int n){
    int i, j, h, x=1;
    len = cnt = 0;
    for(i=0; x<=n; i++){
        g[i] = x;
        x = x*3+1;
        len++;
    }
    for(h=len-1; h>=0; h--){
        for(i=g[h]; i<n; i++){
            int key = a[i];
            j = i-g[h];
            while(j >= 0 && a[j] > key){
                cnt++;
                a[j+g[h]] = a[j];
                j -= g[h];
            }
            a[j+g[h]]=key;
        }
    }   
}

int main(void){
    int n;
    int a[1000001];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    shellSort(a, n);
    printf("%d\n", len);
    for(int i=len-1; i>=0; i--){
        printf("%d", g[i]);
        if(i) printf(" ");
    }
    printf("\n%d\n", cnt);
    for(int i=0; i<n; i++) printf("%d\n", a[i]);
    return 0;    
}
