#include <stdio.h>
typedef struct{
  int num;
  char mk; 
} C;

int isStable(C in[],C out[]);
int n;

int main()
{
  int i,j,minj;
  C N[36],M[36],temp;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&N[i].mk,&N[i].num);
    M[i]=N[i];
  }

  //BubbleSort
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(N[j].num<N[j-1].num){
	temp=N[j];
	N[j]=N[j-1];
	N[j-1]=temp; 
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%c%d ",N[i].mk,N[i].num);
  printf("%c%d\n",N[n-1].mk,N[n-1].num);

  if(isStable(M,N)) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++) N[i]=M[i];

  //SelectionSort
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(N[j].num<N[minj].num) minj=j;
    }
    temp=N[i];
    N[i]=N[minj];
    N[minj]=temp;
  } 
  for(i=0;i<n-1;i++) printf("%c%d ",N[i].mk,N[i].num);
  printf("%c%d\n",N[n-1].mk,N[n-1].num);
  
  if(isStable(M,N)) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

int isStable(C in[],C out[]){
  int i,j,a,b;

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(in[i].num==in[j].num && in[i].mk==out[b].mk && in[j].mk==out[a].mk){
	    if(in[i].num==out[b].num && in[j].num==out[a].num) return 0;
	  }
	}
      }
    }
  }
  return 1;
}