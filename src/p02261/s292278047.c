#include <stdio.h>

struct CARD{
   char mark;
   int  number;
};

int BubbleSort(struct CARD B[], int b){
   int flag;
   int i;
   int s = 0;
   struct CARD v;

   flag = 1;
   while (flag) {
      flag = 0;
      for (i = b - 1; i > 0; --i) {
         if (B[i].number < B[i - 1].number) {
            v = B[i];
			B[i] = B[i - 1];
			B[i - 1] = v;
			s = s + 1;
			flag = 1;
         }
      }
   }
   return s;
}

int SelectionSort(struct CARD C[], int c) {
   int i, j, minj;
   int s = 0;
   struct CARD v;
   
   
   for (i = 0; i < c - 1; ++i) {
      minj = i;
	  for (j = i; j < c; ++j) {
		 if (C[j].number < C[minj].number)
			minj = j;
	  }
	  if (i != minj) {
		 v = C[i];
		 C[i] = C[minj];
		 C[minj] = v;
		 s = s + 1;
	  }
   }
   return s;
}

int main() { 
   struct CARD A[150], B[150], C[150];
   int i, j, n;
   int s, judge;
   char dummy;

   scanf("%d", &n);
   scanf("%c", &dummy);
   i = 0;
   while (i < n) {
      scanf("%c%d", &A[i].mark, &A[i].number);
	  scanf("%c", &dummy);
	  B[i] = A[i];
	  C[i] = A[i];
      i++;
   }
   s = BubbleSort(B, n);
   for (i = 0; i < n; ++i) {
	   printf("%c%d", B[i].mark, B[i].number);
	   if (i != n - 1)
		   putchar(' ');
   }
   putchar('\n');
   printf("Stable\n");

   s = SelectionSort(C, n);
   for (i = 0; i < n; ++i) {
	  printf("%c%d", C[i].mark, C[i].number);
	  if (i != n - 1)
		 putchar(' ');
   }
   putchar('\n');
   judge = 1;
   for (i = 0; i < n; ++i) {
	  if (B[i].number == C[i].number && B[i].mark != C[i].mark) {
		 judge = 0;
		 printf("Not stable\n");
		 break;
	  }
   }
   if (judge)
	  printf("Stable\n");
   return 0;
}