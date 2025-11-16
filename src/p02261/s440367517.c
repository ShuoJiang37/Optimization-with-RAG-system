#include<stdio.h>

typedef struct {char a,b;} Card;

void bs(Card[],int);
void ss(Card[],int);
void str(Card*,char[]);
void print(Card[],int);

int isStable(Card[],Card[],int);

void bs(Card x[],int y){
    int i,j;
    Card v;

/*    for(i=0;i<=y;i++){*/
    for(i=0;i<y;i++){
        for(j=y-1;j>=i;j--){
            if(x[j].b<x[j-1].b){
                v=x[j];
                x[j]=x[j-1];
                x[j-1]=v;
            }
        }
    }
    return;
}

void ss(Card s[],int t){
    int i,j,minj;
    Card h;
    for(i=0;i<t;i++){
/*    for(i=0;i<=t;i++){ */
        minj=i;
        for(j=i;j<t;j++){
            if(s[minj].b>s[j].b){
                minj=j;
            }
        }
        h=s[minj];
        s[minj]=s[i];
        s[i]=h;
    }
    return;
}
void str(Card *u,char str[]){
    u->a=str[0];
    u->b=str[1]-'0';
    return;
}
void print(Card q[],int r){
    int i;
    for(i=0;i<r;i++){
        if(i!=0){
            printf(" ");
        }
        printf("%c%d",q[i].a,q[i].b);
    }
    printf("\n");
/*    return;*/
}
int isStable(Card a[],Card b[],int n){
    int i;

    for(i=0;i<n;i++){
/*    for(i=0;i<=n;i++){ */
        if(a[i].a!=b[i].a){
            return 0;
        }
    }
    return 1;
}
int main(void){
    int a,d,n;
/*    int a,d,N,n; */
    char ch[3];
    scanf("%d",&n);
/*
    scanf("%d",&N);
    n=N-1;
*/
    Card C1[100],C2[100];
/*    Card C1[n],C2[n];*/
    for(d=0;d<n;d++){
/*    for(d=0;d<=n;d++){ */
        scanf("%s",ch);
        str(&C1[d],ch);
    }
    for(d=0;d<n;d++){
/*    for(d=0;d<=n;d++){ */
        C2[d]=C1[d];
    }
    bs(C1,n);
    ss(C2,n);
    print(C1,n);
    printf("Stable\n");
    print(C2,n);
    a=isStable(C1,C2,n);
    if(a==1){
        printf("Stable\n");
    }
    else if(a==0){
        printf("Not stable\n");
    }
    return 0;
}

