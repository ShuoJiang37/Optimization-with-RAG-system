#include<stdio.h>
int main(){
    int i, j, n, w[100], wb[100], ws[100], a[100], ab[100], as[100], flag=1, tmp, minj, count=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)scanf(" %c%d", &w[i], &a[i]);
    for(i=0; i<n; i++){
        ab[i]=a[i];
        as[i]=a[i];
        wb[i]=w[i];
        ws[i]=w[i];
    }
    while(flag){
        flag=0;
        for(i=n-1; i>0; i--)if(ab[i]<ab[i-1]){
            tmp=ab[i];
            ab[i]=ab[i-1];
            ab[i-1]=tmp;
            tmp=wb[i];
            wb[i]=wb[i-1];
            wb[i-1]=tmp;
            flag=1;
        }
    }
    for(i=0; i<n; i++){
        minj=i;
        for(j=i; j<n; j++)if(as[j]<as[minj]){
                minj=j;
        }
        tmp=as[i];
        as[i]=as[minj];
        as[minj]=tmp;
        tmp=ws[i];
        ws[i]=ws[minj];
        ws[minj]=tmp;
    }
    for(i=0; i<n-1; i++)printf("%c%d ", wb[i], ab[i]);
    printf("%c%d\n", wb[n-1], ab[n-1]);
    printf("Stable\n");
    for(i=0; i<n-1; i++)printf("%c%d ", ws[i], as[i]);
    printf("%c%d\n", ws[n-1], as[n-1]);
    for(i=0; i<n; i++)if(wb[i]!=ws[i]){
        count=1;
        break;
    }
    if(count==0)printf("Stable\n");
    else printf("Not stable\n");
    return 0;
}