#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
  char suit;
  int value;
  int order;
} CARD;

void printcards(CARD *, int);
void printisstable(CARD *, int);
void swap(CARD *, int, int);

int main()
{
  int i, j, numdata, valuedata[36], inttmp, minj;
  int stable1[37], stable2[37]; //0は添字に用いない
  char indata[3], chartmp;
  CARD c1[36],c2[36];
  
  scanf("%d",&numdata);

  for(i = 0; i <= numdata; i++) {
    stable1[i] = stable2[i] = 0;
  }

  for(i = 0; i < numdata; i++) {
    scanf("%s",indata);
    c1[i].suit = c2[i].suit = indata[0];
    c1[i].value = c2[i].value = indata[1] - '0';
    c1[i].order = c2[i].order = stable1[c1[i].value] = stable2[c2[i].value] += 1;
  }

  //Bubble Sort
  for(i = 0; i < numdata; i++) {
    for(j = numdata - 1; j >= i + 1; j--) {
      if(c1[j].value < c1[j-1].value) {
	swap(c1,j,j-1);
      }
    }
  }

  printcards(c1,numdata);
  printisstable(c1,numdata);
  

  //SelectionSprt
  for(i = 0; i < numdata; i++) {
    minj = i;
    for(j = i; j < numdata; j++) {
      if(c2[j].value < c2[minj].value) minj = j;
    }
    swap(c2,i,minj);
  }

  printcards(c2,numdata);
  printisstable(c2,numdata);
  return 0;
}

void printcards(CARD *c, int numdata)
{
  int i;

  for(i = 0; i < numdata; i++) {
    if(i) printf(" ");
    printf("%c%d",c[i].suit,c[i].value);
  }
  printf("\n");
}

void printisstable(CARD *c, int numdata)
{
  int i;
  int judge[37];
  
  for(i = 0; i <= 36; i++) {
    judge[i] = 1;
  }

  for(i = 0; i < numdata; i++) {
    if(c[i].order > judge[c[i].value]) {
      printf("Not stable\n");
      return;
    }
    judge[c[i].value]++;
  }

  printf("Stable\n");
}

void swap(CARD *c, int x, int y)
{
  int inttmp;
  char chartmp;
  
  inttmp = c[x].value;
  c[x].value = c[y].value;
  c[y].value = inttmp;
	
  chartmp = c[x].suit;
  c[x].suit = c[y].suit;
  c[y].suit = chartmp;

  inttmp = c[x].order;
  c[x].order = c[y].order;
  c[y].order = inttmp;
}


