#include<stdio.h>

typedef struct Card {
  char suit;
  int value;
} card;

void print(card A[],int n);
void BubbleSort(card C[],int n);
void SelectionSort(card C[],int n);
int isStable(card in[],card out[],int n);


int main(void)
{
  int n,i;
  card c1[100],c2[100];

  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf(" %c %d",&c1[i].suit,&c1[i].value);
  }

  for(i = 0;i < n;i++){
    c2[i] = c1[i];
  }

  BubbleSort(c1,n);
  
  SelectionSort(c2,n);

  print(c1,n);
  puts("Stable");
  
  print(c2,n);
  
  if(isStable(c1,c2,n) == 1){
    puts("Stable");
  } else {
    puts("Not stable");
  }

  return 0;
}






void print(card A[],int n){
  int i;
  
  for(i = 0;i < n;i++){
    if(0 < i){
      printf(" ");
    }
    
    printf("%c%d",A[i].suit,A[i].value);
  }
  
  puts("");
}



void BubbleSort(card C[], int n){
  int i,j;
  card temp;
  
  for(i = 0;i < n;i++){
    for(j = n-1;j >= i+1;j--){
      if(C[j].value < C[j-1].value){
	temp =
	  C[j-1];
	C[j-1] = C[j];
	C[j] = temp;
      }
    }
  }
  
}



void SelectionSort(card C[],int n){
  int i,j;
  card temp;
  int minj;
  
  for(i = 0;i < n;i++){
    minj = i;
    
    for(j = i ;j < n;j++){
      if(C[j].value < C[minj].value){
	minj = j;
      }
    }
    
    temp = C[i];
    C[i] = C[minj];
    C[minj] = temp;
  }
  
}



int isStable(card in[],card out[],int n){  
  int i;
 
  for(i = 0;i < n;i++){
    if(in[i].suit != out[i].suit){
      return 0;
    }
  }
  
  return 1;
}

