#include<stdio.h>
struct card {
   char mark;
   char num; 
};
void bubble_sort(struct card[], int);
void selection_sort(struct card[], int);
void print_array(struct card[], int);
int is_stable(struct card[], struct card[], int);
void strCastCard(struct card *, char[]);
int main(void){
    struct card cards_bubble[36];
    struct card cards_select[36];
    int i, N, j;
    char s[3];

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%s",s);
        strCastCard(&cards_bubble[i], s);
    }
    for(i = 0; i < N; i++) cards_select[i] = cards_bubble[i];
    
    bubble_sort(cards_bubble, N);
    selection_sort(cards_select, N);

    print_array(cards_bubble, N);
    printf("Stable\n");
    print_array(cards_select, N);
    if(is_stable(cards_bubble, cards_select, N)){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }

    return 0;
}
void bubble_sort(struct card data[], int N){
    int i, j;
    struct card t;
    for(i = 0; i < N; i++){
        for(j = N - 1; j >= i; j--){
            if(data[j].num < data[j-1].num){
                t = data[j];
                data[j] = data[j-1];
                data[j-1] = t;
            }
        }
    }
}
void selection_sort(struct card A[], int N){
    int i, j, minj;
    struct card t;
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j].num < A[minj].num){
                minj = j;
            }
        }
        t = A[i];
        A[i] = A[minj];
        A[minj] = t;
    }
}
void print_array(struct card a[], int n){
    int i = 0;
    // printf("%c%d", a[0].mark, a[0].num);
    while(i < n){
        if(i > 0) printf(" ");
        printf("%c%d", a[i].mark, a[i].num);
        i++;
    }
    printf("\n");
    return;
}
int is_stable(struct card src[], struct card dst[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(src[i].mark != dst[i].mark || src[i].num != dst[i].num) return 0;
    }
    return 1;
}
void strCastCard(struct card *t, char str[]){
    t->mark = str[0];
    t->num = str[1] - '0';
    return;
}

