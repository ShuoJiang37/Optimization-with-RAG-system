a,b,i,j,N,p,P,t[36],c[36],T[36],C[36];
int Q(int *a,int *b){
    for(i=0;i<N;printf("%c%d%s",a[i],b[i],i==N-1?"\n":" "),i++);
}
B(){
    for(i=0;i<N;i++)
    for(j=N-1;j>0;j--)
        if(t[j-1]>t[j]){
            t[j]^=t[j-1]^=t[j]^=t[j-1];
            c[j]^=c[j-1]^=c[j]^=c[j-1];
        }
    Q(c,t);
    puts("Stable");
}
S(){
    for(i=0;i<N;i++){
        for(j=p=i;j<N;j++)if(T[j]<T[p])p=j;
        P=T[p];T[p]=T[i];T[i]=P;
        P=C[p];C[p]=C[i];C[i]=P;
    }
    Q(C,T);
    for(i=p=0;i<N;i++)if(c[i]==C[i]&&t[i]==T[i])p++;
    puts(p==N?"Stable":"Not stable");
}

int main(){
    for(scanf("%d",&N);i<N;scanf(" %c%d",&c[i],&t[i]),T[i]=t[i],C[i]=c[i],i++);
    B();S();

}