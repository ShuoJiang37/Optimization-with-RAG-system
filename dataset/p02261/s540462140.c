#include<stdio.h>
#include<string.h>


int main(){
    int n,i,j;
    char mozia[100],mozib[100];
    int numa[100],numb[100];
    int flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c%d",&mozia[i],&numa[i]);
        strcpy(&mozib[i],&mozia[i]);
        numb[i]=numa[i];
    }
    //Bubble
    char tempa;
    int tempb;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(numa[j-1]>numa[j]){
                tempa=mozia[j];
                mozia[j]=mozia[j-1];
                mozia[j-1]=tempa;
                tempb=numa[j];
                numa[j]=numa[j-1];
                numa[j-1]=tempb;
            }
        }
    }
    for(i=0;i<n;i++){
        if(i!=0)printf(" ");
        printf("%c%d",mozia[i],numa[i]);
    }
    printf("\nStable\n");
    
    //Select
    int minj;
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(numb[j]<numb[minj])minj=j;
        }
        tempa=mozib[i];
        mozib[i]=mozib[minj];
        mozib[minj]=tempa;
        tempb=numb[i];
        numb[i]=numb[minj];
        numb[minj]=tempb;
    }
    for(i=0;i<n;i++){
        if(i!=0)printf(" ");
        printf("%c%d",mozib[i],numb[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        if(mozia[i]!=mozib[i])flag=1;
    }
    if(flag==1)printf("Not stable\n");
    else printf("Stable\n");
    
    return 0;
}


