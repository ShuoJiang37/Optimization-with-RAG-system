#include <stdio.h>
struct card{
    char suit;
    int value;
};
struct card c[2][36];

void Swap(int b, int x, int y){
    int v;
    char s;
    v=c[b][x].value;
    s=c[b][x].suit;
    c[b][x].value=c[b][y].value;
    c[b][x].suit=c[b][y].suit;
    c[b][y].value=v;
    c[b][y].suit=s;
}

void Print(int b, int n){
    for(int i=0;i<n;i++){
        printf("%c%d",c[b][i].suit,c[b][i].value);
        if(i!=n-1) printf(" ");
        else printf("\n");
    }
}

void isStable(int x,int n){
    int flag=0;
    int y;
    if(x==0) y=1;
    else y=0;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int a=0;a<n;a++){
                for(int b=a+1;b<n;b++){
                    if(c[x][i].value==c[x][j].value && c[x][i].value==c[y][b].value && c[x][i].suit==c[y][b].suit && c[x][j].value == c[y][a].value && c[x][j].suit == c[y][a].suit){
                        printf("Not stable\n");
                        flag=1;
                        break;
                    }
                }
                if(flag==1) break;
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    if(flag==0) printf("Stable\n");
}

void BubbleSort(int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(c[0][j].value<c[0][j-1].value){
                Swap(0,j,j-1);
            }
        }
    }
    Print(0,n);
    isStable(0,n);
}

void SelectionSort(int n){
    int i,j,minj;
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(c[1][j].value<c[1][minj].value){
                minj=j;
            }
       }
       Swap(1,i,minj);
    }
    Print(1,n);
    isStable(1,n);
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%c",&c[0][i].suit);
        if(c[0][i].suit<65||89<c[0][i].suit) scanf("%c",&c[0][i].suit);
        scanf("%d",&c[0][i].value);
        c[1][i]=c[0][i];
    }
    BubbleSort(n);
    SelectionSort(n);
    
    return 0;
}

