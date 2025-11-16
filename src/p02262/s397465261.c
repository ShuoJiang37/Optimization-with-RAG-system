#include "stdlib.h"
#include "stdio.h"

int N;
int num[1000010];
int G[100];
int cnt;

void printfResult(){
    int i;
    for(i=0; i<N; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}

void insertSort(int g){
    int i, j;
    int temp;
    for(i=g; i<N; i++){
        temp = num[i];
        j = i-g;
        while(j>=0 && temp<num[j]){
            num[j+g] = num[j];
            j = j - g;
            cnt++;
        }
        num[j+g] = temp;
    }
}

void shellSort(){
    int i;
    int m=0;
    G[0] = 1;
    while((3 * G[m] + 1) <= N){
        ++m;
        G[m] = 3 * G[m-1] + 1;
    }
    printf("%d\n", m+1);
    for(i=m; i>0; i--){
        printf("%d ",G[i]);
    }
    printf("%d\n", G[0]);
    for(i=m; i>=0; i--){
        insertSort(G[i]);
    }
}



int main(){
    //freopen("D:\\zhouyu\\study\\codes\\SortSample.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &num[i]);
    }
    shellSort();
    printf("%d\n", cnt);
    for(int i=0; i<N; i++){
        printf("%d\n", num[i]);
    }
}
