#include <stdio.h>
#define N 102

struct inf{
    char form;
    int num;
};

struct inf ori[N];

void bubblesort(struct inf *a,int n){
    struct inf tmp;
    int i,j,side;
    side = 0;
    for(i = 0; i < n-1;i++){
        for (j = n-1; j > side; j--) {
            if (a[j].num < a[j-1].num) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
        side++;
    }
}

void selectionsort(struct inf *b,int n){
    struct inf tmp;
    int i,j,minj;

    for (i = 0; i < n-1; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            if (b[j].num < b[minj].num) {
                minj = j;
            }
        }
        tmp = b[i];
        b[i] = b[minj];
        b[minj] = tmp;
    }
}

int judge(struct inf *x,struct inf *y,int n){
    int i;

    for (i = 0; i < n; i++) {
        if(x[i].form != y[i].form){
            return 0;
        }
    }
    return 1;
}

void print(struct inf *x,struct inf *y, int n){
    int i,hantei;
    for (i = 0; i < n; i++) {
        if(i == 0){
            printf("%c%d",x[i].form,x[i].num);
        }else{
            printf(" %c%d",x[i].form,x[i].num);
        }
    }
    printf("\nStable\n");

    for (i = 0; i < n; i++) {
        if(i == 0){
            printf("%c%d",y[i].form,y[i].num);
        }else{
            printf(" %c%d",y[i].form,y[i].num);
        }
    }
    hantei = judge(x,y,n);
    if(hantei == 1){
        printf("\nStable\n");
    }else{
        printf("\nNot stable\n");
    }

}

int main(int argc, char const *argv[]) {
    struct inf a[N],b[N];
    int n,i;

    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf(" %c%d",&ori[i].form,&ori[i].num);
        a[i] = b[i] = ori[i];
    }
    bubblesort(a,n);
    selectionsort(b,n);
    print(a,b,n);


    return 0;
}

