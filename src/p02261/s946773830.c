#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 36

typedef struct{
  char c;
  int num;
} pair;

int n;

int judgment(pair *, pair *);

int main(){
  int i, j, ask, minimum; 
  char *judge[2] = {"Stable", "Not stable"};
  pair a[N], b[N], temp1, temp2;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf(" %c", &a[i].c);
    scanf("%d", &a[i].num);
    b[i] = a[i];
  }

  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){
      if(a[j].num < a[j - 1].num){
	temp1 = a[j];
	temp2 = a[j - 1];

	a[j] = temp2;
	a[j - 1] = temp1;
      }
    }
  }

  for(i = 0; i < n; i++){
    minimum = i;
    
    for(j = i; j < n; j++){
      if(b[j].num < b[minimum].num)
	minimum = j;
    }
    if(minimum != i){
      temp1 = b[minimum];
      temp2 = b[i];
      b[minimum] = temp2;
      b[i] = temp1;
    }
  }
    
  ask = judgment(a, b);
  
  for(i = 0; i < n; i++){
    if(i != n - 1)
      printf("%c%d ", a[i].c, a[i].num);
    else
      printf("%c%d", a[i].c, a[i].num);
  }
  printf("\n%s\n", judge[0]);
    
  for(i = 0; i < n; i++){
    if(i != n - 1)
    printf("%c%d ", b[i].c, b[i].num);
    else
      printf("%c%d", b[i].c, b[i].num);
  }
  
  printf("\n");
  if(ask == 1)
    printf("%s\n", judge[0]);
  else
    printf("%s\n", judge[1]);
      

  return 0;
}

int judgment(pair *a, pair *b){
  int i;

  for(i = 0; i < n; i++){
    if(a[i].c != b[i].c)
      return 0;
  }

  return 1;
}

