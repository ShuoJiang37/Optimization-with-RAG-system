#include<stdio.h>
#include<stdlib.h>
#define N 36
#define TRUE 1
#define FALSE 0

typedef struct {
    char suit;
    int value;
} Card;

int eq_cards(Card a, Card b){
    if(a.value == b.value && a.suit == b.suit) return TRUE;
    else return FALSE;
}

void swap(Card *a, Card *b){
    Card temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

Card* selectionsort(int n, Card *r){
    int i,j,minj;
    Card *res;
    res = (Card *)malloc(N * sizeof(Card));
    for(i=0;i<n;i++) res[i] = r[i];

    for(i=0;i<n;i++){
        minj = i;
        for(j=i;j<n;j++){
            if(res[j].value<res[minj].value) minj = j;
        }
        swap(&res[i], &res[minj]);
    }
    return res;
}

Card* bubblesort(int n, Card *r){
    int flag = 1;
    int i;
    Card *res;
    res = (Card *)malloc(N * sizeof(Card));
    for(i=0;i<n;i++) res[i] = r[i];

    while(flag){
        flag = 0;
        for(i=n-1;i>0;i--){
            if(res[i].value<res[i-1].value){
                swap(&res[i], &res[i-1]);
                flag = 1;
            }
        }
    }
    return res;
}

void print_array(Card *cs, int n){
    int i;
    for(i=0;i<n-1;i++) printf("%c%d ", cs[i].suit, cs[i].value);
    printf("%c%d\n", cs[n-1].suit, cs[n-1].value);

}

int is_stable(Card *b, Card *a, int n){
    int i, j, k, l;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            for(k=0;k<n;k++)
                for(l=k+1;l<n;l++)
                    if(b[i].value == b[j].value && eq_cards(b[i], a[l]) && eq_cards(b[j], a[k])) return FALSE;
    return TRUE;
}

int main(){
    int n;
    Card r[N];
    int i, j;
    Card *b_res, *s_res;

    scanf("%d", &n);
    for(i=0;i<n;i++) scanf(" %c%d", &r[i].suit, &r[i].value);

    b_res = bubblesort(n, r);
    s_res = selectionsort(n, r);
    
    print_array(b_res, n);
    if(is_stable(r, b_res, n)==TRUE) printf("Stable\n");
    else printf("Un stable\n");
    print_array(s_res, n);
    if(is_stable(r, s_res, n)==TRUE) printf("Stable\n");
    else printf("Not stable\n");
    
    free(b_res);
    free(s_res);
    return 0;
}