#include <stdio.h>

#define Max 36

typedef struct{
  char m;
  int v;
}Trump;

int main(){
  
  int n, i, j, flag, min;
  Trump x[Max], y[Max], temp ;


  scanf("%d",&n);


  for(i = 0 ; i < n ; i++){
    //scanf("%c%d",&x[i].m, &x[i].v);
    scanf("%c%c%d",&x[i].m, &x[i].m, &x[i].v);
    y[i] = x[i];
  }
  

 

  for(i = 0 ; i < n ; i++)
    for(j = n-1 ; j >= i+1 ; j--)
      if(x[j].v < x[j-1].v){
	temp = x[j];
	x[j] = x[j-1];
	x[j-1] = temp;
      }
  


  for(i = 0 ; i < n ; i++){
    min = i;
    for(j = i ; j < n ;j++)
      if(y[j].v < y[min].v)
	min = j;
    temp = y[i];
    y[i] = y[min];
    y[min] = temp;     
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


  flag = 1;


  for(i = 0 ; i < n ; i++)
    if(x[i].m != y[i].m)
      flag = 0;


  if(flag == 1)
    printf("Stable\n");
  else 
    printf("Not stable\n");
 

  return 0;
}