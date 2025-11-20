#include <stdio.h>
static const int N =100;
void Trace(int A[], int n){
        int i;
        for ( i = 1; i <= n; i++ ) {
                if ( i > 1 ) printf(" ");
                printf("%d", A[i]);
        }
        printf("\n");
}

void Isort(int A[],int n){
        int i,j,v;
        for(i=1; i<=n; i++) {
                v=A[i];
                j=i-1;
                while(j>0 && A[j]>v) {
                        A[j+1]=A[j];
                        j--;
                }
                A[j+1]=v;
                Trace(A,n);
        }

}
int main(){
        int n,i,j;
        int A[N+1];
        scanf("%d",&n);
        for (i=1; i<=n; i++) {
                scanf("%d",&A[i]);
        }
        Isort(A,n);
        return 0;
}
