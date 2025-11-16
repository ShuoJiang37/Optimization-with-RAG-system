#include<stdio.h>

struct Card{
  char suit;
  int value;
};


int main(){
  struct Card C1[101], C2[101],key[101];
  int n, i,j,mini,count=0;;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 1; i <= n; i++ ){
    scanf("%c%d%c", &C1[i].suit, &C1[i].value, &ch);
  }

for ( i = 1; i <= n; i++ ){
  C2[i]=C1[i]; 
  }
for(i=1;i<=n;i++){
    for(j=n;j>=i+1;j--){
      if(C1[j].value<C1[j-1].value){
    key[j]=C1[j];
    C1[j]=C1[j-1];
    C1[j-1]=key[j];
    }}}
   for(i=1;i<=n;i++){
if(i==n){
printf("%c%d\n",C1[i].suit,C1[i].value);
    break;
}
 printf("%c%d ",C1[i].suit,C1[i].value);
}
	printf("Stable\n");
	
	
	for(i=1;i<=n;i++){
    mini=i;
    for(j=i;j<=n;j++){
        if(C2[j].value<C2[mini].value){
        mini=j;
        }}         
    if(C2[mini].value<C2[i].value){
    key[i]=C2[i];
    C2[i]=C2[mini];
    C2[mini]=key[i];
    }}
	
	  for(i=1;i<=n;i++){
if(i==n){
printf("%c%d\n",C2[i].suit,C2[i].value);
    break;
}
 printf("%c%d ",C2[i].suit,C2[i].value);
}
for(i=1;i<=n;i++){
	if(C1[i].value==C2[i].value && C1[i].suit==C2[i].suit){
		count++;
		}
else break;
}
	if(count==n) printf("Stable\n");
	else printf("Not stable\n");
	
	
  return 0;}