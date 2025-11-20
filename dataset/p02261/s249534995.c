#include<stdio.h>
#include<string.h>
int i,j;

typedef struct{
 char design;
  char number;
}Card;

void bubble(Card A[],int n){
  Card t;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j].number<A[j-1].number){
	t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
      }
    }
  }
}
void select(Card A[],int n){
  int min;
  Card t;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j].number<A[min].number)min=j;//????°??????¨??????????´???°  
    }
    t=A[i];
    A[i]=A[min];
    A[min]=t;
  }
}

int stable(Card c1[],Card c2[],int n){
  for(i=0;i<n;i++){
    if(c1[i].design!=c2[i].design)return -1;
  }

  return 1;
  
}

void print(Card A[],int n){

  for(i=0;i<n;i++){
    printf("%c%c",A[i].design,A[i].number);
    if(i!=n-1)printf(" ");
  }
      printf("\n");
}

int main(){
  int n;
  int i;
  Card c1[100],c2[100];
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %c%c", &c1[i].design, &c1[i].number);
    c2[i].design=c1[i].design;
    c2[i].number=c1[i].number;
  }

  bubble(c1,n);
  select(c2,n);

  print(c1,n);
  printf("Stable\n");
  print(c2,n);

  if(stable(c1,c2,n)==1)printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}



  

  