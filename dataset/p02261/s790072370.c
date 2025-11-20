#include <stdio.h>
#include <string.h>

void a_swap(char C[][3], int i)
{
  char temp1;
  char temp2;

  temp1=C[i][0];
  C[i][0]=C[i-1][0];
  C[i-1][0]=temp1;

  temp2=C[i][1];
  C[i][1]=C[i-1][1];
  C[i-1][1]=temp2;
}

void b_swap(char C[][3], int j ,int minj)
{
  char temp1;
  char temp2;

  temp1=C[j][0];
  C[j][0]=C[minj][0];
  C[minj][0]=temp1;

  temp2=C[j][1];
  C[j][1]=C[minj][1];
  C[minj][1]=temp2;
}

void b_sort(char C[][3], int n)
{
  int i,j;

  for (i=0; i<n; i++) {
    for (j=n-1; j>i; j--) {
      if (C[j][1]<C[j-1][1]) {
        a_swap(C,j);
      }
    }
  }
}

void s_sort(char C[][3], int n)
{
  int i,j;
  int minj;

  for (i=0; i<n; i++) {
    minj=i;
    for (j=i; j<n; j++) {
      if (C[j][1]<C[minj][1]) {
        minj=j;
      }
    }
    b_swap(C,i,minj);
  }
}

int main(void)
{
  char card[53][3];
  char tcard[53][3];
  char *temp;
  int n;
  int i,j;
  int cnt[100];
  int l=0;
  int judge=0;

  scanf("%d",&n);
  
  for (i=0; i<n; i++) {
    scanf("%s",card[i]);
  }

  for (i=0; i<n; i++) {
    for (j=0; j<3; j++) {
      tcard[i][j]=card[i][j];
    }
  }
  
  b_sort(card,n);

  for (i=0; i<n; i++) {
    if (i!=n-1) printf("%s ",card[i]);
    else printf("%s\n",card[i]);
  }
  puts("Stable");

  s_sort(tcard,n);

  for (i=0; i<n; i++) {
    if (i!=n-1) printf("%s ",tcard[i]);
    else printf("%s\n",tcard[i]);
  }

  for (i=0; i<n; i++) {
    cnt[i]=strcmp(*(card+i),*(tcard+i));
    if (cnt[i]!=0) {
      judge=1;
      break;
    }
  }

  if (judge==1) printf("Not stable\n");
  else puts("Stable");

  return 0;
}