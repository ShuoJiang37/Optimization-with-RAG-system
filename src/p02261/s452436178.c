#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char suit;
  int value;
} Card;


void ChkIfStable(Card *c1, Card *c2, int n)
{
  int v, k;
  char a1[n];
  char a2[n];
  int len1, len2;
  len1 = len2 = 0;
  for (v=1; v<10; v++) {
    len1=0;
    for (k=0; k<n; k++) {
      if (c1[k].value == v) a1[len1++] = c1[k].suit;
    }
    a1[len1]=0;
    len2=0;
    for (k=0; k<n; k++) {
      if (c2[k].value == v) a2[len2++] = c2[k].suit;
    }
    a2[len2]=0;
    if (strcmp(a1,a2)) {
      fputs("Not stable\n", stdout);
      return;
    }
  }
  fputs("Stable\n", stdout);
}


void BubbleSort(Card *c, int n)
{
  int i, j;
  for (i=0; i<n; i++) {
    for (j=n-1; j>=i+1; j--) {
      if (c[j].value < c[j-1].value) {
	Card tmp = c[j];
	c[j] = c[j-1];
	c[j-1] = tmp;
      }
    }
  }
}


void  SelectionSort(Card *c, int n)
{
  int i, j, mini;
  for (i=0; i<n; i++) {
    mini = i;
    for (j=i; j<n; j++) {
      if (c[j].value < c[mini].value)	mini = j;
    }
    if (i!=mini) {
      Card tmp = c[i];
      c[i] = c[mini];
      c[mini] = tmp;
    }
  }
}

int main()
{
  int i, n;
  char buf[128];
  fgets(buf, 128, stdin);
  if (buf[1]=='\n') {
    n = buf[0]-'0';
  } else {
    n = (buf[0]-'0')*10+buf[1]-'0';
  }
  Card *cc = (Card*)malloc(sizeof(Card)*n);
  Card *bs = (Card*)malloc(sizeof(Card)*n);
  Card *ss = (Card*)malloc(sizeof(Card)*n);
  fgets(buf, 128, stdin);
  char *p = buf;
  for (int i=0; i<n; i++) {
    cc[i].suit = bs[i].suit = ss[i].suit = *p;
    cc[i].value = bs[i].value = ss[i].value = *(p+1)-'0';
    p+=3;
  }

  BubbleSort(bs, n);
  
  for (i=0; i<n-1; i++)
    fprintf(stdout, "%c%d ", bs[i].suit, bs[i].value);
  fprintf(stdout, "%c%d\n", bs[i].suit, bs[i].value);

  ChkIfStable(cc, bs, n);
  
  SelectionSort(ss, n);

  for (i=0; i<n-1; i++)
    fprintf(stdout, "%c%d ", ss[i].suit, ss[i].value);
  fprintf(stdout, "%c%d\n", ss[i].suit, ss[i].value);
  
  ChkIfStable(cc, ss, n);
  return 0;
}

