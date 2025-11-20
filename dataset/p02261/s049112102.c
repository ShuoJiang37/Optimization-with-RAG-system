#include<stdio.h>
typedef struct{
  int k;
  char mozi;
}card;
  
int main(){
  int i,j,n,min;
  card num[36],suit[36],temp;
   
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf(" %c%d", &num[i].mozi, &num[i].k);
    suit[i].mozi = num[i].mozi;
    suit[i].k = num[i].k;
  }
  
  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(num[j].k < num[j-1].k){
	temp = num[j];
	num[j] = num[j-1];
	num[j-1] = temp;
      }
    }
  }
 
  for(i = 0; i < n-1; i++){
    printf("%c%d ",num[i].mozi, num[i].k);
  }
  printf("%c%d\nStable\n",num[i].mozi, num[i].k);
 
  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i; j <= n-1; j++){
      if(suit[j].k < suit[min].k) min = j;
    }
    temp = suit[i];
    suit[i]=suit[min];
    suit[min]=temp;
  }
 
  for(i = 0; i < n-1; i++){
    printf("%c%d ",suit[i].mozi,suit[i].k);
  }
  printf("%c%d\n",suit[i].mozi,suit[i].k);
  
  for(i = 0; i < n; i++){
    if(suit[i].mozi != num[i].mozi) {
      printf("Not stable\n");
      break;
    }
  }
  if(i == n)printf("Stable\n");
  return 0;
}