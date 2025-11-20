#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct card {
  char mark;
  int value;
};

int main(int argc, char *argv[])
{
  int N, i, j, minj;
  struct card *C, *C1, *C2, tmp;
  int stable;
  char rd[3];
  char m[4];
  int order, max = 0;

  scanf("%d", &N);

  C = (struct card *)malloc(sizeof(struct card) * N);
  C1 = (struct card *)malloc(sizeof(struct card) * N);
  C2 = (struct card *)malloc(sizeof(struct card) * N);
  
  for (i = 0; i < N; i++) {
    scanf("%s", rd);
    C[i].mark = rd[0];
    C[i].value = atoi(&rd[1]);
    C1[i].mark = C[i].mark;
    C1[i].value = C[i].value;
    C2[i].mark = C[i].mark;
    C2[i].value = C[i].value;
  }

  stable = 1;
  for (i = 0; i < N; i++) {
    for (j = N - 1; j > i; j--) {
      if (C1[j].value < C1[j-1].value) {
	tmp.mark = C1[j].mark;
	tmp.value = C1[j].value;
	C1[j].mark = C1[j-1].mark;
	C1[j].value = C1[j-1].value;
	C1[j-1].mark = tmp.mark;
	C1[j-1].value = tmp.value;
      }
    }
  }

  for (i = 0; i < N; i++) {
    if (i != N - 1) printf("%c%d ", C1[i].mark, C1[i].value);
    else printf("%c%d\n", C1[i].mark, C1[i].value);
  }
  if (stable == 1) printf("Stable\n");
  else printf("Not stable\n");

  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (C2[j].value < C2[minj].value) minj = j;
    }
    if (i != minj) {
      tmp.mark = C2[i].mark;
      tmp.value = C2[i].value;
      C2[i].mark = C2[minj].mark;
      C2[i].value = C2[minj].value;
      C2[minj].mark = tmp.mark;
      C2[minj].value = tmp.value;
    }
  }

  stable = 1;
  for (i = 1; i <= 9; i++) {
    order = 0;
    for (j = 0; j < N; j++) {
      if (C[j].value == i) m[order++] = C[j].mark;
    }
    order = 0;
    for (j = 0; j < N; j++) {
      if (C2[j].value == i) {
	if (C2[j].mark != m[order]) {
	  stable = 0;
	  break;
	}
	order++;
      }
    }
    if (stable == 0) break;
  }

  for (i = 0; i < N; i++) {
    if (i != N - 1) printf("%c%d ", C2[i].mark, C2[i].value);
    else printf("%c%d\n", C2[i].mark, C2[i].value);
  }
  if (stable == 1) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}