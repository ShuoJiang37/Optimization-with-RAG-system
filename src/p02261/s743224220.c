#include <stdio.h>
#define N 36

int main() {
  int i, j;
  int n, minj;
  int flag = 0;
  char bcard[N][2], scard[N][2];
  char temp[2];

  scanf("%d", &n);


  for(i = 0; i < n; i++)
    scanf("%s", bcard[i]);

  for(i = 0; i < n; i++) 
    for(j = 0; j < 2; j++) 
      scard[i][j] = bcard[i][j];
    

  //Bubble Sort
  for(i = 0; i < n; i++) {
    for(j = n - 1; j >= 0; j--) {
      if(bcard[j-1][1] > bcard[j][1]) {
	temp[0] = bcard[j][0];
        temp[1] = bcard[j][1];
	bcard[j][0] = bcard[j-1][0];
	bcard[j][1] = bcard[j-1][1];
	bcard[j-1][0] = temp[0];
	bcard[j-1][1] = temp[1];
      }
    }
  }

  //printBubbleSort
  for(i = 0; i < n; i++) {
    for(j = 0; j < 2; j++) {
      printf("%c", bcard[i][j]);
    }
    if(i < n - 1) printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  

  //Selection Sort
  for(i = 0; i < n - 1; i++) {
    minj = i;
    for(j = i; j < n; j++) {
      if(scard[minj][1] > scard[j][1]) minj = j;	
    }
    if(scard[minj][1] < scard[i][1]) {
      temp[0] = scard[i][0];
      temp[1] = scard[i][1];
      scard[i][0] = scard[minj][0];
      scard[i][1] = scard[minj][1];
      scard[minj][0] = temp[0];
      scard[minj][1] = temp[1];
    }
  }

  //Compare
  for(i = 0; i < n; i++) 
    for(j = 0; j < 2; j++) 
      if(bcard[i][j] != scard[i][j]) flag = 1;

  //printSelectionSort
  for(i = 0; i < n; i++) {
    for(j = 0; j < 2; j++) {
      printf("%c", scard[i][j]);
    }
    if(i < n - 1) printf(" ");
  }
  printf("\n");
  if(flag == 0) printf("Stable\n");
  else printf("Not stable\n");
   

  return 0;
  
}