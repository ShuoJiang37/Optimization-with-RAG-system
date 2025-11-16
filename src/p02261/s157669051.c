#include<stdio.h>
#include<string.h>
#define N 36
  
typedef struct{
  char mark;
  int value;
}card;

void BubbleSort(card *c,int n){
  int i,j;
  card tmp;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(c[j].value<c[j-1].value){
	tmp = c[j];
	c[j]=c[j-1];
	c[j-1]=tmp;
      }
    }
  }
}
void SelectionSort(card *c,int n){
  int i,j,min;
  card tmp;
  for(i=0;i<n;i++){
    min = i;
    for(j=i;j<n;j++){
      if(c[j].value<c[min].value){
	min = j;
      }
    }
    tmp = c[i];
    c[i]=c[min];
    c[min]=tmp;
  }
}


int main(){
  int n, i;
  card c1[N], c2[N];
  int flag =0;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&c1[i].mark,&c1[i].value);
  }

  for(i=0;i<n;i++) c2[i]=c1[i];

  BubbleSort(c1,n);
  
  for(i=0;i<n-1;i++) printf("%c%d ",c1[i].mark,c1[i].value);
  printf("%c%d\n",c1[n-1].mark,c1[n-1].value);
  printf("Stable\n");

  SelectionSort(c2,n);
  for(i=0;i<n-1;i++) printf("%c%d ",c2[i].mark,c2[i].value);
  printf("%c%d\n",c2[n-1].mark,c2[n-1].value);
  
for(i=0;i<n;i++) if(c1[i].mark!=c2[i].mark) flag++;
  if(flag==0) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}