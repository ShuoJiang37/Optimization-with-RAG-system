#include<stdio.h>
#define N 1000000

/*????????????????????£?¨?*/
void insertionSort(int [],int,int);
void shellSort(int [],int);

/*??°????????????*/
int cnt =0;


/*main??¢??°*/
int main(){

  int A[N],i,num;
  scanf("%d",&num);

  for(i=0;i<num;i++) scanf("%d",&A[i]);
  shellSort(A,num);
  printf("%d\n",cnt);
  for(i=0;i<num;i++) printf("%d\n",A[i]);

  return 0;
}

/*?????§????????????*/
void shellSort(int A[],int n){
  int i=0,m=0;
  int G[n];

  G[0]=0;
  for(i=0;i<n;i++){
      G[i+1] = 3*G[i]+1;
      m++;
      if(G[i+1]>n)break;
  }
  while(1){
    if(G[m]>N)m--;
    else m--; break;
     }

  if(m==0)m=1;

  printf("%d\n",m);
  for(i=m;i>1;i--)printf("%d ",G[i]);
  printf("%d\n",G[1]);
  for(i=m;i>=0;i--){
    insertionSort(A,n,G[i]);
  }
}

/*sort*/
void insertionSort(int A[],int n, int g){

  int i,j,v;
  for(i=g;i<=n-1;i++){
    v = A[i];
    j=i-g;
    while(j>=0 && A[j]>v){

      A[j+g] = A[j];
      j=j-g;
      cnt++;
    }
    A[j+g] = v;
  }
}