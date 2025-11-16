#include<stdio.h>

struct Card{
  char mark;
  char number;
};

int isStable(struct Card *, struct Card *, int);

int main(){
  struct Card C1[100], C2[100],k;
  int n, i, j, minj;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf(" %c %c",&C1[i].mark,&C1[i].number);
  }

  for(i=0;i<n;i++){
    C2[i]=C1[i];
  }
  
  for(i=0;i<=n-1;i++){
    for (j=n-1;j>=i+1;j--){
      if (C1[j].number<C1[j-1].number){
	k=C1[j];
	C1[j]=C1[j-1];
	C1[j-1]=k;
      }
    }
  }
  
  for (i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if (C2[j].number<C2[minj].number){
	minj=j;
      }
    }
    k=C2[i];
    C2[i]=C2[minj];
    C2[minj]=k;
  }
  
  for (i=0;i<n;i++){
    if (i>=1) printf(" ");
    printf("%c%c",C1[i].mark,C1[i].number);
  }
  printf("\n");
  printf("Stable\n");
  
  for (i=0;i<n;i++){
    if (i>=1) printf(" ");
    printf("%c%c",C2[i].mark,C2[i].number);
  }
  printf("\n");
  
  if ( isStable(C1, C2, n) == 1 ){
    printf("Stable\n");
    } else {
    printf("Not stable\n");
    }
  
  return 0;
}
int isStable(struct Card C1[], struct Card C2[], int n)
{
  int i;
  for ( i = 0; i < n; i++ ){
  if ( C1[i].mark != C2[i].mark ) return 0;
  }
  return 1;
  }