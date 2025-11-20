#include <stdio.h>

int main(void) {
  int n,i,j,num1[36],num2[36],nchange,min,minpoint,count;
  char mar1[36],mar2[36],mchange;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf(" %c %d",&mar1[i],&num1[i]);
    num2[i] = num1[i];
    mar2[i] = mar1[i];
  }
  for(i = 0; i < n; i++){
    for(j = n - 1; j >= i + 1; j--){
      if(num1[j] < num1[j - 1]){
        nchange = num1[j];
        num1[j] = num1[j - 1];
        num1[j - 1] = nchange;
        mchange = mar1[j];
        mar1[j] = mar1[j - 1];
        mar1[j - 1] = mchange;
      }
    }
  }
  for(i = 0; i < n; i++){
    if(i != 0)printf(" ");
    printf("%c%d",mar1[i],num1[i]);
  }
  printf("\nStable\n");

  for(i = 0; i < n; i++){
    minpoint = i;
    min = 999;
    for(j = i; j < n; j++){
      if(min > num2[j]){
        min = num2[j];
        minpoint = j;
      }
    }
    nchange = num2[i];
    num2[i] = num2[minpoint];
    num2[minpoint] = nchange;
    mchange = mar2[i];
    mar2[i] = mar2[minpoint];
    mar2[minpoint] = mchange;
  }
  for(i = 0; i < n; i++){
    if(i != 0)printf(" ");
    printf("%c%d",mar2[i],num2[i]);
  }

  for(i = 0; i < n; i++)if(mar1[i] == mar2[i])count++;
  if(count == n)printf("\nStable\n");
  else printf("\nNot stable\n");
  return 0;
}
