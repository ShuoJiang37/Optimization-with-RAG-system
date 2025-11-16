#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
  char mark;
  int number;
}card;

void bubblesort(card*,int);
void selectionsort(card*,card*,int);

int main(){
  int n,i,j,t;
   card detail[36],detail2[36];
  char a;
  

  scanf("%d",&n);
  
  for(i=0; i<n; i++)
    {
    scanf(" %c%c",&detail[i].mark,&a);
    detail[i].number = atoi(&a);
  }

  for(i=0; i<n; i++)
  detail2[i]=detail[i];
  bubblesort(detail,n);
  selectionsort(detail,detail2,n);
  return 0;
}
  

void bubblesort(card a[],int n){
  int i,j;
  card tmp;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j].number<a[j-1].number){
	tmp=a[j];  //swap
	a[j]=a[j-1];
	a[j-1]=tmp;
      }
    }
  }

  for(i=0; i<n; i++){
    if(i>0)printf(" ");
    printf("%c%d",a[i].mark,a[i].number);
  }

  printf("\n");
  printf("Stable\n");   //bubblesortは安定 
}


void  selectionsort(card a[],card a2[],int n){
  int i,j,minj,count=0;
  card tmp;
  for(i=0; i<=n; i++){
    minj=i;
    for(j=i; j<n; j++){
      if(a2[j].number<a2[minj].number){
	minj=j;
      }
    }
    tmp=a2[i]; //swap
    a2[i]=a2[minj];
    a2[minj]=tmp;
}
  for(i=0; i<n; i++){
    if(i>0)printf(" ");
    printf("%c%d",a2[i].mark,a2[i].number);
  }
  printf("\n");

  
  for(i=0;i<n;i++){
    if(a[i].mark != a2[i].mark || a[i].number != a2[i].number){
      printf("Not stable\n");
      count=1;
      break;
    } }

  
  if(count != 1) printf("Stable\n");
  
}

 

