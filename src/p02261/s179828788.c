#include<stdio.h>

struct CARD{
  char suit;
  char value;
};

int main(){

  struct CARD C1[100],C2[100],new;
  int n,i,j,min;
  int cnt = 0;
  char c;

  scanf("%d",&n);
  scanf("%c",&c);

  for (i=0;i<n;i++){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value,&c);
  }

  for(i=0;i<n;i++){
    C2[i] = C1[i];
  }

  for(i=0;i<=n-1;i++){
    for(j=n-1; j>=i+1; j--){

      if(C1[j].value < C1[j-1].value){
        new = C1[j];
        C1[j] = C1[j-1];
        C1[j-1] = new;
      }
    }
  }

  for(i=0;i<=n-1;i++){
    min = i;
    for(j=i; j<=n-1; j++)
      if(C2[j].value < C2[min].value) min = j;
    if(min != i) {
      new = C2[i];
      C2[i] = C2[min];
      C2[min] = new;
    }
  }

  for(i=0;i<n-1;i++){
   printf("%c%c ",C1[i].suit,C1[i].value);
  }
  printf("%c%c\n",C1[n-1].suit,C1[n-1].value);
  printf("Stable\n");

  for(i=0;i<n-1;i++){
    printf("%c%c ",C2[i].suit,C2[i].value);
    if(C1[i].suit != C2[i].suit) cnt=1;
  }
  printf("%c%c\n",C2[n-1].suit,C2[n-1].value);

  if(cnt == 1) {
  	printf("Not stable\n");
  }else{
  	printf("Stable\n");
  }

  return 0;
}
