#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubblesort(char a[][3],int c[],int n){
  int i=0,j,s = 0,flag = 1,k,m;
  char x[3];
  while(flag != 0){
    flag = 0;
    for(j = n-1;j > i;j--){
      if(c[j-1] > c[j]){
	k = c[j];
	c[j] = c[j-1];
	c[j-1] = k;
	strcpy(x,a[j]);
	strcpy(a[j],a[j-1]);
	strcpy(a[j-1],x);
	flag = 1;
      }
    }
    i++;
  }
}

void selectsort(char b[][3],int e[],int n){
  int i,min,j,k,m;
   char x[3];

  for(i = 0;i < n-1; i++){
    min = i;
   for(j = i;j < n; j++){
    if(e[j] < e[min]){
      min = j;
     }
    }
   if(e[i] > e[min]){
      k = e[i];
      e[i] = e[min];
      e[min] = k;
      strcpy(x,b[i]);
      strcpy(b[i],b[min]);
      strcpy(b[min],x);
   }
  }
}

int main(){
  
  int i,n,result = 0,c[36],e[36];
  char a[36][3],b[36][3],*d;
  
   scanf("%d",&n);
  
  for(i = 0;i<n;i++){
    scanf("%s",a[i]);
    strcpy(b[i],a[i]);
    c[i] = (int)strtol(&b[i][1],&d,0);
    e[i] = c[i];
  }
  bubblesort(a,c,n);
  selectsort(b,e,n);
  for(i = 0;i<n;i++){
    if(i > 0)printf(" ");
    printf("%s",a[i]);
  }
  printf("\nStable\n");

   for(i = 0;i<n;i++){
    if(i > 0)printf(" ");
    printf("%s",b[i]);
    if(strcmp(a[i],b[i])==0)result++;
  }
   
   if(result == n)printf("\nStable\n");
   else printf("\nNot stable\n");
  return 0;
}

