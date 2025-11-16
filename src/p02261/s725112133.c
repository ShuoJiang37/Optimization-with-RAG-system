#include <stdio.h>
#define N 36

typedef struct{
  char c;
  int num;
}Data;

void bubbleSort(Data*, int);
void selectionSort(Data*, int);
char* isStable(Data*, Data*, int);
  
int main(){

  Data card[N], data[N];
  int n, i;
  char a;

  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    scanf(" %c%d",&card[i].c, &card[i].num);
   }

  for(i=0; i<n; i++){
    data[i]=card[i];
  }

  bubbleSort(card, n);
  
  for(i=0; i<n-1; i++){
    printf("%c%d ", card[i].c, card[i].num);
  } printf("%c%d\n", card[n-1].c, card[i].num);

  
  printf("%s\n", isStable(card, card, n));
  

  
  selectionSort(data, n);

  for(i=0; i<n-1; i++){
    printf("%c%d ", data[i].c, data[i].num);
  } printf("%c%d\n", data[n-1].c, data[i].num);

  printf("%s\n", isStable(card, data, n));
  

 
  return 0;
}

void bubbleSort(Data* card, int n){

  int i, j;
  Data temp;
  
  for(i=0; i<n-1; i++){

    for(j=n-1; j>i; j--){
      
      if(card[j].num<card[j-1].num){
	temp =card[j];
	card[j]=card[j-1];
	card[j-1]=temp;
      }
    }
  }  
}

void selectionSort(Data* data, int n){

  int i, j, min;
  Data temp;

  for(i=0; i<n-1; i++){

    min= i;
    for(j=i+1; j<n; j++){
      if(data[j].num<data[min].num){
	min=j;
      }
    }
    temp=data[i];
    data[i]=data[min];
    data[min]=temp;

  }
}

char* isStable(Data* bubble, Data* comp, int n){

  int i;
  char *result;

  for(i=0; i<n; i++){
    if(bubble[i].c!= comp[i].c || bubble[i].num!= comp[i].num){
      result = "Not stable";
      return result;
    }
  }
  result = "Stable";
  return result;  
}

