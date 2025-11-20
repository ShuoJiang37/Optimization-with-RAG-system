
#include <stdio.h>

void output_array( int* array, int num)
{
	int i;
	for (i = 0; i < num-1; i++)
	{
		printf("%d ", array[i]);
	}
	printf("%d\n", array[i]);
	return;
}


int main(void) 
{
	int N;
	int array[100];
	int i, j;
	int tmp;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}
	
	output_array(array, N);
	
	for (i = 1; i < N; i++)
	{
		tmp = array[i];
		for (j = i-1; j >= 0 && array[j] > tmp; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = tmp;
		output_array(array, N);
	}
	return 0;
}

