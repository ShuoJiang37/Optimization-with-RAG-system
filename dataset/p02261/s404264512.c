/*安定なソート*/
#include <stdio.h>
#include <stdlib.h>

#define N 37

typedef struct{
  char mark;
  int value;
} Card;

int isStable(Card *, Card *, int);
int ctoi(char);

int main(){
  Card c[N], s[N], b[N], tmp;
  char data[2];
  int i, j, n, min;

  /*入力*/
  scanf("%d", &n);
  for (i=0; i<n; i++){
    scanf("%s", data);
    c[i].mark = data[0];
    c[i].value = ctoi(data[1]);
    s[i] = c[i];
    b[i] = c[i];
  }
  
  /*バブルソートについて*/
  for (i=0; i<n; i++){
    for (j=n-1; j>i; j--){
      if (b[j].value < b[j-1].value){
	tmp = b[j];
	b[j] = b[j-1];
	b[j-1] = tmp;
      }
    }
  }
  for (i=0; i<n-1; i++){
    printf("%c%d ",b[i].mark, b[i].value);
  }
  printf("%c%d\n",b[n-1].mark, b[n-1].value);
  if (isStable(c,b,n))
    printf("Stable\n");
  else
    printf("Not stable\n");
  
  
   /*選択ソートについて*/
  for (i=0; i<n; i++){
    min = i;
    for (j=i; j<n; j++){
      if (s[j].value < s[min].value)
	min = j;
    }
    tmp = s[i];
    s[i] = s[min];
    s[min] = tmp;
  }
  
  for (i=0; i<n-1; i++){
    printf("%c%d ",s[i].mark, s[i].value);
  }
  printf("%c%d\n",s[n-1].mark, s[n-1].value);
  if (isStable(s,b,n))
    printf("Stable\n");
  else
    printf("Not stable\n");

  return 0;
}

int isStable(Card *in, Card *out, int n){
  int i, j, k, l;
  
  for (i=0; i<n; i++){
    for (j=i+1; j<n; j++){
      for (k=0; k<n; k++){
	for (l=k+1; l<n; l++){
	  if (in[i].value == in[j].value &&
	      in[i].value == out[l].value &&
	      in[j].value == out[k].value &&
	      in[i].mark == out[l].mark &&
	      in[j].mark == out[k].mark)
	    return 0;
	}
      }
    }
  }

  return 1;
}

int ctoi(char c) {
  switch (c) {
  case '0': return 0;
  case '1': return 1;
  case '2': return 2;
  case '3': return 3;
  case '4': return 4;
  case '5': return 5;
  case '6': return 6;
  case '7': return 7;
  case '8': return 8;
  case '9': return 9;
  default: return 0;
  }
}

