#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ppp(int arr[], int N, char ccc[]){
    int counter, j, temp;
    char c;
    for(counter=0;counter<N;counter++){
        for(j=N-1; j>counter; j--){
            if (arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                c = ccc[j];
                ccc[j]=ccc[j-1];
                ccc[j-1]=c;
            }
        }
    }
    for(j=0; j<N; j++){
        printf("%c%d",ccc[j],arr[j]);
        if(j != N-1) printf(" ");
    }
    printf("\nStable\n");
    return 1;
}
int xxx(int arr[], int N, char ccc[]){
    int counter, j, temp, aaa;
    char c;
    for(counter=0;counter<N;counter++){
        temp = counter;
        for(j=counter;j<N;j++){
            if (arr[j]<arr[temp]){
               temp = j;
            }
        }
            aaa = arr[counter];
            arr[counter] = arr[temp];
            arr[temp] = aaa;
            c = ccc[counter];
            ccc[counter] = ccc[temp];
            ccc[temp] = c;
    }
   for(j=0; j<N; j++){
        printf("%c%d",ccc[j],arr[j]);
        if(j != N-1) printf(" ");
    }
    return 1;
}

int main(int argc, char** argv) {
    int N = 0;
    scanf("%d",&N);
    int arr[N];
    char list[N];
    int arr_b[N];
    char list_b[N];
    int counter, j, temp, aaa;
    for(counter=0;counter<N;counter++){
        scanf(" %c %d", &list[counter], &arr[counter]);
        list_b[counter] = list[counter];
        arr_b[counter] = arr[counter];
    }

    int ppp1 = ppp(arr_b, N, list_b);
    /*for(int i=0; i<N; i++){
        arr_b[i] =  arr[i];
        list_b[i] = list[i];
    }*/
    int ppp2 = xxx(arr, N, list);

    if ((strncmp(list_b,list,N)==0)){
    printf("\nStable\n");
    }else{
    printf("\nNot stable\n");
    }
    return 0;
}

