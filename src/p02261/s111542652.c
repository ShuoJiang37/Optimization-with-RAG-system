#include<stdio.h>
#include<stdlib.h>
#define N 37

typedef struct {
  char a;
  int num;
}data;

data *BubbleSort(data *,int);
data *SelectionSort(data *,int);
void swap(data*,data*);
int cheak(data*,data*,int);

int main(){
  data member[N],member2[N],*result,*result2;
  int i,n;

  scanf("%d",&n);
 

  for(i=0;i<n;i++){
    scanf(" %c%d",&member[i].a,&member[i].num);   
  }
 for(i=0;i<n;i++){
 member2[i]=member[i];
 }

result=BubbleSort(member,n);

 

for(i=0;i<n;i++){
printf("%c%d",result[i].a,result[i].num);
if(i!=n-1)
printf(" ");
}
printf("\n");

  printf("Stable\n");


result2=SelectionSort(member2,n);

for(i=0;i<n;i++){
printf("%c%d",result2[i].a,result2[i].num);
if(i!=n-1)
printf(" ");
}
printf("\n");
if(cheak(result2,result,n)==0){
  printf("Stable\n");
} else printf("Not stable\n");


return 0;
}

data* BubbleSort(data *da,int n){
  data *change;
  int i,j;
  change=da;
  for(i=0;i<n;i++){
    for(j=n-1;j>0;j--){
      if(change[j].num<change[j-1].num)
      swap(&change[j],&change[j-1]);
      }
  }
  return change;
}

data* SelectionSort(data *dai,int n){
  data *change;
  int i,j,minj;
  change=dai;

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(change[j].num<change[minj].num)
      minj=j;
    }
  
   if(i!=minj)
    swap(&change[i],&change[minj]);
  }
return change;
}


void swap(data *x,data *y){
 data change;

 change=*x;
 *x=*y;
 *y=change;
}

int cheak(data *x,data *a,int n){
  int i;
   for(i=0;i<n;i++){
    if(x[i].a!=a[i].a)
    return 1;
  }
  return 0;
}
