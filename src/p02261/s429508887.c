#include <stdio.h>

typedef struct{
    int value;
    char mark;
}CARD;

void bubbleSort(CARD c[],int N){
    int i,j;
    int v;
    char m;
    for(i=0;i<N;i++){
        for(j=N-1;j>=i+1;j--){
            if(c[j].value<c[j-1].value){
                v=c[j].value;
                c[j].value=c[j-1].value;
                c[j-1].value=v;
                m=c[j].mark;
                c[j].mark=c[j-1].mark;
                c[j-1].mark=m;
            }
        }
    }
}
void selectionSort(CARD c[],int N){
    int i,j;
    int minj;
    int v;
    char m;
    for(i=0;i<N;i++){
        minj=i;
        for(j=i+1;j<N;j++){
            if(c[j].value<c[minj].value)minj=j;
        }
        v=c[i].value;
        c[i].value=c[minj].value;
        c[minj].value=v;
        m=c[i].mark;
        c[i].mark=c[minj].mark;
        c[minj].mark=m;
    }
}
void checkStable(CARD c[],CARD o[],int N){
    int i,j;
    char flag[N];
    for(i=0;i<N;i++)flag[i]='n';
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(c[i].value==o[j].value&&flag[j]=='n'){
                if(c[i].mark!=o[j].mark){
                    printf("Not stable\n");
                    return;
                }
                flag[j]='y';
                break;
            }
        }
    }
    printf("Stable\n");
}
int main(void){
    int i;
    
    int N;
    scanf("%d",&N);
    CARD o[N],c1[N],c2[N];
    for(i=0;i<N;i++){
        scanf("\n%c%d ",&o[i].mark,&o[i].value);
        c1[i].mark=o[i].mark;
        c1[i].value=o[i].value;
        c2[i].mark=o[i].mark;
        c2[i].value=o[i].value;
    }
    
    bubbleSort(c1,N);
    printf("%c%d",c1[0].mark,c1[0].value);
    for(i=1;i<N;i++)printf(" %c%d",c1[i].mark,c1[i].value);
    printf("\n");
    checkStable(c1,o,N);
    
    selectionSort(c2,N);
    printf("%c%d",c2[0].mark,c2[0].value);
    for(i=1;i<N;i++)printf(" %c%d",c2[i].mark,c2[i].value);
    printf("\n");
    checkStable(c2,o,N);
    
    
    return 0;
}
