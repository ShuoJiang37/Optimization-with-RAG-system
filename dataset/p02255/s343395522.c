
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, num, key;
	int *A;
	
	scanf("%d", &num);
	A = (int*)malloc(num * sizeof(int));
	if (NULL == A) {
		return 1;
	}
	
	for (i = 0; i < num; i++) {
		scanf("%d", &A[i]);
		if (i != num -1) {
			printf("%d ", A[i]);
		}
		else {
			printf("%d\n", A[i]);
		}
	}
	
	for (i = 1; i < num; i++) {
        key = A[i];
        for (j = i - 1; j >= 0 && A[j] > key; j--) {
			A[j+1] = A[j];
        }
		A[j+1]=key;
        for (j = 0; j < num; j++) {
			if (j != num -1) {
				printf("%d ", A[j]);
			}
			else {
				printf("%d\n", A[j]);
			}
		}
    }
	
  return 0;
}

	

