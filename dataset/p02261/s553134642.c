#include<stdio.h>
#include<string.h>

typedef struct{
    char a[1];
    int n;
}card;

int main(){
    int i, j, k;
    int N;
    int nmin, ans=0;
    card C1[200], C2[200];
    card tmp;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%1s%d", &C1[i].a, &C1[i].n);
        C2[i] = C1[i];
        //printf("%1s%d ", C1[i].a, C1[i].n);
    }

    for(i=0; i<N; i++){
        for(j=N-1; j>i; j--){
            if(C1[j].n<C1[j-1].n){
                tmp = C1[j];
                C1[j] = C1[j-1];
                C1[j-1] = tmp;
            }
        }
    }

    for(i=0; i<N-1; i++){
        nmin = i;
        for(j=i+1; j<N; j++){
            if(C2[j].n<C2[nmin].n){
                nmin = j;
            }
        }
        if(i!=nmin){
            tmp = C2[i];
            C2[i] = C2[nmin];
            C2[nmin] = tmp;
        }
    }

    for(i=0; i<N; i++){
        if(i>0){
            printf(" ");
        }
        printf("%s%d", C1[i].a, C1[i].n);
    }
    printf("\nStable\n");

    for(i=0; i<N; i++){
        if(i>0){
            printf(" ");
        }
        printf("%s%d", C2[i].a, C2[i].n);
    }
    printf("\n");

    for(i=0; i<N; i++){
        //printf("%s%s\n", C1[i].a, C2[i].a);
        if(strcmp(C1[i].a, C2[i].a)){
            ans = 1;
        }
    }
    if(ans == 0){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

    return 0;
}
