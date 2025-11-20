#include<stdio.h>
#define Num 100

int main(){

    int i,j,n;
    int count = 0;
    int mj,stock;
    int a[Num];

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        mj = i;
        for(j=i;j<n;j++){
            if(a[j]<a[mj])
            mj = j;
        }
        if(i != mj){
            stock = a[i];
            a[i] = a[mj];
            a[mj] = stock;
            count++;
        }
    }

    for(i=0;i<n;i++){
        if(i != n && i != 0){
            printf(" ");
        }

        printf("%d",a[i]);

    }

    printf("\n");
    printf("%d\n",count);

    return 0;
}
