    #include <stdio.h>
    #define TRUE 1
    #define FALSE 0

    struct Card{
      char suit, value;
    };

    void bubble(struct Card A[], int N){
      int i,j;
      struct Card tmp;
      for(i = 0; i < N; i++){
        for(j = N-1; j >= i+1; j--){
          if(A[j].value < A[j-1].value){
            tmp = A[j];
            A[j] = A[j-1];
            A[j-1] = tmp;
          }
        }
      }
    }

    void selection(struct Card A[], int N){
      int i,j;
      int min;
      for(i = 0; i < N; i++){
        min = i;
        for(j = i; j < N; j++){
          if(A[j].value < A[min].value)
            min = j;
        }
        struct Card tmp = A[i];
        A[i] = A[min];
          A[min] = tmp;
      }
    }

    void print(struct Card A[], int N){
      int i;

      for(i = 0; i < N; i++){
        if(i > 0)
          printf(" ");
        printf("%c%c",A[i].suit,A[i].value);
      }

      printf("\n");
    }

    int isStable(struct Card C1[],struct Card C2[], int N){
      int i;

      for(i = 0; i < N; i++){
        if(C1[i].suit != C2[i].suit)
          return FALSE;
      }

      return TRUE;
    }

    int main(){

      int i,n;

      struct Card C1[100], C2[100];


      scanf("%d",&n);

      for(i = 0; i < n; i++){
        scanf("%1s%1s",&C1[i].suit,&C1[i].value);
      }

      for(i = 0; i < n; i++)
        C2[i] = C1[i];

      bubble(C1,n);

      selection(C2, n);

      print(C1, n);

      printf("Stable\n");

      print(C2,n);

      if(isStable(C1,C2,n) == TRUE){
        printf("Stable\n");
      }

      else
        printf("Not stable\n");

      return 0;
    }

