#include <stdio.h>
#include <stdlib.h>

struct Card
{
  char suit;
  int value;
};

void printCardArray(struct Card *, int);
int isStable(struct Card *, struct Card *, int);
void bubbleSort(struct Card *, int);
void selectionSort(struct Card *, int);

int main(void)
{
  int n, i;
  struct Card *list, *listBub, *listSel, current;
  scanf(" %d", &n);
  list = (struct Card *) malloc(sizeof(struct Card[n]));
  listBub = (struct Card *) malloc(sizeof(struct Card[n]));
  listSel = (struct Card *) malloc(sizeof(struct Card[n]));
  for (i = 0; i < n; i++)
    {
      scanf(" %c%d", &current.suit, &current.value);
      list[i] = current;
      listBub[i] = current;
      listSel[i] = current;
    }
  bubbleSort(listBub, n);
  printCardArray(listBub, n);
  printf("%s\n", isStable(listBub, list, n) == 0 ? "Stable" : "Not stable");
  selectionSort(listSel, n);
  printCardArray(listSel, n);
  printf("%s\n", isStable(listSel, list, n) == 0 ? "Stable" : "Not stable");
  return 0;
}

// printCardArray prints the cards in the given array with length len.
void printCardArray(struct Card *list, int len)
{
  int i;
  for (i = 0; i < len; i++)
    printf("%c%d%s", list[i].suit, list[i].value, i != len - 1 ? " " : "\n");
}

// isStable returns 0 if the lists are stable, 1 otherwise.
int isStable(struct Card *sortedList, struct Card *list, int len)
{
  int i, j, lastVal, lastPos, jStart;
  lastVal = -1;
  for (i = 0; i < len; i++)
    {
      // check if a value is duplicated
      if (sortedList[i].value == lastVal)
	{
	  jStart = lastPos + 1;
	  if (jStart == len)
	    return 1;
	}
      else
	jStart = 0;
      for (j = jStart; j < len; j++)
	{
	  if ((sortedList[i].suit == list[j].suit) &&
	      (sortedList[i].value == list[j].value))
	    break;
	  else if (j == len-1)
	    return 1;
	}
      lastVal = list[j].value;
      lastPos = j;
    }
  return 0;
}

void bubbleSort(struct Card *list, int len)
{
  int i, j;
  struct Card holder;
  for (i = 0; i < len; i++)
    for (j = len - 1; j > i; j--)
      if (list[j].value < list[j-1].value)
	{
	  holder = list[j];
	  list[j] = list[j-1];
	  list[j-1] = holder;
	}
}

void selectionSort(struct Card *list, int len)
{
  int i, j, mini;
  struct Card holder;
  for (i = 0; i < len; i++)
    {
      mini = i;
      for (j = i + 1; j < len; j++)
	if (list[j].value < list[mini].value)
	  mini = j;
      holder = list[i];
      list[i] = list[mini];
      list[mini] = holder;
    }
}

