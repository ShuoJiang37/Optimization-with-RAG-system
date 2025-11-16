#include<stdio.h>
int selectionSort(char mk[],char N[],int n){
    int i,j,minj;
    char p;
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(N[j]<N[minj]){
                minj=j;
            }
        }
        p=N[i];
        N[i]=N[minj];
        N[minj]=p;
        p=mk[i];
        mk[i]=mk[minj];
        mk[minj]=p;
    }
    return 0;
}

int bubbleSort(char mk[],char N[],int n){
    int i,j;
    char p;
    for(i=0;i<n;i++){
        for(j=n-1;i<j;j--){
            if(N[j]<N[j-1]){
                p=N[j];
                N[j]=N[j-1];
                N[j-1]=p;
                p=mk[j];
                mk[j]=mk[j-1];
                mk[j-1]=p;
            }
        }
    }
    return 0;
}
int main(){
    int i,n;
    char num[36],mk[36],num1[36],num2[36],mk1[36],mk2[36];
    char str[2];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",str);
        mk1[i]=str[0];
        num1[i]=str[1];
        mk[i]=str[0];
        num[i]=str[1];
    }
    
    bubbleSort(mk1,num1,n);
    for(i=0;i<n-1;i++){
        printf("%c%c ",mk1[i],num1[i]);
    }
    printf("%c%c\n",mk1[n-1],num1[n-1]);
    printf("Stable\n");
    
    for(i=0;i<n;i++){
        mk2[i]=mk[i];
        num2[i]=num[i];
    }
    
    selectionSort(mk2,num2,n);
    for(i=0;i<n-1;i++){
        printf("%c%c ",mk2[i],num2[i]);
    }
    printf("%c%c\n",mk2[n-1],num2[n-1]);
    
    if((strncmp(num1,num2,n)==0) && (strncmp(mk1,mk2,n)==0)){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }
    return 0;
}
