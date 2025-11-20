#include<stdio.h>
typedef struct{char suit, value;}card;
void swap(card *a,card *b){
    card t=*a;
    *a = *b;
    *b = t;
    return;
}
void bubble(int n, card a[]){
    int i, j, flag;
    flag=1;
    for(i=0;flag;i++){
        flag=0;
        for(j=n-1;j>=i+1;j--){
            if(a[j].value < a[j-1].value){
                swap(&a[j], &a[j-1]);
                flag=1;
            }
        }
    }
    return;
}
void selectionSort(card a[], int N){
    int i, j, minj;
    card t;
    for(i = 0; i < N-1; i++){
        minj = i;
        for(j=i;j<N;j++){
            if(a[j].value < a[minj].value){
                minj=j;
            }
        }
        t = a[i];
        a[i] = a[minj];
        a[minj] = t;
    }
    return;
}
void str2Card(card *t,char str[]) {
    t->suit  = str[0];
    t->value = str[1] - '0';
}
void print(card A[], int N) {
  int i;
  for(i=0; i<N; i++) {
    if(i>0) printf(" ");
      printf("%c%d",A[i].suit,A[i].value);
  }
  printf("\n");
}
int stable(card a[], card b[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(a[i].suit != b[i].suit){
            return 0;
        }
    }
    return 1;
}
int main(void){
    card c1[100], c2[100];
    int i, n;
    char str[3];
    scanf("%d", &n);
    for(i= 0; i < n; i++){
        scanf("%s", &str);
        str2Card(&c1[i], str);
    }
    for(i = 0;i < n; i++){
        c2[i] = c1[i];
            }
    bubble(n, c1);
    selectionSort(c2, n);
    print(c1, n);
    printf("Stable\n");
    print(c2, n);
    if(stable(c1, c2, n)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
    return 0;
}
