#include <stdio.h>
#include <stdlib.h>

#define N 36

typedef struct node{
  char value;
  int num;
}Node;

int isStable(Node *, Node *, int);
void BubbleSort(Node *, int);
void SelectionSort(Node *, int);

Node C[N], C1[N];
char c[3];
int n;

int main()
{

  int i;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%s", c);

    C[i].value = c[0];
    C[i].num = atoi(&c[1]);
    C1[i] = C[i];

  }

  for(i=0; i<n-1; i++){
    BubbleSort(C, n);
    printf("%c%d ", C[i].value, C[i].num);
  }
 
  printf("%c%d\n", C[i].value, C[i].num);
  printf("Stable\n");

  for(i=0; i<n-1; i++){
    SelectionSort(C1, n);
    printf("%c%d ", C1[i].value, C1[i].num);
  }

  printf("%c%d\n", C1[i].value, C1[i].num);

  if(isStable(C, C1, n) == 0) printf("Not stable\n");
  else printf("Stable\n");
 
  return 0;
}


int isStable(Node *C, Node *C1, int n){

  int i;

  for(i=0; i<n; i++){
    if(C[i].value != C1[i].value) return 0;
  }

  return 1;

}

void BubbleSort(Node *C, int n){

  int i, j;
  Node tmp;

  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(C[j].num < C[j-1].num){
	tmp = C[j];
	C[j] = C[j-1];
	C[j-1] = tmp;
      }
    }
  }
}

void SelectionSort(Node *C1, int n){

  int i, j, minj;
  Node tmp;

   for(i=0; i<=n-1; i++){
     minj = i;
     for(j=i; j<=n-1; j++){
       if(C1[j].num < C1[minj].num){
	 minj = j;
       }
     }     
     tmp = C1[i];
     C1[i] = C1[minj];
     C1[minj] = tmp;
   }
}