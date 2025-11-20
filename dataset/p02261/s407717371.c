#include<stdio.h>
struct Card{
  char suit;
  int value;
};

int main(){
  struct Card C1[101], C2[101];
  int i,j,K,n,t,mini,ii;
  char ch,u;
  
  scanf("%d%c", &K, &ch);
  for ( i = 0; i < K; i++ ){
    scanf("%c%d%c", &C1[i].suit, &C1[i].value, &ch);
    C2[i].suit = C1[i].suit;
    C2[i].value = C1[i].value;
  }
  for(i=0;i<K-1;i++){
    for(j=K-1;i<j;j--){
      if(C1[j].value<C1[j-1].value){
	int t=C1[j].value;
	C1[j].value=C1[j-1].value;
	C1[j-1].value=t;
	char u=C1[j].suit;
	C1[j].suit=C1[j-1].suit;
	C1[j-1].suit=u;
      }
    }
  }
  
  for(i=0;i<K-1;i++){
    mini=i;
    for(j=i;j<K;j++){
      if(C2[j].value<C2[mini].value){
	mini=j;
      }
    }
    int t=C2[i].value;
    C2[i].value=C2[mini].value;
    C2[mini].value=t;
    char u=C2[i].suit;
    C2[i].suit=C2[mini].suit;
    C2[mini].suit=u;
  }
  for(n=0;n<K;n++){
    if(n == K-1)
      printf("%c%d",C1[n].suit,C1[n].value);
    else printf("%c%d ",C1[n].suit,C1[n].value);
  }
  printf("\n");
  printf("Stable\n");
  for(n=0;n<K;n++){
    if(n == K-1)
      printf("%c%d",C2[n].suit,C2[n].value);
    else printf("%c%d ",C2[n].suit,C2[n].value);
  }
  printf("\n");
  for(n=0;n<K;n++){
    if(C1[n].suit!=C2[n].suit){
      printf("Not stable\n");
      break;
    }
    if(n==K-1)printf("Stable\n");
  }
  return 0;
}