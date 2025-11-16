#include<stdio.h>
#define N 36
struct Card{
  char suit;
  char value;
};
int main(){
  struct Card C1[N], C2[N],p;
  int n,i,j,mini,l=0;
  char ch;
  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }
  for(i=0;i<n;i++){
    C2[i] = C1[i];
  }
  for(i=0;i<n;i++){
      for(j=n-1;j>i;j--){
    if(C1[j].value < C1[j-1].value){
          p = C1[j];
          C1[j] = C1[j-1];
          C1[j-1] = p;
    }
      }
  }
  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if(C2[j].value < C2[mini].value)
	mini = j;
       }
    p = C2[i];
    C2[i] = C2[mini];
    C2[mini] = p;
  }
  for(i=0;i<n;i++){
    printf("%c%c",C1[i].suit,C1[i].value);
    if(i != n-1)
      printf(" ");
    if(i == n-1)
      printf("\n");
    }
  printf("Stable\n");
  
  for(i=0;i<n;i++){
    printf("%c%c",C2[i].suit,C2[i].value);
    if(i != n-1)
    printf(" ");
    if(i == n-1)
      printf("\n");
  }
  for(i=0;i<n;i++){
    if(C1[i].suit != C2[i].suit)
    l = 1;
  }
  if(l==1)
    printf("Not stable\n");
  else
    printf("Stable\n");
  return 0;
}