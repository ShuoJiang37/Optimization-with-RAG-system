#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct card{
    char suit;
    int value;
};
typedef struct card card;

void print_array(card a[], int length)
{
    for(int i=0; i<length; i++){
        if(i==length-1)
            printf("%c%d\n", a[i].suit, a[i].value);
        else
            printf("%c%d ", a[i].suit, a[i].value);
    }
}

void swap(card *a, card *b)
{
    card temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(card a[], int length)
{
    //int swap_num = 0;
    for(int i=0; i<length; i++){
        //for(int j=0; j<length-i; j++){
        for(int j=length-1; j>=i+1; j--){
            if(a[j].value < a[j-1].value){
                swap(&a[j],&a[j-1]);
                //swap_num++;
            }
        }
    }
    //return swap_num;
}

void selection_sort(card a[], int length)
{
    //int swap_num = 0;
    for(int i=0; i<length; i++){
        int min_i = i;
        //int swap_flag = 0;
        for(int j=i; j<length; j++){
            if(a[j].value < a[min_i].value){
                min_i = j;
                //swap_flag = 1;
            }
        }
        swap(&a[i], &a[min_i]);
        //if(swap_flag == 1) swap_num++;
    }
    //return swap_num;
}

int main(){
    int data_length;
    card given_card[40];
    card given_card_copied[40];
    
    scanf("%d", &data_length);
    getchar();
    char get_input[200];
    fgets(get_input, sizeof(get_input), stdin);
    get_input[strlen(get_input) - 1] = '\0';
    
    int card_num = 0;
    for(int i=0; i<strlen(get_input); i++){
        if(isalpha(get_input[i])){
            given_card[card_num].suit = get_input[i];
            given_card[card_num].value = get_input[i+1] - '0';
            card_num++;
        }
        else;
    }

    for(int i=0; i<data_length; i++){
        given_card_copied[i].suit = given_card[i].suit; 
        given_card_copied[i].value = given_card[i].value;
    }

    bubble_sort(given_card_copied, data_length);
    print_array(given_card_copied, data_length);
    //printf("%d\n", swap);
    printf("Stable\n");
    
    for(int i=0; i<data_length; i++){
        given_card_copied[i].suit = given_card[i].suit; 
        given_card_copied[i].value = given_card[i].value;
    }

    bubble_sort(given_card, data_length);
    selection_sort(given_card_copied, data_length);
    print_array(given_card_copied, data_length);
    int is_stable = 1;
    for(int i=0; i<data_length; i++){
        if(given_card_copied[i].suit != given_card[i].suit){
            is_stable = 0;
        }
    }
    if(is_stable == 1) printf("Stable\n");
    else printf("Not stable\n");
}

