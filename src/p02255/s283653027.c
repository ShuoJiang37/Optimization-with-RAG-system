#include <stdio.h>

#define N 100

int main(){

  int i, j, k, key, n, a[N];

  scanf("%d",&n);

  scanf("%d ",&a[0]);

  for(i=1;i<n;i++)
    scanf(" %d",&a[i]);

  for(i=1;i<n;i++){

      printf("%d",a[0]); 

  for(k=1;k<n;k++)
    printf(" %d",a[k]); 

   printf("\n");
    j = i-1;
    key = a[i];
    
    while(j>=0 && a[j]>key){
      
      a[j+1] = a[j];
      a[j] = key;
      j--;
    }
   
  }

    printf("%d",a[0]); 

  for(i=1;i<n;i++)
    printf(" %d",a[i]); 
  printf("\n");
  
  
  return 0;
}