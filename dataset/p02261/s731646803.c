#include <stdio.h>
#define N 36
#define exch(a, b) {card x = a; a = b; b = x;}
#define less(a, b) (a.num < b.num)
#define compexch(a, b) {if(less(a, b))exch(a, b);}

typedef struct{
  char mark, num;
}card;

void printarr(card *a, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%c%c", a[i].mark, a[i].num);
    printf((i == n - 1) ? "" : " ");
  }
  printf("\n");
}

void selectionSort(card *a, int n){
  int i, j, min, count = 0;
  for(i = 0; i < n - 1; i++){
    min = i;
    for(j = i + 1; j < n; j++)
      if(less(a[j], a[min])) min = j;
    if(min != i) exch(a[i], a[min]);
  }
}

void bubblesort(card *a, int n){
  int i, j;
  for(i = 0; i < n - 1; i++)
    for(j = n - 1; j >= i; j--)
      compexch(a[j], a[j - 1]);
}

int comparr(card *a, card *b, int n){
  int i;
  for(i = 0; i < n; i++)
    if(a[i].mark != b[i].mark) return 0;
  return 1;
}

int main(void){
  int n, i;
  char ch;
  card bubble[N], select[N];
  scanf("%d%c", &n, &ch);
  for(i = 0; i < n; i++){
    scanf("%c%c%c", &bubble[i].mark, &bubble[i].num, &ch);
    select[i] = bubble[i];
  }
  bubblesort(bubble, n);
  printarr(bubble, n);
  printf("Stable\n");
  selectionSort(select, n);
  printarr(select, n);
  printf(comparr(bubble, select, n) ? "Stable\n" : "Not stable\n");
  return 0;
}