#include <stdio.h>

typedef struct{
    char c;
    int value;
} card;

int main(){
int i,j,N,minj;
card C1[36],C2[36];
card temp,temp2;

scanf("%d",&N);

for(i=0;i<N;i++){
scanf(" %c%d",&C1[i].c,&C1[i].value);
//C1[i]=in[i];
C2[i]=C1[i];
}

/*BubbleSort*/
for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
        if(C1[j].value < C1[j-1].value){
            temp=C1[j];
            C1[j]=C1[j-1];
            C1[j-1]=temp;
        }
    }
}

/*Selectionsort*/
for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
        if(C2[j].value < C2[minj].value){
            minj=j;
        }
    }
            temp2=C2[i];
            C2[i]=C2[minj];
            C2[minj]=temp2;
}

/*Bubblesort*/
for(i=0;i<N-1;i++){
printf("%c%d ",C1[i].c,C1[i].value);
}

printf("%c%d\n",C1[N-1].c,C1[N-1].value);

printf("Stable\n");

/*Selectionsort*/
for(i=0;i<N-1;i++){
printf("%c%d ",C2[i].c,C2[i].value);
}

printf("%c%d\n",C2[N-1].c,C2[N-1].value);

for(i=0;i<N;i++){
    if(C1[i].c != C2[i].c && C1[i].value == C2[i].value){
        printf("Not stable\n");
       return 0;
    }
}
printf("Stable\n");

return 0;
}