#include <stdio.h>
struct C{
  int num;
  char c;
};

int main(){

  int n,i,j,tmp,min,flag=0;
  char tmpc;
  struct C card[36],out2[36];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&card[i].c,&card[i].num);
    out2[i].c=card[i].c;
    out2[i].num=card[i].num;
  }

  for(i=0;i<n;i++){
    for(j=n-1;i<j;j--){
      if(card[j].num < card[j-1].num){
	tmp=card[j].num;
	tmpc=card[j].c;
	card[j].num=card[j-1].num;
	card[j].c=card[j-1].c;
	card[j-1].num=tmp;
	card[j-1].c=tmpc;
      }
      
    }
  }

  for(i=0;i<n;i++){
    if(i==0) printf("%c%d",card[i].c,card[i].num);
    else printf(" %c%d",card[i].c,card[i].num);
    }
  printf("\n");

  printf("Stable\n");
 


  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(out2[j].num < out2[min].num) min=j;

      
    }
      tmp=out2[min].num;
      tmpc=out2[min].c;
      out2[min].num=out2[i].num;
      out2[min].c=out2[i].c;
      out2[i].num=tmp;
      out2[i].c=tmpc;
      
    
  }

  for(i=0;i<n;i++){
    if(i==0) printf("%c%d",out2[i].c,out2[i].num);
    else printf(" %c%d",out2[i].c,out2[i].num);

    if(out2[i].c!=card[i].c) flag=1;
     
    else if(out2[i].num!=card[i].num) flag=1;
  }
  printf("\n");

 if(flag==0) printf("Stable\n");
 else printf("Not stable\n");


  return 0;
}