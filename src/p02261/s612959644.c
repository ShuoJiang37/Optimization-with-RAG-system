#include <stdio.h>
#include <string.h>
void bubble_sort(int C[], int value[], int length) {
  int i,j,tmp;
  for(i = 1; i <= length; ++i) {
    for(j = length; j >= i+1; --j) {
      if(value[C[j]] < value[C[j-1]]) {
        tmp = C[j];
        C[j] = C[j-1];
        C[j-1] = tmp;
      }
    }
  }
}

void select_sort(int C[], int value[], int length) {
  int i,j,mini,tmp;
  for(i = 1; i <= length; ++i) {
    mini = i;
    for(j = i; j <= length; ++j) {
      if(value[C[j]] < value[C[mini]] ){
        mini = j;
      }
    }
    tmp = C[i];
    C[i] = C[mini];
    C[mini] = tmp;
  }
}

void make_str(char str[], int C[], int value[], char mark[], int length) {
  int i,j,k;
  k = 0;
  for(i = 1; i <= 9; ++i) {
    for(j = 1; j <= length; ++j) {
      if(value[C[j]] == i) str[k++] = mark[C[j]];
    }
  }
  str[k] = '\0';
}

void show(int C[], int value[], char mark[], int length, int isNotStable) {
  int i;
  for(i = 1; i <= length; ++i) {
    if(i != 1) printf(" ");
    printf("%c%d", mark[C[i]], value[C[i]]);
  }
  printf("\n");
  printf("%s\n",isNotStable==0?"Stable":"Not stable");
}

int main() {
  int length;
  int value[37];
  char mark[37];

  int C[37],C1[37],C2[37];
  char S[37],S1[37],S2[37];
  int i,j,k;

  scanf("%d", &length);
  for(i = 1; i <= length; ++i) {
    scanf(" %c%d", &mark[i], &value[i]);
  }
  for(i = 1; i <= length; ++i) {
    C[i] = C1[i] = C2[i] = i;
  }

  bubble_sort(C1,value,length);
  select_sort(C2,value,length);

  make_str(S,C,value,mark,length);
  make_str(S1,C1,value,mark,length);
  make_str(S2,C2,value,mark,length);
  show(C1,value,mark,length,strcmp(S,S1));
  show(C2,value,mark,length,strcmp(S,S2));

  return 0;
}