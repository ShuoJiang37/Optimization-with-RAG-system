#include<stdio.h>
#define N 36

void bubble(int,int *,char *);
void selec(int,int *,char *);
int isStable(int,char *,char *);

int main(){
  int i;
  int NUMBER[N],NUMBER_se[N];
  char mark[N],mark_se[N];
  char blank;
  int num;
  int hantei;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%c%c%d",&blank,&mark[i],&NUMBER[i]);
    NUMBER_se[i]=NUMBER[i];
    mark_se[i]=mark[i];
  }

  bubble(num,NUMBER,mark);
  printf("Stable\n");

  selec(num,NUMBER_se,mark_se);
  
  for(i=0;i<num;i++){
    if(mark[i]!=mark_se[i]){
      printf("Not stable\n");
      break;
    }
  }
  if(i==num)printf("Stable\n");

  return 0;
}

void bubble(int num,int x[],char y[]){
  int i,j;
  int mask;
  char blank;

  for(i=0;i<num-1;i++){
    for(j=num-1;i<j;j--){
      if(x[j]<x[j-1]){
	mask=x[j];
	x[j]=x[j-1];
	x[j-1]=mask;

	blank=y[j];
	y[j]=y[j-1];
	y[j-1]=blank;
      }
    }
  }

  for(i=0;i<num;i++){
    if(i!=0)printf(" ");
    printf("%c%d",y[i],x[i]);
  }
  printf("\n");

}

void selec(int num,int x[],char y[]){
  int i,j,min;
  int mask;
  char blank;

  for(i=0;i<num-1;i++){
    min=i;
    for(j=i;j<num;j++){
      if(x[j]<x[min]){
	min=j;
      }
    }
    if(i!=min){
      mask=x[i];
      x[i]=x[min];
      x[min]=mask;
    
      blank=y[i];
      y[i]=y[min];
      y[min]=blank;
    }
  }

  for(i=0;i<num;i++){
    if(i!=0)printf(" ");
    printf("%c%d",y[i],x[i]);
  }
  printf("\n");
}