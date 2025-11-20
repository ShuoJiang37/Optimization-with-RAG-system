#include<stdio.h>

int main(){
  int i,j,n,min,flag=0;
  char tmp,cardA[36][2],cardB[36][2];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%c",&cardA[i][0],&cardA[i][1]);
    cardB[i][0]=cardA[i][0];
    cardB[i][1]=cardA[i][1];
  }

  for(i=0;i<n;i++){
    for(j=n-1;i+1<=j;j--){
      if(cardA[j][1]<cardA[j-1][1]){
	tmp=cardA[j][1];
	cardA[j][1]=cardA[j-1][1];
	cardA[j-1][1]=tmp;
	tmp=cardA[j][0];
	cardA[j][0]=cardA[j-1][0];
	cardA[j-1][0]=tmp;
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%c%c ",cardA[i][0],cardA[i][1]);
  printf("%c%c\n",cardA[i][0],cardA[i][1]);
  printf("Stable\n");

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(cardB[j][1]<cardB[min][1]) min=j;
    }
    
    tmp=cardB[i][1];
    cardB[i][1]=cardB[min][1];
    cardB[min][1]=tmp;
    tmp=cardB[i][0];
    cardB[i][0]=cardB[min][0];
    cardB[min][0]=tmp;
  }

  for(i=0;i<n;i++){
    if(cardA[i][0]!=cardB[i][0] || cardA[i][1]!=cardB[i][1]) flag=1;
  }

  for(i=0;i<n-1;i++) printf("%c%c ",cardB[i][0],cardB[i][1]);
  printf("%c%c\n",cardB[i][0],cardB[i][1]);
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");
    
  return 0;
}

