#include <stdio.h>
#include <stdlib.h>

#define MAX_1 37
#define MAX_2 2

main()
{
  int i, j, n, a, c, x;
  char b, d, mini;
  char card[MAX_1][MAX_2], cardX[MAX_1][MAX_2], cardS[MAX_1][MAX_2], str[3];  
  
  scanf("%d",&n);
  
  for(i=1; i<=n; i++){
    scanf("%s",str);
    card[i][0]=cardS[i][0]=cardX[i][0]=str[0];
    card[i][1]=cardS[i][1]=cardX[i][1]=atoi(&str[1]);
  }
  
  for(i=1; i<=n; i++){
    for(j=n; j>i; j--){
      if(cardX[j-1][1] > cardX[j][1]){
	a=cardX[j][0];
	b=cardX[j][1];
	cardX[j][0]=cardX[j-1][0];
	cardX[j][1]=cardX[j-1][1];
	cardX[j-1][0]=a;
	cardX[j-1][1]=b;
      }
    }
  }
  
  for(i=1; i<n; i++){
    mini=i;
    for(j=i; j<=n; j++){
      if(cardS[j][1] < cardS[mini][1]){
	mini=j;
      }
    }
    if(cardS[i][1] > cardS[mini][1]){
      c=cardS[i][0];
      d=cardS[i][1];
      cardS[i][0]=cardS[mini][0];
      cardS[i][1]=cardS[mini][1];
      cardS[mini][0]=c;
      cardS[mini][1]=d;
    }
  }
  
  x=1;
  
  for(i=1; i<n; i++){
    printf("%c%d ",cardX[i][0],cardX[i][1]);
    if(x==1 && i<0 && cardX[i-1][1]==cardX[i][1]){
      for(j=1; j<=n; j++){
	if(card[j][0]==cardX[i-1][0] && cardX[i-1][1]==card[j][1]){
	  break;
	}
	if(card[j][1]==cardX[i][1] && card[i][0]==cardX[j][0]){
	  x=0;
	  break;
	}
      }
    }
  }
  
  if(i==n){ 
    printf("%c%d",cardX[i][0],cardX[i][1]);
  }
  
  printf("\n");
  
  if(x==1){
    printf("Stable\n");
  }
  
  else printf("Not stable\n");
  
  x=1;
  
  for(i=1; i<n; i++){
    printf("%c%d ",cardS[i][0],cardS[i][1]);
    if(x==1 && i>0 && cardS[i-1][1]==cardS[i][1]){
      for(j=1; j<=n; j++){
	if(card[j][0]==cardS[i-1][0] && cardS[i-1][1]==card[j][1]){
	  break;
	}
	if(card[j][1]==cardS[i][1] && cardS[i][0]==card[j][0]){
	  x=0;
	  break;
	}
      }
    }
  }
  if(i==n){ 
    printf("%c%d",cardS[i][0],cardS[i][1]);
  }
  
  printf("\n");
  
  if(x==1){
    printf("Stable\n");
  }
  
  else printf("Not stable\n");
  
  return 0;
}