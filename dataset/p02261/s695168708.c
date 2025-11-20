#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 36


typedef struct  {
  char c;
  int value;
} data;


void selectionsort(data *,int);
void bubblesort(data *,int);
void swap(data *,data *);


int main(){
  data a[N];
  data b[N];
  char c[2];
  int i,j,n,flag=0;
  
  
  scanf("%d",&n);
  for(i=0;i<n;i++){   
    scanf("%s",c);
    a[i].c=c[0];
    a[i].value=atoi(&c[1]);
    b[i].c=a[i].c;
    b[i].value=a[i].value;
  }
  
  bubblesort(a,n);  
  selectionsort(b,n);
  
  for(i=0;i<n;i++){
    printf("%c%d",a[i].c,a[i].value);
    if(i<n-1)printf(" ");
  }

  printf("\nStable\n");
    
  for(i=0;i<n;i++){
    printf("%c%d",b[i].c,b[i].value);
    if(i<n-1)printf(" ");
  }
  for(i=0;i<n;i++){
    if(a[i].c==b[i].c && a[i].value==b[i].value);
    else flag++;
  }
  if(flag)printf("\nNot stable\n");
  else printf("\nStable\n");

  return 0;
}
void selectionsort(data b[],int n){
  int i,j,min;
  
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(b[j].value<b[min].value){
	min=j;
      }
    }
    if(i!=min){
      swap(&b[i],&b[min]);

      }
  }
  
}
void bubblesort(data a[],int n)
{
  int i,j;

  for(i=0;i<n;i++){

    for(j=n-1;j>i;j--){
      if(a[j].value<a[j-1].value){
	swap(&a[j],&a[j-1]);
      }
    }
  }

}

void swap(data *p,data *q)
{
  data tmp;

  tmp=*p;
  *p=*q;
  *q=tmp;
  
}




