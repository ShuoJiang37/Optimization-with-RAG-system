#include<stdio.h>

//トランプの構造体
struct Card{
  char mark;
  int num;
};

typedef struct Card card;




int main(void){
  int n,i,j,min,flag=0;
  card c1[36],c2[36],temp;
  char a;

  //入力
  scanf("%d%c",&n,&a);
  for(i=0;i<n;i++){
    scanf("%c%d%c",&c1[i].mark,&c1[i].num,&a);
    c2[i]=c1[i];
  }
  
  //バブル
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(c1[j].num < c1[j-1].num){
	temp=c1[j];
	c1[j]=c1[j-1];
	c1[j-1]=temp;
      }
    }
  }

    
  //セレクション
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(c2[j].num < c2[min].num) min=j;
    }
    temp=c2[min];
    c2[min]=c2[i];
    c2[i]=temp;
  }


  for(i=0;i<n;i++){
    if(i==n-1) printf("%c%d\n",c1[i].mark,c1[i].num);
    else  printf("%c%d ",c1[i].mark,c1[i].num);
  }
  printf("Stable\n");
  
  for(i=0;i<n;i++){
    if(i==n-1) printf("%c%d\n",c2[i].mark,c2[i].num);
    else  printf("%c%d ",c2[i].mark,c2[i].num);
  }
  
  for(i=0;i<n;i++){
    if(c1[i].mark != c2[i].mark) flag=1;
  }
  if(flag==1)printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}