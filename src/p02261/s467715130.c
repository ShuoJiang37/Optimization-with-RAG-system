#include<stdio.h>
#define MAX 36

void BubbleSort(char [], int [], int);
void SelectionSort(char [], int [], int, char [], int []);

int main(){
  int n, i, num1[MAX], num2[MAX];
  char c1[MAX], c2[MAX];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf(" %c%d", &c1[i], &num1[i]);
    c2[i] = c1[i];
    num2[i] = num1[i];
  }
  BubbleSort(c1, num1, n);
  SelectionSort(c2, num2, n, c1, num1);

  return 0;
}

void BubbleSort(char c[], int num[], int n){
  int i, j, flag = 1, vi;
  char vc;

  for(i = 0; i <= n - 1; i++){
    for(j = n - 1; j >= i + 1; j--){
      if(num[j] < num[j - 1]){
        vc = c[j];
        vi = num[j];
        c[j] = c[j - 1];
        num[j] = num[j - 1];
        c[j - 1] = vc;
        num[j - 1] = vi;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%c%d", c[i], num[i]);
    if(i != n - 1)
      printf(" ");
  }
  printf("\nStable\n");
}

void SelectionSort(char c[], int num[], int n, char c1[], int num1[]){
  int i, j, minj, vi, stable = 0;
  char vc;

  for(i = 0; i <= n - 1; i++){
    minj = i;
    for(j = i; j <= n - 1; j++){
      if(num[j] < num[minj]){
        minj = j;
      }
    }
    vc = c[i];
    vi = num[i];
    c[i] = c[minj];
    num[i] =num[minj];
    c[minj] = vc;
    num[minj] = vi;
  }

  for(i = 0; i < n; i++){
    printf("%c%d", c[i], num[i]);
    if(i != n - 1)
      printf(" ");
    if(c[i] != c1[i])
      stable = 1;
  }
  if(stable == 0)
    printf("\nStable\n");
  else
    printf("\nNot stable\n");
}

