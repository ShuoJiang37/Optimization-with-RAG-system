#include<stdio.h>
#define N 101
struct Card{char suit;int value; };
int main()
{
  struct Card a[N],b[N];
  int total,i,j,k,mini,m,sum=0;
  char ch;
  scanf("%d%c",&total,&ch);
  for(i=0;i<total;i++){
    scanf("%c%d%c",&a[i].suit,&a[i].value,&ch);
  }
  for(i=0;i<total+1;i++){
    b[i]=a[i];
  }
    for(i=0;i<total-1;i++){
    for(j=total-1;j>i;j--){
      if(a[j].value<a[j-1].value){
        m=a[j].value;
        a[j].value=a[j-1].value;
        a[j-1].value=m;
        ch=a[j].suit;
        a[j].suit=a[j-1].suit;
        a[j-1].suit=ch;
      }
    }
  }
  for(i=0;i<total-1;i++){
    mini=i;
    m=b[i].value;
    for(j=i;j<total;j++){
      if(b[j].value<m){
        m=b[j].value;
        mini=j;
      }
    }
     if(m!=b[i].value){
      k=b[i].value;
      b[i].value=b[mini].value;
      b[mini].value=k;
      ch=b[i].suit;
      b[i].suit=b[mini].suit;
      b[mini].suit=ch;
    }
  }
  for(i=0;i<total;i++){
    if(a[i].suit==b[i].suit && a[i].value==b[i].value){
    sum++;
    }
  }
  for(i=0;i<total-1;i++){
    printf("%c%d ",a[i].suit,a[i].value);
  }
  printf("%c%d",a[i].suit,a[i].value);
  printf("\nStable\n");

  for(i=0;i<total-1;i++){
    printf("%c%d ",b[i].suit,b[i].value);
  }
  printf("%c%d",b[i].suit,b[i].value);
  if(sum==total)printf("\nStable\n");
  else printf("\nNot stable\n");
  return 0;
}
    
