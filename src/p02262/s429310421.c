#include<stdio.h>
#define N 1000000

typedef long int ll;

ll cnt = 0;

void InsertionSort(int A[], const int n, const int g);
void ShellSort(int [], int);

int main()
{
  int i;
  int n;
  int A[N+1];
  
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }

  ShellSort(A,n);

  printf("%ld\n",cnt);
  
  for(i = 0;i < n;i++){
    printf("%d\n",A[i]);
  }
}

void InsertionSort(int A[], const int n, const int g) // from 1 to g
{
  int i=0,j=0;
  int key;

  for(i = g;i < n;i++){
    key = A[i];
    j = i-g;
    
    while(j >= 0 && A[j] > key){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = key;
  }
}

void ShellSort(int A[], int n)
{
  int i=0;
  int h = 0;
  int G[101];
  
  cnt = 0;
  
  while(h <= n){
    h = 3*h+1;
    G[i] = h;
    i++;
  }
  int m = i-1;

  printf("%d\n",m);
  for(i = 0;i < m;i++){
    if(i) printf(" ");
    printf("%d",G[m-1-i]);
  }
  printf("\n");
  
  for(i = 0;i < m;i++){
    InsertionSort(A,n,G[m-1-i]);
  }
}

