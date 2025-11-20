#include <stdio.h>
#define N 36

typedef struct{
  char design;
  int num;
}card;



int main(){
  int i,j,n,minj,c=0;
  card a[N],b[N],temp;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&a[i].design,&a[i].num);
    b[i].design=a[i].design;
    b[i].num=a[i].num;
  }
  //bubblesort
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j].num<a[j-1].num){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
      }
    }
  }
  
  //selectionsort 
   for(i=0;i<n;i++){
     minj=i;
    for(j=i;j<n;j++){
      if (b[j].num < b[minj].num){
	minj=j;
      }
    }
    if(i!=minj){
      temp=b[i];
      b[i]=b[minj];
      b[minj]=temp;
    }
   }
  for(i=0;i<n;i++){
    printf("%c%d",a[i].design,a[i].num);
    if(i<n-1)printf(" ");
  }
  printf("\nStable\n");
  for(i=0;i<n;i++){
    printf("%c%d",b[i].design,b[i].num);
    if(i<n-1)printf(" ");
    if(a[i].design!=b[i].design)c++;
  }
  if(c)printf("\nNot stable\n");
  else printf("\nStable\n");
  
  return 0;
}

