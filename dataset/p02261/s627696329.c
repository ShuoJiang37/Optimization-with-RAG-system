#include <stdio.h>
#define TRUE 1
#define FALSE 0

int N;

typedef struct{
    char mark;
    int value;
} trump;

void swap(trump *a, trump *b){
    trump tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubblleSort(trump C[]){
    int i,j;

    for(i=0; i<N-1; i++){
        for(j=N-1; j>=i+1; j--){
            if(C[j].value < C[j-1].value) 
                swap(&C[j],&C[j-1]);
        }
    }
}

void SelectionSort(trump C[]){
    int i,j;
    int minj;

    for(i=0; i<N; i++){
        minj = i;
        for(j=i; j<N; j++){
            if(C[j].value < C[minj].value)
                minj = j;
        }

        swap(&C[i],&C[minj]);
    }
}

void Allprint(trump C[]){
    int i;

    for(i=0; i<N; i++){
        if(i != 0) printf(" ");
        printf("%c%d",C[i].mark,C[i].value);
    }
    printf("\n");
}

int check_stable(trump in[],trump out[]){
    int i,j,k,l;
    for(i=0; i<N; i++){
        for(j=i+1; j<N; j++){
            for(k=0; k<N; k++){
                for(l=k+1; l<N; l++){
                    if(in[i].value == in[j].value
                        && in[i].value == out[l].value 
                            && in[i].mark == out[l].mark 
                                &&in[j].value == out[k].value
                                     &&in[j].mark == out[k].mark)
                                        return FALSE;
                }
            }
        }
    }

    return TRUE;
}


int main(){
    int i;
    trump in[36];
    trump bubble[36];
    trump selection[36];

    scanf("%d",&N);
    for(i=0; i<N; i++){ 
        scanf(" %c%d",&in[i].mark,&in[i].value);
    }
    for(i=0; i<N; i++){
        bubble[i] = in[i];
        selection[i] = in[i];
    }

    BubblleSort(bubble);
    Allprint(bubble);
    if( check_stable(in,bubble) ) printf("Stable\n");
    else printf("Not stable\n");

    SelectionSort(selection);
    Allprint(selection);
    if(check_stable(in,selection)) printf("Stable\n");
    else printf("Not stable\n");

    return 0;

}
