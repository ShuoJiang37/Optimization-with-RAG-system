#include <stdio.h>
#define N 36

typedef struct{
    int num;
    char type;
}Card;

int main(){
    Card in[N],bubble[N],selection[N];
    int n,i,j,minj,flag=0;
    Card stac,stac2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c%d",&in[i].type,&in[i].num);
        bubble[i]=in[i];
        selection[i]=in[i];
    }
    
    //bubble
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            if(bubble[j].num<bubble[j-1].num){
                stac=bubble[j];
                bubble[j]=bubble[j-1];
                bubble[j-1]=stac;
            }
        }
    }
    //bubble end
    
    //selection
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(selection[j].num<selection[minj].num){
                minj=j;
            }
        }
        stac=selection[minj];
        selection[minj]=selection[i];
        selection[i]=stac;
    }
    //selection end
    
    //bubble aply
    for(i=0;i<n-1;i++){
        printf("%c%d ",bubble[i].type,bubble[i].num);
        if(bubble[i].type!=selection[i].type)flag++;
    }
    printf("%c%d\nStable\n",bubble[n-1].type,bubble[n-1].num);
    //bubble aply end
    
    //selection aply
    for(i=0;i<n-1;i++){
        printf("%c%d ",selection[i].type,selection[i].num);
    }
    printf("%c%d\n",selection[n-1].type,selection[n-1].num);
    if(flag==0)printf("Stable\n");
    else printf("Not stable\n");
    
    return 0;

}