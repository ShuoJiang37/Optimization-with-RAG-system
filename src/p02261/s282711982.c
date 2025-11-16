#include <stdio.h>

struct Data{
    int Number;
    char Mark;
};

void BubbleSort(struct Data *data,int N){
    int i,j;
    struct Data temp;
    for(i = 0; i < N ; i++) {
        for (j = N - 1; j > i; --j) {
            if (data[j].Number < data[j - 1].Number) {
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
        }
    }
    for(i = 0; i < N-1; ++i){
        printf("%c%d ",data[i].Mark,data[i].Number);
    }
    printf("%c%d",data[N-1].Mark,data[N-1].Number);
    putchar('\n');
    printf("Stable\n");
}

void SelectionSort(struct Data *data,int N){
    int minj;
    int i,j;
    struct Data temp;
    for(i = 0; i < N ; i++){
        minj = i;
        for(j = i; j < N ; ++j) {
            if (data[minj].Number > data[j].Number) {
                minj = j;
            }
        }
        temp       = data[i];
        data[i]    = data[minj];
        data[minj] = temp;
    }

    for(i = 0; i < N-1; ++i){
        printf("%c%d ",data[i].Mark,data[i].Number);
    }
    printf("%c%d",data[N-1].Mark,data[N-1].Number);

    putchar('\n');
}

int main() {

    int i;
    struct Data data_B[110],data_S[110];
    int N;
    int count = 0;

    scanf("%d",&N);
    for (i = 0; i < N; ++i){
        scanf(" %c%d",&data_B[i].Mark,&data_B[i].Number);
        data_S[i].Number = data_B[i].Number;
        data_S[i].Mark = data_B[i].Mark;
    }

    BubbleSort(data_B,N);
    SelectionSort(data_S,N);
    for (i = 0; i < N; ++i){
        if(data_B[i].Mark != data_S[i].Mark){
            printf("Not stable\n");
            break;
        }
        count++;
    }
    if(count == N){
        printf("Stable\n");
    }


    return 0;
}
