#include <stdio.h>
#include <string.h>
#define NUM(n) ((int)((n-'1')+1))
#define CONV(str) (NUM(str[1])+(int)(str[0]*10))
void print_ary(int *ary, int n){
    for(int i=0;i<n;i++){
        printf("%c%d",ary[i]/10,ary[i]%10);
        (i==n-1)? printf("\n"):printf(" ");
    }
}
void bubblesort(int *con, int *chk, int n){
    int i,j,buf;
    for(i=0;i<n;i++){chk[i]=con[i];}
    for(j=0;j<n-1;j++){
        for(i=0;i<n-1-j;i++){
            if (chk[i]%10>chk[i+1]%10){
                buf=chk[i];chk[i]=chk[i+1];chk[i+1]=buf;    
            }
        }
    }
    print_ary(chk,n);
    printf("Stable\n");
}
void selectionsort(int *ary, int *chk, int n){
    int m,i,j,addr,buf,flg=0;
    for(i=0;i<n;i++,m=1e9){
        for(j=i;j<n;j++){
            if (m>ary[j]%10){m=ary[j]%10,addr=j;}
        }
        buf=ary[i],ary[i]=ary[addr],ary[addr]=buf;
    }
    print_ary(ary,n);
    for(i=0;i<n;i++){if (chk[i] != ary[i]){flg=1;break;}}
    (flg==0)? printf("Stable\n"):printf("Not stable\n");
}
int main(void){
    int n,i;
    scanf("%d",&n);
    char ary[n][3];int con[n],chk[n];
    for(i=0;i<n;i++){scanf("%s",ary[i]);}
    for(i=0;i<n;i++){con[i]=CONV(ary[i]);}
    bubblesort(con,chk,n);
    selectionsort(con,chk,n);
    return 0;
}

