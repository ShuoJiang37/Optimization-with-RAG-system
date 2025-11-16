#include<stdio.h>
#include<string.h>

typedef struct{
  char chr;
  int num;
}card;

void BubbleSort(card A[], int N);
void SelectionSort(card A[], int N);



int main(void){
  int n,i,cnt;
	scanf("%d",&n);

	card A[n],B[n];

	for(i=0;i<n;i++){
		scanf(" %c%d",&A[i].chr,&A[i].num);
    B[i]=A[i];
	}

  BubbleSort(A,n);
  SelectionSort(B,n);

  for(i=0;i<n;i++){
    if(A[i].chr!=B[i].chr){
      printf("Not stable\n");
      break;
    }
    if(i==n-1){
      printf("Stable\n");
    }
  }

  return 0;
}

void BubbleSort(card A[], int N){

  int j,i,cnt=0;
  card jump;

  for(j=0;j<N-1;j++){
    for(i=N-1;i>j;i--){
      if(A[i].num<A[i-1].num){
        jump=A[i];
        A[i]=A[i-1];
        A[i-1]=jump;
        cnt++;
      }
    }
  }

  for(i=0;i<N-1;i++){
		printf("%c%d ",A[i].chr,A[i].num);
	}
  printf("%c%d\n",A[i].chr,A[i].num);
  printf("Stable\n");

}

void SelectionSort(card A[], int N){

  int min,i,j,cnt=0;
  card jump;

  for(i=0;i<N;i++){
    min=i;
    for(j=i;j<N;j++){
      if(A[min].num>A[j].num){
        min=j;
      }
    }
    if(i!=min){
      jump=A[i];
      A[i]=A[min];
      A[min]=jump;
      cnt++;
    }
  }
  for(i=0;i<N-1;i++){
		printf("%c%d ",A[i].chr,A[i].num);
	}
  printf("%c%d\n",A[i].chr,A[i].num);
}

