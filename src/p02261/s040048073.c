#include <stdio.h>
#define SWAP(type,a,b) { type temp = a; a = b; b = temp; }
#define N 36

typedef struct element{
  char mark;
  int num;
}card;
 

int main(){
  int i, j, n, minj, judge=0;
  card ca[N], cb[N];
  char s;

  scanf("%d%c",&n,&s);
  for(i=0;i<n;i++){
    scanf("%c%d%c",&ca[i].mark,&ca[i].num,&s);
    cb[i] = ca[i];
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(ca[j].num < ca[j-1].num){
	SWAP(card,ca[j],ca[j-1]);
      }
    }
  }


  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(cb[minj].num > cb[j].num){
	minj = j;
      }
    }
    SWAP(card,cb[minj],cb[i]);
  }

  for(i=0;i<n;i++){
    if(i==n-1) printf("%c%d\n",ca[i].mark,ca[i].num);
    else printf("%c%d ",ca[i].mark,ca[i].num);
  }

  
  printf("Stable\n");

  
  for(i=0;i<n;i++){
    if(i==n-1) printf("%c%d\n",cb[i].mark,cb[i].num);
    else printf("%c%d ",cb[i].mark,cb[i].num);
  }


  
  for(i=0;i<n;i++){
    if(ca[i].mark != cb[i].mark) judge=1;
  }
  if(judge==1) printf("Not stable\n");
  else printf("Stable\n");


  
  return 0;
}

