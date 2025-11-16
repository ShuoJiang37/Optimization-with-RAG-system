#include <stdio.h>
 
#define M 36
 
typedef struct{
  char m;
  int v;
}Trump;
 
int main(){
   
  int n, i, j, f, min;
  Trump x[M], y[M], t ;
 
 
  scanf("%d",&n);
 
 
  for(i = 0 ; i < n ; i++){
    //scanf("%c%d",&x[i].m, &x[i].v);
    scanf("%c%c%d",&x[i].m, &x[i].m, &x[i].v);
    y[i] = x[i];
  }
   
 
  
 
  for(i = 0 ; i < n ; i++)
    for(j = n-1 ; j >= i+1 ; j--)
      if(x[j].v < x[j-1].v){
    t = x[j];
    x[j] = x[j-1];
    x[j-1] = t;
      }
   
 
 
  for(i = 0 ; i < n ; i++){
    min = i;
    for(j = i ; j < n ;j++)
      if(y[j].v < y[min].v)
    min = j;
    t = y[i];
    y[i] = y[min];
    y[min] = t;     
  }
 
 
 
 
  for( i = 0 ; i < n-1 ; i++){
    printf("%c%d ",x[i].m, x[i].v);
  }
  printf("%c%d\n",x[n-1].m, x[n-1].v);
  printf("Stable\n");
  
  for( i = 0 ; i < n-1 ; i++){
    printf("%c%d ",y[i].m, y[i].v);
  }
  printf("%c%d\n",y[n-1].m, y[n-1].v);
 
 
  f = 1;
 
 
  for(i = 0 ; i < n ; i++)
    if(x[i].m != y[i].m)
      f = 0;
 
 
  if(f == 1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  
 
  return 0;
}