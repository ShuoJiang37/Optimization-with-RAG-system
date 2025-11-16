#include <stdio.h>

#define N 36

typedef struct {
    char sign;
    int number;
}Card;

typedef struct {
    Card card[N];
}Card_Array;

void comp_memer(Card_Array, Card_Array, int);
void print_array(Card_Array, int);
Card_Array Bubble(Card_Array, int);
Card_Array Selection(Card_Array, int);

int main() {
    int i, num;
    Card_Array data[3];
    

    scanf("%d", &num);
    for(i=0; i<num; ++i) 
        scanf(" %c%d", &data[0].card[i].sign, &data[0].card[i].number);
    
    data[1] = Bubble(data[0], num);
    printf("Stable\n");

    data[2] = Selection(data[0], num);
    comp_memer(data[1], data[2], num);

    return 0;
}

Card_Array Bubble(Card_Array p, int num) {
    int i,j;
    Card tmp;
    Card_Array ret_data;

    for(i=0; i<num; ++i){
        for(j=num-1; j>=i+1; --j){
            if(p.card[j].number < p.card[j-1].number) {
                tmp = p.card[j];
                p.card[j] = p.card[j-1];
                p.card[j-1] = tmp; 
            }
        }
        ret_data.card[i] = p.card[i];
    }
    print_array(p, num);

    return ret_data;
}

Card_Array Selection(Card_Array p, int num) {
    int i, j, minj = 0;
    Card tmp;
    Card_Array ret_data;
    
    for(i=0; i < num; ++i){
        minj = i;
        for(j=i; j < num; ++j){
            if(p.card[j].number < p.card[minj].number)
                minj = j;
        }
        tmp = p.card[i];
        p.card[i] = p.card[minj];
        p.card[minj] = tmp;
        ret_data.card[i] = p.card[i];
    }
    print_array(p, num);

    return ret_data;
}

void print_array(Card_Array data, int num) {
    int i;
    for(i=0; i<num; ++i) {
        if(i) 
            printf(" ");

        printf("%c%d", data.card[i].sign, data.card[i].number);
    }
    printf("\n");
}

void comp_memer(Card_Array data1, Card_Array data2, int num){
    int i;

    for(i=0; i<num; ++i){
        if(data1.card[i].sign != data2.card[i].sign){
            printf("Not stable\n"); 
            return ;
        }
    }
    printf("Stable\n");
}
