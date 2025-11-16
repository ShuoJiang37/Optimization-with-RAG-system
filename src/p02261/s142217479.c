#include <stdio.h>
#include <string.h>
#define N 36
void sele(void);
void bubl(void);
void pr(char);
char b[N][3];
char s[N][3];
int num;
int main(void){
    int i,math[N][2],mark=0;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%s",math[i]);
        strcpy(b[i],math[i]);
        strcpy(s[i],math[i]);
    }
    
    bubl();
    printf("%s",b[0]);
    for(i=1;i<num;i++){
         printf(" %s",b[i]);
    }
    printf("\nStable\n");
    
    sele();
    printf("%s",s[0]);
    for(i=1;i<num;i++){
         printf(" %s",s[i]);
    }
    
    for(i=0;i<num;i++){
       if(strcmp(s[i],b[i])!=0){
           mark =1;
           break;
       }
    }
    
    printf("%s",(mark==0)?"\nStable\n":"\nNot stable\n");
    
    return 0;
}

void sele(void){
    int i,j,min;
    char temp[3];
    for(i=0;i<=num-2;i++){
        min = i;
        for(j=i;j<=num-1;j++){
            if(s[j][1]<s[min][1]){
               min = j;
            }
        }
        
       if(i != min ){
            strcpy(temp,s[min]);
            strcpy(s[min],s[i]);
            strcpy(s[i],temp);
        }
    }
}

void bubl(void){
    int i,j;
    char temp[3];
    for(i=0;i<num-1;i++){
        for(j=num-1;j>=i+1;j--){
            if(b[j][1]<b[j-1][1]){
                strcpy(temp,b[j-1]);
                strcpy(b[j-1],b[j]);
                strcpy(b[j],temp);
            }
        }
    }
}



