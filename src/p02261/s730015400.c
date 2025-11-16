#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 36
typedef struct{
  char gara;
  int number;
}card;
void Swap(card*x,card*y){
  card temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
void bubble(card *after,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(after[j].number<after[j-1].number){
	Swap(&after[j],&after[j-1]);
      }
    }
  }
}
void Select(card *after,int n){
  int i,j,minj;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(after[j].number<after[minj].number){
	minj=j;
      }
    }
    if(minj!=i){
      Swap(&after[i],&after[minj]);
    }
  }
}
		       
int isstable(card*x,card*y,int n){
  int i,j,a,b;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(x[i].number==x[j].number&&memcmp(&x[i],&y[b],sizeof(card))==0&&memcmp(&x[j],&y[a],sizeof(card))==0)
	    return -1;
	}
      }
    }
  }
  return 0;
}
int main(){
  card A[N],*after1,*after2;
  int i,j,n,judge1,judge2;
  scanf("%d",&n);
  after1=(card *)malloc(n*(sizeof(card)));
  after2=(card *)malloc(n*(sizeof(card)));
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].gara,&A[i].number);
  }
  for(i=0;i<n;i++){
    after1[i]=A[i];
  }
  for(i=0;i<n;i++){
    after2[i]=A[i];
  }
  bubble(after1,n);
  Select(after2,n);
  judge1=isstable(A,after1,n);
  judge2=isstable(A,after2,n);
  for(i=0;i<n;i++){
    printf("%c%d",after1[i].gara,after1[i].number);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  if(judge1==0){
    printf("Stable\n");
  }
  if(judge1==-1){
    printf("Not stable\n");
  }
  for(i=0;i<n;i++){
    printf("%c%d",after2[i].gara,after2[i].number);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  if(judge2==0){
    printf("Stable\n");
  }
  if(judge2==-1){
    printf("Not stable\n");
  }
  free(after1);
  free(after2);
  return 0;
}