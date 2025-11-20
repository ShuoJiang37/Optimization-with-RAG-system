#include<stdio.h>

struct Card{
  char Su;
  char Va;
};

void bubble(struct Card o[], int n){
  int i, j;
  struct Card t;
  for (i=0;i<n;i++){
    for (j= n-1;j>= i+1;j--){
      if (o[j].Va<o[j-1].Va){
	t=o[j];o[j]=o[j-1];o[j-1]=t;
      }
    }
  }
}

void selection(struct Card o[], int n){
  int i, j, Mi;
  struct Card t;
  for ( i = 0; i < n; i++ ){
    Mi=i;
    for (j=i;j<n;j++){
      if(o[j].Va<o[Mi].Va )Mi=j;
    }
    t=o[i];o[i]=o[Mi];o[Mi]=t;
  }
}

void print(struct Card o[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i ) printf(" ");
    printf("%c%c", o[i].Su, o[i].Va);
  }
  printf("\n");
}

int isStable(struct Card C1[], struct Card C2[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( C1[i].Su != C2[i].Su ) return 0;
  }
  return 1;
}

int main(){
  struct Card C1[101], C2[101];
  int n, i;
  char ch;

  scanf("%d\n", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c ", &C1[i].Su, &C1[i].Va);
  }

  for (i=0;i<n;i++)C2[i]=C1[i];

  bubble(C1, n);
  selection(C2, n);

  print(C1, n);
  printf("Stable\n");
  print(C2, n);
  if ( isStable(C1, C2, n) ){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  return 0;
}

