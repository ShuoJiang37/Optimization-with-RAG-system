#include <stdio.h>
#include <math.h>
#include<stdlib.h>
void insertionSort(int A[],int N,int g,int *cnt){
    int i,j;
    int v;
    
    for(i=g;i<N;i++){
        v=A[i];
        j=i-g;
        while(j>=0&&A[j]>v){
            A[j+g]=A[j];
            j=j-g;
            (*cnt)++;
        }
        A[j+g]=v;
    }
}
int main(void){
    int i;
    int N;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++)scanf("%d",&A[i]);
    
    int cnt=0;
    int m=0;
    int g=N/2;
    int *G;
    G=(int*)malloc(sizeof(int));
    while(g!=0){
        G=(int*)realloc(G,sizeof(int)*(m+1));
        G[m]=g;
        m++;
        g=g/2;
    }
    if(m==0){
        G[0]=1;
        m++;
    }
    printf("%d\n",m);
    printf("%d",G[0]);
    for(i=1;i<m;i++)printf(" %d",G[i]);
    printf("\n");
    
    for(i=0;i<m;i++){
        insertionSort(A,N,G[i],&cnt);
    }
    printf("%d\n",cnt);
    for(i=0;i<N;i++)printf("%d\n",A[i]);

    return 0;
}
