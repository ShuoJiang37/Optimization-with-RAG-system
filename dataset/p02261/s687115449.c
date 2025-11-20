#include <stdio.h>
i,j,N,p,P,t[36],c[36],T[36],C[36];
B(){
    for(i=0;i<N;i++)
    for(j=N-1;j>0;j--)
        if(t[j-1]>t[j]){
            t[j]^=t[j-1]^=t[j]^=t[j-1];
            c[j]^=c[j-1]^=c[j]^=c[j-1];
        }
}
S(){
    for(i=0;i<N;i++){
        for(j=p=i;j<N;j++)if(T[j]<T[p])p=j;
        P=T[p];T[p]=T[i];T[i]=P;
        P=C[p];C[p]=C[i];C[i]=P;
    }
}
int main(void){
    for(scanf("%d",&N);i<N;scanf(" %c%d",&c[i],&t[i]),T[i]=t[i],C[i]=c[i],i++);
    B();S();
    for(i=0;i<N;printf("%c%d%s",c[i],t[i],i==N-1?"\n":" "),i++);
    puts("Stable");
    for(i=0;i<N;printf("%c%d%s",C[i],T[i],i==N-1?"\n":" "),i++);
    for(i=p=0;i<N;i++){
        if(c[i]==C[i]){
            if(t[i]==T[i]){
                p++;
            }
        }
    }
    puts(p==N?"Stable":"Not stable");
}