#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// the number of total comparisons
int comparisons = 0;

// merge merges the A from left to mid and mid to right assuming that those sublists are already sorted.
void merge(int *A, int left, int mid, int right)
{
  int i;
  // allocate arrays to hold the two sorted sections to merge
  int *leftArray = (int *) malloc((mid-left+1)*sizeof(int));
  int *rightArray = (int *) malloc((right-mid+1)*sizeof(int));
  // assign the proper values to the subarrays
  for ( i = 0; i < mid-left; i++ )
    leftArray[i] = A[left+i];
  for ( i = 0; i < right-mid; i++ )
    rightArray[i] = A[mid+i];
  leftArray[mid-left] = INT_MAX;
  rightArray[right-mid] = INT_MAX;
  // merge the subarrays
  int j = 0, k = 0;
  for ( i = left; i < right; i++ )
    {
      comparisons++;
      if ( leftArray[j] <= rightArray[k] )
	A[i] = leftArray[j++];
      else
	A[i] = rightArray[k++];
    }
  return;
}

// mergeSort sorts the array A from left to right in ascending order.
void mergeSort(int *A, int left, int right)
{
  if ( left+1 < right )
    {
      int mid = (left + right)/2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }
  return;
}

int main()
{
  int length, *A, i;
  scanf(" %d", &length);
  A = (int *) malloc(length*sizeof(int));
  for ( i = 0; i < length; i++ )
    scanf(" %d", A+i);
  mergeSort(A, 0, length);
  for ( i = 0; i < length; i++ )
    printf("%d%c", A[i], i == length-1 ? '\n' : ' ');
  printf("%d\n", comparisons);
  return 0;
}

