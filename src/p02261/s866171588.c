#include<stdio.h>
 
struct AA{
  char s;
  char v;
};
 
 
 
int main(){

  struct AA a1[100], a2[100],f;
  int n, i,j,m,x=0;
  char z;
 
  scanf("%d%c", &n, &z);

  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &a1[i].s, &a1[i].v, &z);
  }
  for ( i = 0; i < n; i++ ){
    a2[i] = a1[i];
  }
  for(i = 0; i < n; i++){
    for(j = n-1; j >= i+1; j--){
      if(a1[j].v < a1[j-1].v){
    f = a1[j];      
    a1[j] = a1[j-1]; 
    a1[j-1] = f;
      }
    }
  }
   
  for(i = 0; i < n; i++){
    printf("%c%c",a1[i].s,a1[i].v);
    if(i< n-1){
      printf(" ");
    }
  } 
  printf("\n");
   
  printf("Stable\n");
   
  for(i = 0; i <= n-1; i++){
    m = i;
    for(j = i; j <= n-1; j++){
       
      if(a2[j].v < a2[m].v){
    m = j;
      }
    } 
     
    f = a2[i];      
    a2[i] = a2[m]; 
    a2[m] = f; 
  }
  for(i = 0; i < n; i++){
    if(a1[i].s != a2[i].s){
      x = 1;
    }
  }
   
  for(i = 0; i < n; i++){
    printf("%c%c",a2[i].s,a2[i].v);
    if(i<n-1){
      printf(" ");
    }
     
  }   
  printf("\n");
 
  if(x == 1){
    printf("Not stable\n");
  }
  else {
    printf("Stable\n");
  }
   
  return 0;
}