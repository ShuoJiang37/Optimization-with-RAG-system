#include <stdio.h>
#include <stdbool.h>
#define MAX 36

struct Card{
    char suit;
    int value;
};

struct Card a[MAX],b[MAX];
int N;

void BubbleSort();
void SelectionSort();
int isStable();

int main(){
int i;

scanf("%d",&N);

for(i=0;i<N;i++){
    scanf(" %c%d ",&a[i].suit,&a[i].value);
    b[i].suit=a[i].suit;
    b[i].value=a[i].value;
}

BubbleSort();

for(i=0;i<N;i++){
    if(i==N-1) printf("%c%d\n",a[i].suit,a[i].value);
    else printf("%c%d ",a[i].suit,a[i].value);
}
printf("Stable\n");

SelectionSort();

for(i=0;i<N;i++){
    if(i==N-1) printf("%c%d\n",b[i].suit,b[i].value);
    else printf("%c%d ",b[i].suit,b[i].value);
}
if(isStable()) printf("Stable\n");
else printf("Not stable\n");

return 0;
}


void BubbleSort(){
int i,j;
struct Card tmp;

for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
        if(a[j].value<a[j-1].value){
            tmp=a[j];
            a[j]=a[j-1];
            a[j-1]=tmp;
            }
        }
    }
}

void SelectionSort(){
    int i,minj,j;
    struct Card tmp;

    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(b[j].value<b[minj].value) minj=j;
        }
        tmp=b[i];
        b[i]=b[minj];
        b[minj]=tmp;
    }
}

int isStable(){
    int i;

    for(i=0;i<N;i++){
        if(a[i].suit!=b[i].suit) return 0;
    }
    return 1;
}

