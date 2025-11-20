#include <stdio.h>

typedef struct{
    char design;
    int value;
}card;

void BubbleSort(card *,int);
void SelectionSort(card *,int);

int main() {
  int i,n,flag=0;
    card C[36],A[36];
    
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
      scanf(" %c%d",&C[i].design,&C[i].value);
      A[i] = C[i];
    }
    
    BubbleSort(C,n);
    for(i = 0; i < n; i++) {
      printf("%c%d",C[i].design,C[i].value);
      if(i != n-1) printf(" ");
    }
    printf("\n");
    printf("Stable\n");
    
    SelectionSort(A,n);
    for(i = 0; i < n; i++) {
      printf("%c%d",A[i].design,A[i].value);
      if(i != n-1) printf(" ");
    }
    printf("\n");

    for(i = 0; i < n; i++) {
      if(C[i].design != A[i].design) flag = 1;
    }
    
    if(flag == 1) printf("Not stable\n");
    else printf("Stable\n");

    return 0;
}

void BubbleSort(card *C,int N)
{
  int i,j;
  card temp;
    for(i = 0; i <= N-1; i++) {
        for(j = N-1; j >= i+1; j--) {
            if(C[j].value < C[j-1].value) {
                temp = C[j];
                C[j] = C[j-1];
                C[j-1] = temp;
            }
        }
    }
}

void SelectionSort(card *C,int N)
{
  int i,j,minj;
  card temp;
    for(i = 0; i <= N-1; i++) {
        minj = i;
        for(j = i; j <= N-1; j++) {
            if(C[j].value < C[minj].value) {
                minj = j;
            }
        }
	temp = C[i];
	C[i] = C[minj];
	C[minj] = temp;
    }
}

