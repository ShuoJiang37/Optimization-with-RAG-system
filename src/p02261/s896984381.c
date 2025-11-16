#include <stdio.h>
#include <stdlib.h>

typedef struct {
        char mark;
        int num;
} Card;

void Babble_Sort(int, Card *);
void Selection_Sort(int, Card *);
int checkStable(int, Card *);

Card *array;

int main(){
        int n, i;
        Card *bs_array, *ss_array;

        scanf("%d", &n);

        array = (Card *)malloc(n * sizeof(Card));
        bs_array = (Card *)malloc(n * sizeof(Card));
        ss_array = (Card *)malloc(n * sizeof(Card));

        for(i = 0 ; i < n ; i++){
                scanf(" %c", &array[i].mark);
                scanf("%d", &array[i].num);
                bs_array[i] = array[i];
                ss_array[i] = array[i];
        }

        Babble_Sort(n, bs_array);
        Selection_Sort(n, ss_array);

        for(i = 0 ; i < n ; i++){
                printf("%c", bs_array[i].mark);
                printf("%d", bs_array[i].num);
                if(i + 1 != n)printf(" ");
        }
        printf("\n");


        if(checkStable(n, bs_array) == 0)printf("Stable\n");
        else printf("Not stable\n");
        
        for(i = 0 ; i < n ; i++){
                printf("%c", ss_array[i].mark);
                printf("%d", ss_array[i].num);
                if(i + 1 != n)printf(" ");
        }
        printf("\n");

        if(checkStable(n, ss_array) == 0)printf("Stable\n");
        else printf("Not stable\n");

        return 0;
}

void Babble_Sort(int n, Card *b_array){
        int i, j;
        Card buffer;

        for(j = 0 ; j < n ; j++){
                for(i = n - 1 ; i > j ; i--){
                        if(b_array[i].num < b_array[i - 1].num){
                                buffer = b_array[i];
                                b_array[i] = b_array[i - 1];
                                b_array[i - 1] = buffer;
                        }
                }
        }
}

void Selection_Sort(int n, Card *s_array){
        int i, j, minj; 
        Card buffer;

        for(i = 0 ; i < n ; i++){
                minj = i;
                for(j = i ; j < n ; j++){
                        if(s_array[j].num < s_array[minj].num){
                                minj = j;
                        }
                }
                if(minj != i){
                        buffer = s_array[minj];
                        s_array[minj] = s_array[i];
                        s_array[i] = buffer;
                }
        }
}

int checkStable(int n, Card *c_array){
        int i, j, k, num_of_same;
        char mark_order[4];

        for(i = 0 ; i < n ; i++){
                k = 0;
                if(c_array[i].num == c_array[i + 1].num){
                        if(c_array[i].num  == c_array[i + 2].num ){
                                if(c_array[i].num  == c_array[i + 3].num ){
                                        num_of_same = 4;
                                }else{
                                        num_of_same = 3;
                                }
                        }else{
                                num_of_same = 2;
                        }

                        for(j = 0 ; j < n ; j++){
                                if(array[j].num == c_array[i].num){
                                        mark_order[k] = array[j].mark;
                                        k++;
                                }
                        }

                        for(j = 0 ; j < num_of_same ; j++){
                                if(c_array[i + j].mark == mark_order[j])continue;
                                else return 1;
                        }

                        i += num_of_same - 1;
                }else{
                        continue;
                }

        }

        return 0;
}

