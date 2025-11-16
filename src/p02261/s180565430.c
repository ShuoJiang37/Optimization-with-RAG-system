#include <stdio.h>
#include <string.h>
void bubbleSort(char c[][3],int n){
    int flag=1,j,i;
    char tmp[3];
    for(i=0;flag;i++){
        flag=0;
        for(j=n-1;j>=i+1;j--){
            if(c[j][1]<c[j-1][1]){
                strcpy(tmp,c[j]);
                strcpy(c[j],c[j-1]);
                strcpy(c[j-1],tmp);
                flag=1;
            }
        }
    }
    for(j=0;j<n;j++){
        printf("%s%s",c[j],(j==n-1?"\n":" "));
    }
} 



void selectionSort(char c[][3],int n){
    int i,minj,j;
    char tmp[3];
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(c[j][1]<c[minj][1]){
                minj=j;
            }
        }
        strcpy(tmp,c[i]);
        strcpy(c[i],c[minj]);
        strcpy(c[minj],tmp);
    }
    for(j=0;j<n;j++){
        printf("%s%s",c[j],(j==n-1?"\n":" "));
    }
}

int main(void){
    char c[37][3];
    char c2[37][3];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",c[i]);
        strcpy(c2[i],c[i]);
        //printf("%s%s",c[i],(i==n-1?"\n":" "));
    }
    bubbleSort(c,n);
    printf("Stable\n");
    selectionSort(c2,n);
    for(i=0;i<n;i++){
        if(c[i][0]!=c2[i][0]){
            printf("Not stable\n");
            return 0;
        }
    }
    
    printf("Stable\n");
    return 0;
}

