  #include <stdio.h>
  #define N 100

  typedef struct{
    char a;
    char value;
  }Card_t;

  void bubble(Card_t A[],int v){
    int i,j;
    Card_t t;
    for(i=0;i<v;i++){
      for(j=v-1;j>=i;j--){
        if(A[j].value < A[j-1].value){
          t=A[j];
          A[j]=A[j-1];
          A[j-1]=t;
        }
      }
    }
  }

  void selection(Card_t A[],int v){
    int i,j;
    int minj;
    Card_t t;
    for(i=0;i<v;i++){
      minj=i;
      for(j=i;j<v;j++){
        if(A[j].value<A[minj].value){
          minj=j;
        }
      }
        t=A[i];
        A[i]=A[minj];
        A[minj]=t;
      }
    }

  int isStable(Card_t C1[],Card_t C2[],int v){
   int i;
   for(i=0;i<v;i++){
     if(C1[i].a != C2[i].a) return 0; //false
   }
   return 1; //true
  }

  int main(){
    Card_t C1[N],C2[N];
    int v,i,j;
    char S[3];

    scanf("%d",&v);
    for(i=0;i<v;i++){
      scanf("%s",S);
      C1[i].a=S[0];
      C1[i].value=S[1];
    }

    for(i=0;i<v;i++){
      C2[i]=C1[i];
    }

    bubble(C1,v);
    selection(C2,v);
    for(i=0;i<v;i++){
      if(i>0) printf(" ");
      S[0]=C1[i].a;
      S[1]=C1[i].value;
      printf("%s",S);
    }
    printf("\n");
    printf("Stable\n");

    for(i=0;i<v;i++){
      if(i>0) printf(" ");
      S[0]=C2[i].a;
      S[1]=C2[i].value;
      printf("%s",S);
    }
    printf("\n");
    if(isStable(C1,C2,v)==1) {
      printf("Stable\n");
    } else {
      printf("Not stable\n");
    }
    return 0;
  }