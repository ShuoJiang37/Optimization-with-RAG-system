#include <stdio.h>
int i,j,k,v,N,A[100];
int main(void){
    for(scanf("%d",&N);i<N;scanf("%d",&A[i++]));
    for(k=0;k<N;printf("%d%s",A[k],k==N-1?"\n":" "),k++);
    for(i=1;i<N;i++){
        v=A[i];
        for(j=i-1;A[j]>v;j--){
            A[j+1]=A[j];
        }
        A[j+1]=v;
        for(k=0;k<N;printf("%d%s",A[k],k==N-1?"\n":" "),k++);
    }

}