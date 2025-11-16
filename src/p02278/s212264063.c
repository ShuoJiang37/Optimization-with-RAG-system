#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

#define WMAX 10000

int n , allmin ,*arr ,*sortarr ,*nextarr;
bool *booarr;
int part ( int [],int ,int);
void quickSort( int [],int ,int);

int main(){
	scanf("%d",&n);
	arr = malloc (n * sizeof(int));
	sortarr = malloc (n * sizeof(int));
	nextarr = malloc (WMAX * sizeof(int));
	booarr = malloc (n * sizeof(bool));
	allmin = INT_MAX;
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		sortarr[i] = arr[i];
		allmin = allmin < arr[i] ? allmin : arr[i];
		booarr[i] = false;
	}
	
	int outp =0;
	quickSort(sortarr, 0,n-1);
	makeNextArr();
	
	for(int i= 0 ; i <n ; i++)
	{
	if(booarr[i] == true){continue;}
	int csum = 0 ,cn =0 , cmin = INT_MAX , nowi = i ;
	do	{
	booarr[nowi] = true;
	csum += arr[nowi];
	cn++;
	cmin = cmin < arr[nowi] ? cmin : arr[nowi];
	nowi = nextarr[arr[nowi]];
	}while(booarr[nowi] == false);

	int incr = (cn - 2) * cmin + csum;
	int lent = cmin + (cn + 1) * allmin + csum;	
	outp += incr < lent ? incr : lent;

	}
	
	printf("%d\n",outp);
	return 0;
}

void makeNextArr()
{
	for( int i = 0 ; i < n;i++ ){
		nextarr[sortarr[i]] = i;
	}
}

void quickSort( int a[],int p,int r){
  if ( p < r){
    int q = part(a , p ,r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
  }
}

int  part (int a[] ,int p ,int r){
  int x = a[r] ,t ;
  int j, i = p-1;
  for ( j = p ; j < r ; j++ ){
    if ( a[j]  <= x){
      i++;
      t = a[i]; a[i] = a[j]; a[j] =t;
    }
  }
  t = a[i+1]; a[i+1] = a[r] ; a[r]=t;
  return i+1;
}

