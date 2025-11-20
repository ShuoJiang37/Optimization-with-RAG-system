#include <stdio.h>
#include <string.h>
 
void bubble(int N,char s[],int a[]){
    int i,j,tmp;
    char x;
     
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
           if(a[j]>a[j+1]){
               tmp=a[j];
               a[j]=a[j+1];
               a[j+1]=tmp;
                
               x=s[j];
               s[j]=s[j+1];
               s[j+1]=x;
           } 
        }
    }
}
 
void selection(int N,char s[],int a[]){
    int i,j,min,tmp;
    char x;
     
    for(i=0;i<N-1;i++){
        min=i;
        for(j=i;j<N;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
         
        x=s[i];
        s[i]=s[min];
        s[min]=x;
    }
}
 
int main(void){
    char s[36],t[36];
    int a[36]={};
    int b[36]={};
    int i,N;
     
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%c%d",&s[i],&a[i]);
        getchar();
        b[i]=a[i];
    }
    strcpy(t,s);
     
    bubble(N,s,a);
    for(i=0;i<N;i++){
        printf("%c%d",s[i],a[i]);
        if(i!=N-1)printf(" ");
    }
    puts("\nStable");
     
    selection(N,t,b);
    for(i=0;i<N;i++){
        printf("%c%d",t[i],b[i]);
        if(i!=N-1)printf(" ");
    }
    puts("");
     
    if(strcmp(s,t)==0){
        puts("Stable");
    }
    else puts("Not stable");
     
    return 0;
}