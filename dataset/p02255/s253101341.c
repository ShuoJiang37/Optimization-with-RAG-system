i,j,k,v,N,A[100];
main(){
    for(scanf("%d",&N);i<N;scanf("%d",&A[i++]));
    for(k=0;k<N;printf("%d%s",A[k],k==N-1?"\n":" "),k++);
    for(i=1;i<N;i++){
        for(j=i-1,v=A[i];A[j]>v;A[j+1]=A[j],j--);
        A[j+1]=v;
        for(k=0;k<N;printf("%d%s",A[k],k==N-1?"\n":" "),k++);
    }
}