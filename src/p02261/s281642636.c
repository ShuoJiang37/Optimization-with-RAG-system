#include<stdio.h>

typedef struct {
    char suit; // One of S, H, C, D
    char value;  // One of 1, 2, ... 9 (not int, but char)
} Card;


void show_cards(Card A[], int N){
    int i;

    for(i = 0; i < N; i++){
        
        printf("%c", A[i].suit);
        printf("%c", A[i].value);
        if(i < N - 1){
            putchar(' ');
        }
        else{
            putchar('\n');
        }
    }
}

void exchange(Card A[], int i, int j){
    Card tmp;
    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void bubble_sort(Card A[], int N){
    int i, j;
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j > i; j--){
            if(A[j].value < A[j-1].value){
                exchange(A, j, j - 1);
            }
        }
    }
}

void selection_sort(Card A[], int N){
    int i, j;
    int idx_min;
    for(i = 0; i < N; i++){
        idx_min = i;
        for(j = i; j < N; j++){
            if(A[idx_min].value > A[j].value){
                idx_min = j;
            }
        }
        if(i != idx_min){
            exchange(A, i, idx_min);
        }
    }
}

void print_stable(int flag){
    if(flag){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }
}

int main(void){
    int N;
    Card C1[36];
    Card C2[36];
    char tmpstr[3];
    int i;
    int flag; /* whether C1 and C2 after sorting coincide with each other */
    
    /* Set the length of Cards array */
    scanf("%d", &N);
    
    /* Set C1 */
    for(i = 0; i < N; i++){
        scanf("%s", tmpstr);
        C1[i].suit = tmpstr[0];
        C1[i].value = tmpstr[1];
    }
    
    /* Copy C1 to C2 (this is a deep copy, and hence modifying C1 does not affect C2, and vice versa.) */
    for(i = 0; i < N; i++){
        C2[i] = C1[i];
    }

    // Perform sorting
    bubble_sort(C1, N);
    selection_sort(C2, N);

    // Judge whether the result of selection sort is stable or not 
    // by comparing it with that of bubble_sort, whose output is always stable.
    flag = 1;
    for(i = 0; i < N; i++){
        if( ( C1[i].value != C2[i].value) || ( C1[i].suit != C2[i].suit ) ){
            flag = 0;
            break;
        }
    }
    
    show_cards(C1, N);
    print_stable(1);
    show_cards(C2, N);
    print_stable(flag);
    
    return 0;
}

