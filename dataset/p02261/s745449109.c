#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *, char *);

int main(){
  int i, j, n;
  char **C, **cC, minj;

  scanf("%d", &n);

  C = (char **)malloc(sizeof(char *) * n);

  for(i=0; i<n; i++){
    C[i] = (char *)malloc(sizeof(char) * 2);
  }

  cC = (char **)malloc(sizeof(char *) * n);

  for(i=0; i<n; i++){
    cC[i] = (char *)malloc(sizeof(char) * 2);
  }
  
  for(i=0; i<n; i++){
    scanf("%s",C[i]);
    strcpy(cC[i], C[i]);
  }

  // BubbleSort
  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(atoi(&C[j][1]) < atoi(&C[j-1][1])){
	swap(C[j], C[j-1]);
      }
    }
  }

  for(i=0; i<n-1; i++){
      printf("%s ", C[i]);
    }

  printf("%s\n", C[i]);

  printf("Stable\n");

  // SelectionSort
  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(cC[j][1] < cC[minj][1]){
	minj = j;
      }
    }
    swap(cC[i],cC[minj]);
  }

  for(i=0; i<n-1; i++){
      printf("%s ", cC[i]);
    }

  printf("%s\n", cC[i]);

  for(i=0; i<n; i++){
    if(cC[i][0] != C[i][0]){
      printf("Not stable\n");
      return 0;
    }
  }

  printf("Stable\n");

  return 0;

}

void swap(char *a, char *b){
  int i;
  char c;

  for(i=0; i<2; i++){
  c = a[i];
  a[i] = b[i];
  b[i] = c;
  }

}