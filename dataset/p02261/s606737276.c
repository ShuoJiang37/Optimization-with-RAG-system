#include <stdio.h>
 
typedef struct{
  char c;
  int value;
}card;
 
int main(){
  char space;
  int i, j, n, min, flag;
  card a[36], b[36], x;

  scanf("%d\n",&n);
  for(i = 0; i < n; i++){
    scanf("%c%d%c", &a[i].c, &a[i].value, &space);
    b[i] = a[i]; 
  }
   
  for(j = 0; j < n; j++){
    flag = 0;   
    for(i= n-1; i > j; i--){
      if(a[i].value < a[i-1].value){
        x = a[i];
        a[i] = a[i-1];
        a[i-1] = x;
        flag = 1;
      }
    }
    if(flag == 0) break;
  }
 
  for(j = 0; j < n; j++){
    min = j;
    for(i = j; i < n; i++){
      if(b[i].value < b[min].value)
        min = i; 
    }   
    if(min != j){
      x = b[j];
      b[j] = b[min];
      b[min] = x;
    }
  }
 
  for(i = 0; i < n-1; i++){
    printf("%c%d ", a[i].c, a[i].value);
  }
  printf("%c%d\n", a[n-1].c, a[n-1].value);
  printf("Stable\n");

  for(i = 0; i < n-1; i++){
    printf("%c%d ", b[i].c, b[i].value);
    if(a[i].c != b[i].c){
      flag = 2;
    }
  }

  printf("%c%d\n", b[n-1].c, b[n-1].value);

  if(flag == 2){
    printf("Not stable\n");
  }
  else printf("Stable\n");
 
  return 0;
}