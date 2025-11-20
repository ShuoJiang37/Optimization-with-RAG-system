#include <stdio.h>
#include <string.h>

int main(void){
    int n,i,j,min,num,flg=1;
    char k[4];
    char a[36][4];
    char b[36][4];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
        strcpy(b[i],a[i]);
    }
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j][1]>a[j+1][1]){
                strcpy(k,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],k);
            }
        }
    }
    
    for(i=0;i<n;i++){
        printf("%s",a[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\nStable\n");
    
    for(i=0;i<n-1;i++){
        min = b[i][1];
        num = i;
        for(j=i+1;j<n;j++){
            if(min>b[j][1]){
                min = b[j][1];
                num = j;
                
            }
        }
        if(num!=i){
            strcpy(k,b[i]);
            strcpy(b[i],b[num]);
            strcpy(b[num],k);
        }
    }
    for(i=0;i<n;i++){
        printf("%s",b[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n");
    for(i=0;i<n;i++){
        if(strcmp(a[i],b[i])!=0){
            printf("Not stable\n");
            flg = 2;
            break;
        }
    }
    if(flg==1){
        printf("Stable\n");
    }
    
    return 0;
}

