#include <stdio.h>
#define N 36

typedef struct{
  char kind;
  int number;
}Trump;
  
int main(void){
  int n, i, j, s, min;
  Trump x[N], y[N], t;
  
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
    scanf("%c%c%d",&x[i].kind, 
                 &x[i].kind,
                 &x[i].number);
    y[i] = x[i];
  }
    
  for(i = 0 ; i < n ; i++){
    for(j = n-1 ; j >= i+1 ; j--){
      if(x[j].number < x[j-1].number){
        t = x[j];
        x[j] = x[j-1];
        x[j-1] = t;
      }
    }
  }    
      
    
  for(i = 0 ; i < n ; i++){
    min = i;
    for(j = i ; j < n ;j++)
      if(y[j].number < y[min].number)
        min = j;
      t = y[i];
      y[i] = y[min];
      y[min] = t;     
  }
  
  
  
  
  for( i = 0; i < n-1; i++){
    printf("%c%d ", x[i].kind, x[i].number);
  }
  printf("%c%d\n", x[n-1].kind, x[n-1].number);
  printf("Stable\n");
   
  for( i = 0; i < n-1; i++){
    printf("%c%d ", y[i].kind, y[i].number);
  }
  printf("%c%d\n", y[n-1].kind, y[n-1].number);
  
  s = 1;
  
  for(i = 0; i < n; i++)
    if(x[i].kind != y[i].kind)
      s = 0;
  
  if(s == 1)
    printf("Stable\n");
  else
    printf("Not stable\n");
   
  return 0;
}