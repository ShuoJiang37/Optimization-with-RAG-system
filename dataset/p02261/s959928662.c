#include <stdio.h>
#define N 10000
typedef struct {
        char name;
        int value;

}Card;
void Bubble(Card c[],int n){
        Card swap;
        int i,j;
        for(i=0; i<=n-1; i++) {
                for(j=n-1; j>=i+1; j--) {
                        if(c[j].value<c[j-1].value) {
                                swap=c[j];
                                c[j]=c[j-1];
                                c[j-1] =swap;
                        }
                }
        }
        for(i=0; i<n-1; i++) {
                printf("%c%d ",c[i].name,c[i].value);
        }
        printf("%c%d",c[i].name,c[i].value);
        printf("\n");
}
void Selection(Card c[],int n){
        Card swap;
        int i,j;
        int minj;
        for(i=0; i<n; i++) {
                minj=i;
                for(j=i+1; j<n; j++) {
                        if(c[j].value<c[minj].value) {
                                minj=j;

                        }

                }
                swap=c[i];
                c[i]=c[minj];
                c[minj] =swap;
        }
        for(i=0; i<n-1; i++) {
                printf("%c%d ",c[i].name,c[i].value);
        }
          printf("%c%d",c[i].name,c[i].value);
        printf("\n");
}
int isStable(Card A[],Card B[],int n){
        int flug=0,i;
        for(i=0; i<n; i++) {
                if(A[i].name!=B[i].name) {
                        flug++;
                }

        }
        if(flug==0) return 1;
        else return 0;
}
int main(){
        int i,n;

        Card A[N],B[N];
        scanf("%d",&n);
        for(i=0; i<n; i++) {
                scanf("%c%c%d",&A[i].name,&A[i].name,&A[i].value);
                B[i]=A[i];
        }

        Bubble(A, n);
        printf("Stable\n");
        Selection(B, n);
        if(isStable(A,B,n)) {
                printf("Stable\n");
        }
        else  {

                printf("Not stable\n");
        }
        return 0;
}