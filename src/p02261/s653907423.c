#include<stdio.h>
typedef struct{
  char form;
  int num;
}card;
int main()
{
  int n,m,i,j,k=0,wr=0;
  scanf("%d",&n);
  card a[n];
  card tmp;
  card b[n];
  for(i=0;i<n;i++){
    scanf(" %c",&a[i].form);
    scanf("%d",&a[i].num);
    if(i!=n-1)scanf(" ");
    b[i]=a[i];
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j].num<a[j-1].num){
        tmp=a[j-1];
        a[j-1]=a[j];
        a[j]=tmp;
      }
    }
    }
  for(i=0;i<n;i++){
    printf("%c%d",a[i].form,a[i].num);
    if(i!=n-1)printf(" ");
    }
    printf("\n");
  printf("Stable\n");
  for(i=0;i<n;i++){
    int minj=i;
    for(j=i;j<n;j++){
      if(b[j].num<b[minj].num){
        minj=j;
      }
    }
    tmp=b[i];
    b[i]=b[minj];
    b[minj]=tmp;
  }
  for(i=0;i<n;i++){
    printf("%c%d",b[i].form,b[i].num);
    if(a[i].num!=b[i].num || a[i].form!=b[i].form)wr++;
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  if(wr!=0){
    printf("Not stable\n");
  }else{
    printf("Stable\n");
  }
  return 0;
}
