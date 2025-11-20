#include<stdio.h>
typedef struct{
  char sub;
  int figure;
}card;
void bubble(card [],int);
void selection(card [],int);
int stable_cor(card [],card [],int);
void swap(card *,card *,int);
int main(){
  int number;
  int i;
  int flag;
  card cards[36],cards1[36];
  scanf("%d%*c",&number);
  for(i=0;i<number;i++){
    scanf("%c%d%*c",&cards[i].sub,&cards[i].figure);
    cards1[i].sub=cards[i].sub;
    cards1[i].figure=cards[i].figure;
  }
bubble(cards,number);
selection(cards1,number);
flag=stable_cor(cards,cards1,number);
for(i=0;i<number;i++){
  printf("%c%d",cards[i].sub,cards[i].figure);
  if(i<number-1)printf(" ");
  else printf("\n");
}
printf("Stable\n");
for(i=0;i<number;i++){
  printf("%c%d",cards1[i].sub,cards1[i].figure);
  if(i<number-1)printf(" ");
  else printf("\n");
}
if(flag!=1)printf("Stable\n");
else printf("Not stable\n");
return 0;
}
void swap(card *a,card *b,int n){
card c;
c=*a;
*a=*b;
*b=c;
}
int stable_cor(card a[],card b[],int n){
int i;
int flag=0;
  for(i=0;i<n;i++){
    if(a[i].sub!=b[i].sub)flag=1;
  }
  return flag;
}
void bubble(card b[],int n){
int i;
int j;
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(b[j].figure<b[j-1].figure)swap(&b[j],&b[j-1],j);
    }
  }
}
void selection(card s[],int n){
  int i;
  int j;
  int min;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<n;j++){
      if(s[j].figure<s[min].figure)min=j;
    }
    if(min!=i)swap(&s[i],&s[min],min);
  }
}

