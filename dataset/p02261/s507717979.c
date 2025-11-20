#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **copyArray(char**, int);
int stableCheck(char**, char**, int);

main(){
  int n,i,j,minj;
  char **b, **c, **A;
  char *tmp;

  scanf("%d", &n);

  //元の入力保持用 配列
  tmp = (char *)malloc(n*3*sizeof(char));
  A = (char **)malloc(n*sizeof(char *));
  for(i=0; i<n; i++){
    A[i]=tmp+3*i;
    scanf("%s", A[i]);
  }

  //バブルソート用にコピー
  b = copyArray(A,n);
  //bubbleSort
  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(b[j][1]<b[j-1][1]){
	//swap
	/*strcpy(tt, b[j]);
	strcpy(b[j],b[j-1]);
	strcpy(b[j-1], tt);*/
	tmp = b[j];
	b[j] = b[j-1];
	b[j-1] = tmp;
      }
    }
  }

  //セレクトソート用にコピー
  c = copyArray(A,n);
  //bubbleSort
  for(i=0; i<=n-1; i++){
    minj = i;
    for(j=i; j<=n-1; j++){
      if(c[j][1] < c[minj][1]) minj = j;
    }
    if(minj!=i){
	tmp = c[i];
	c[i] = c[minj];
	c[minj] = tmp;
    }
  }

  //print
  for(i=0; i<n-1; i++) printf("%s ", b[i]);
  printf("%s\nStable\n", b[i]); //バブルソートは常に安定
  //print
  for(i=0; i<n-1; i++) printf("%s ", c[i]);
  printf("%s\n", c[i]);
  if(stableCheck(b,c,n)==1)printf("Stable\n");
  else printf("Not stable\n");

  //メモリ開放
  /*free(A[0]);
  free(A);
  free(b[0]);
  free(b);
  free(c[0]);
  free(c);*/

  return 0;
}

char **copyArray(char **A, int n){
  //Aをこぴーした配列の先頭アドレスを返す
  int i;
  char **res, *tmp;
  tmp = (char *)malloc(n*3*sizeof(char));
  res = (char **)malloc(n*sizeof(char *));
  for(i=0; i<n; i++){
    res[i] = tmp+3*i;
    strcpy(res[i],A[i]);
  }

  return res;
}

int stableCheck(char** c, char** b, int n){
  int i;

  for(i=0; i<n; i++){
    if(c[i][1]==b[i][1]){
      if(c[i][0]!=b[i][0]) return 0;
    }
  }
  return 1;
}