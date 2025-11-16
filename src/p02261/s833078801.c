#include<stdio.h>

typedef struct{
  char mark;
  int value;
}CARD;

int main() {
  
  int i, j, n, minj, flag = 0;
  CARD a[100], b[100], temp;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf(" %c%d", &a[i].mark, &a[i].value);
    b[i] = a[i];
  }
  
  //Bubble
  for(i = 0; i < n; i++){
    for(j = n - 1; j != i; j--){
      if(a[j].value < a[j - 1].value){
        temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
      }
    }
  }
  for(i = 0; i < n; i++){
    printf("%c%d", a[i].mark, a[i].value);
    if(i < n-1) printf(" ");
    else printf("\n");
  }
  printf("Stable\n");

  //Select
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(b[j].value < b[minj].value) {
	minj = j;
      }
    }
    temp = b[i];
    b[i] = b[minj];
    b[minj] = temp;
  }
  for(i = 0; i < n; i++){
    if(a[i].mark != b[i].mark) flag = 1;
  }
  for(i = 0; i < n; i++){
    printf("%c%d", b[i].mark, b[i].value);
    if(i < n-1) printf(" ");
    else printf("\n");
  }
  if(flag == 1) printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}

