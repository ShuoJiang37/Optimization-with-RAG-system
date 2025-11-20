struct tranp{
  char gara;
  int atai;
};

void bbsort(struct tranp C[], int);
void selsort(struct tranp C[], int);
void pr(struct tranp C[], int);


int main(){
  int i=0,j=0;
  struct tranp C[100];
  struct tranp CC[100];
  int N=0;
  int count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C[i].gara,&C[i].atai);
  }
  for(i=0;i<N;i++){
      CC[i]=C[i];
  }
  bbsort(C,N);
  selsort(CC,N);
  pr(C,N);
  printf("Stable\n");
  pr(CC,N);
  for(i=0;i<N;i++){
    if(C[i].gara!=CC[i].gara){
      printf("Not stable\n");
      break;
    }
  }
  if(i==N)printf("Stable\n");
  return 0;
}
void bbsort(struct tranp A[],int N){
  int i=0,j=0;
  struct tranp temp;
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j].atai<A[j-1].atai){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
      }
    }
  }
}
void selsort(struct tranp A[], int N){
  int i=0,j=0;
  struct tranp temp;
  int min=0;
  for(i=0;i<=N-1;i++){
    min=i;
    for(j=i;j<=N-1;j++){
      if(A[j].atai<A[min].atai){
	min=j;
      }
    }
    temp=A[i];
    A[i]=A[min];
    A[min]=temp;
  }
}
void pr(struct tranp A[],int N){
  int i=0;
  if(N>1){
    for(i=0;i<N;i++){
      if(i<N-1){
	printf("%c%d ",A[i].gara,A[i].atai);
      }
      if(i==N-1){
	printf("%c%d",A[i].gara,A[i].atai);
      }
    }
    printf("\n");
  }
  else {
    for(i=0;i<N;i++){
      printf("%c%d",A[i].gara,A[i].atai);
    }
    printf("\n");
    }
 
  /*
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%c%d",A[i].gara,A[i].atai);
  }
  printf("\n"); */  
}

