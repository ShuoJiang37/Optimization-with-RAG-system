#include <stdio.h>

struct card{
  char suit;
  char value;
};

void bubble(struct card a[],int n)
{
  int i,j;
  struct card t;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j].value < a[j-1].value){
        t=a[j];
        a[j]=a[j-1];
        a[j-1]=t;
      }
    }
  }
}

void select(struct card a[],int n)
{
  int i,j,min;
  struct card t;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j].value < a[min].value) min=j;
    }
    t=a[i];
    a[i]=a[min];
    a[min]=t;
  }
}

void print(struct card a[],int n)
{
  int i;
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%c%c",a[i].suit,a[i].value);
  }
  printf("\n");
}

int stable(struct card c1[],struct card c2[],int n)
{
  int i,result=1;
  for(i=0;i<n;i++){
    if(c1[i].suit != c2[i].suit) result=0; 
  }
  return result;
}

int main(){
  struct card c1[101],c2[101];
  int n,i;
  char str;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%c",&c1[i].suit,&c1[i].value);
  }
  for(i=0;i<n;i++){
    c2[i].suit=c1[i].suit;
    c2[i].value=c1[i].value;
  }
  bubble(c1,n);
  select(c2,n);

  print(c1,n);
  printf("Stable\n");
  print(c2,n);
  if(stable(c1,c2,n)==1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  return 0;
}
