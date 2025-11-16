  #include<stdio.h>
   typedef struct {
    char mark;
    int value;
  } card;

  void swap(card * , card *);
  void SelectionSort(card * ,int N);
  void BubbleSort(card * , int N);



  int main() {
    int i,N,flag=1;

     while(1) {
      scanf("%d ",&N);
      if(1<=N && N<=36) break;
    }

     card  C1[100],C2[100];
    for(i=0;i<N;i++)  {
      scanf("%c%d ",&C1[i].mark , &C1[i].value);
        //printf("%c%d",C1[i].mark,C1[i].value);
      C2[i] = C1[i];
    }

    BubbleSort(C1,N);
    SelectionSort(C2,N);

    for(i=0;i<N;++i) {
      if(0 < i)printf(" ");
      printf("%c%d",C1[i].mark,C1[i].value);
    }
    printf("\n");
    printf("Stable\n");

    for(i=0;i<N;i++){
      if(0<i)printf(" ");
      printf("%c%d",C2[i].mark,C2[i].value);
      if(!(C2[i].mark == C1[i].mark && C2[i].value == C1[i].value))flag = 0;
    }
    printf("\n");
    if(flag) printf("Stable\n");
    else printf("Not stable\n");

    return 0;
  }

  void swap( card *a,   card *b)
  {
    card t;
    t = *a;
    *a  = *b;
    *b =t;
  }


   void BubbleSort(  card *C, int N)
   {
     int i,j;
     for(i=0;i < N-1;i++) {
       for(j =N-1;j>=i;j--) {
         if(C[j].value < C[j-1].value) swap(&C[j],&C[j-1]);
       }
     }
   }

  void SelectionSort( card *C, int N)
   {
     int i,j,minj;
     for(i=0;i<N;i++) {
       minj = i;
       for(j=i;j<N;j++){
         if(C[j].value < C[minj].value)minj =j;
       }
         swap( &C[i] , &C[minj]);
     }
   }