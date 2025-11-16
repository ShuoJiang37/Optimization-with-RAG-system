#include <stdio.h>

struct card{
    char mark;
    int num;
};

int main(){

    int n;
    scanf("%d\n",&n);

    struct card A[n];//元入力
    struct card B[n];//バブルソート
    struct card C[n];//選択ソート
    struct card cp;

    char air;
    int flag=1;
    
    //初期入力
    for(int i=0;i<n;i++){
        scanf("%c%d%c",&A[i].mark,&A[i].num,&air);
        B[i]=A[i];
        C[i]=A[i];
    }

    //バブルソート
    while(flag){
        flag=0;
        for(int i=0;i<n-1;i++){
            if(B[i].num>B[i+1].num){
                cp=B[i];
                B[i]=B[i+1];
                B[i+1]=cp;
                flag=1;
            }
        }
    }

    //選択ソート
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int f=i+1;f<n;f++){
            if(C[min].num>C[f].num){
                min=f;
            }
        }
        cp=C[min];
        C[min]=C[i];
        C[i]=cp;
    }

    //安定か否か
    int stable=1;
    for(int i=0;i<n;i++){
        if(B[i].num!=C[i].num||B[i].mark!=C[i].mark){
            stable=0;
        }
    }

    printf("%c%d",B[0].mark,B[0].num);
    for(int i=1;i<n;i++){
        printf(" %c%d",B[i].mark,B[i].num);
    }
    printf("\n");
    printf("Stable\n");
    
    printf("%c%d",C[0].mark,C[0].num);
    for(int i=1;i<n;i++){
        printf(" %c%d",C[i].mark,C[i].num);
    }
    printf("\n");
    
    if(stable==1){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
    
}
