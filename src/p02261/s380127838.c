#include<stdio.h>

typedef struct{
  char egara;
  int value;
}C;

void BubbleSort(C[36], int);
void SelectionSort(C[36], int);
int isStable(C[36],C[36],int);

int main(){
  int n,i;
  C c1[36],c2[36];

  scanf("%d",&n);

  for(i = 0; i < n; i++) scanf(" %c%d",&c1[i].egara,&c1[i].value);

  for(i = 0; i <n; i++) c2[i] = c1[i];

  BubbleSort(c1,n);
  SelectionSort(c2,n);

   for(i = 0; i < n; i++){
    if(i == n-1) printf("%c%d\n",c1[i].egara,c1[i].value);
    else printf("%c%d ",c1[i].egara, c1[i].value);
  }
   printf("Stable\n");

    for(i = 0; i < n; i++){
    if(i == n-1) printf("%c%d\n",c2[i].egara,c2[i].value);
    else printf("%c%d ",c2[i].egara, c2[i].value);
  }

    if(isStable(c1, c2, n)) printf("Stable\n");
    else printf("Not stable\n");
   
  return 0;
}

void BubbleSort(C c[36], int n){
  int i,j;
  C temp;

  for(i = 0; i <= n-1; i++){
    for(j = n-1; j >= i+1; j--){
      if(c[j].value < c[j-1].value){
	temp = c[j];
	c[j] = c[j-1];
	c[j-1] = temp;
      } 
    }
  }
}

void SelectionSort(C c[36], int n){
  int i,j,minj;
  C temp;
  
  for(i = 0; i <= n-1; i++){
    minj = i;
    for(j = i; j <= n-1; j++){
      if(c[j].value < c[minj].value) minj = j;
    }
    temp = c[i];
    c[i] = c[minj];
    c[minj] = temp;
  }
}

int isStable(C c1[36], C c2[36], int n){
  int i;

  for(i = 0; i < n; i++){
    if(c1[i].egara != c2[i].egara) return 0;
  }

  return 1;
}

