#include <stdio.h>
#include <string.h>

#define NUM 36

int myatoi(char);

int main()
{
    char a[NUM][5],b[NUM][5],d[5];
    int c[NUM],f[NUM],n;
    int i,j,k = 0,flag = 1,minj = 0;
    
    scanf("%d",&n);
    
    for(i = 0;i < n;i++){
        scanf("%s",a[i]);
        strcpy(b[i],a[i]);
        c[i] = myatoi(a[i][1]);
        f[i] = c[i];
    }
    
    while(flag){
        flag = 0;
        for(j = i-1;j > 0;j--){
            if(c[j] < c[j-1]){
                strcpy(d,a[j-1]);
                strcpy(a[j-1],a[j]);
                strcpy(a[j],d);
                k = c[j];
                c[j] = c[j-1];
                c[j-1] = k;
                flag = 1;
            }
        }
    }
    
    printf("%s",a[0]);
    for(i = 1;i < n;i++){
        printf(" %s",a[i]);
    }
    printf("\n");
    printf("Stable\n");
    
    for(i = 0;i < n;i++){
        minj = i;
        for(j = i;j < n;j++){
            if(f[j] < f[minj]) minj = j;
        }
        if(i != minj){
            strcpy(d,b[i]);
            strcpy(b[i],b[minj]);
            strcpy(b[minj],d);
            k = f[i];
            f[i] = f[minj];
            f[minj] = k;
        }
    }
    
    printf("%s",b[0]);
    for(i = 1;i < n;i++){
        printf(" %s",b[i]);
    }
    printf("\n");
    
    for(i = 0;i < n;i++){
        k = strcmp(a[i],b[i]);
        if(k != 0) break;
    }
    if(k == 0) printf("Stable\n");
    else printf("Not stable\n");
    
    return 0;
}

int myatoi(char x)
{
    if(x == '1') return 1;
    if(x == '2') return 2;
    if(x == '3') return 3;
    if(x == '4') return 4;
    if(x == '5') return 5;
    if(x == '6') return 6;
    if(x == '7') return 7;
    if(x == '8') return 8;
    if(x == '9') return 9;
    else return 0;
}

