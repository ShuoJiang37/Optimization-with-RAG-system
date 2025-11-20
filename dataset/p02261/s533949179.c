#include<stdio.h>
#include<string.h>

struct Card{
   char suit;
   char value;
};

int main()
{
   struct Card C1[101], C2[101], temp;
   int N, i, j, minj, flag = 0;
   char ch;

   scanf("%d%c", &N, &ch);
   for (i=0; i<N; i++){
      scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
      C2[i].suit = C1[i].suit;
      C2[i].value = C1[i].value;
   }


   for (i=0; i<N-1; i++){
      for (j=N-1; j>=i+1; j--){
         if (C1[j].value<C1[j-1].value){
            temp = C1[j];
            C1[j] = C1[j-1];
            C1[j-1] = temp;
         }
      }
   }

   for (i=0; i<N; i++){
      if (i>0)
         printf(" ");
      printf("%c%c", C1[i].suit, C1[i].value);
   }
   printf("\n");

   puts("Stable");


   for (i=0; i<N; i++){
      minj = i;
      for (j=i; j<N; j++){
         if (C2[j].value<C2[minj].value)
            minj = j;
      }
      temp = C2[minj];
      C2[minj] = C2[i];
      C2[i] = temp;
   }

   for (i=0; i<N; i++){
      if (i>0)
         printf(" ");
      printf("%c%c", C2[i].suit, C2[i].value);
   }
   printf("\n");

   for (i=0; i<N; i++){
      if (C1[i].suit != C2[i].suit){
         puts("Not stable");
         flag = 1;
         break;
      }
   }
   if (flag==0)
      puts("Stable");

   return 0;
}