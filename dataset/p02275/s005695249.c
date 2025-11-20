#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int *countingSort(int *array, size_t length, int max)
{
  int i, *counts, *working;
  // allocate the counts array and working array
  counts = (int *) malloc((max+1)*sizeof(int));
  working = (int *) malloc(length*sizeof(int));
  // initialize all the counts to 0
  memset(counts, 0, max+1);
  // set the elements of counts array to the number of each element
  // in the input array
  for ( i = 0; i < length; i++ )
    counts[array[i]] += 1;
  // set the elements of counts array to the number of each element less
  // than or equal to it in the input array
  for ( i = 1; i <= max; i++ )
    counts[i] += counts[i-1];
  // set each element in the working array to the proper element
  // from the input array
  for ( i = 0; i < length; i++ )
    working[--counts[array[i]]] = array[i];
  // free all the arrays except the working array
  free(array);
  free(counts);
  return working;
}

int main()
{
  int max = INT_MIN, i, *array;
  size_t length;
  // get input
  scanf(" %lud", &length);
  array = (int *) malloc(length*sizeof(int));
  for ( i = 0; i < length; i++ )
    {
      scanf(" %d", array+i);
      // find k (the max value in array)
      if ( array[i] > max )
	max = array[i];
    }
  // countingSort the array
  array = countingSort(array, length, max);
  // print the array
  for ( i = 0; i < length; i++ )
    printf("%d%c", array[i], i == length-1 ? '\n' : ' ');
  free(array);
  return 0;
}

