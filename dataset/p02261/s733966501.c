#include <stdio.h>

int main(void)
{
	int n,i,j;
	char s;
	scanf("%d\n",&n);
	char array_b[n*3],array_s1[n*3],array_s2[n*3];
	for (i = 0;i < n * 3;i++) {
		scanf("%c",&array_b[i]);
		array_s1[i] = array_b[i];
		array_s2[i] = array_s1[i];
	}

  /* bubble_sort */
	for (j = 0;j < n;j++) {
		for (i = 1;i < n * 3 - 2;i+=3) {
			if (array_b[i+3] < array_b[i]) {
				/* change letter */
				s = array_b[i+2];
				array_b[i+2] = array_b[i-1];
				array_b[i-1] = s;
				/* change nummber */
				s = array_b[i+3];
				array_b[i+3] = array_b[i];
				array_b[i] = s;
			}
		}
	}
	
	for (i = 0;i < n * 3 - 1;i++) {
		if (i == (n * 3 - 2))
			printf("%c\n",array_b[i]);
		else  printf("%c",array_b[i]);
	}
	printf("Stable\n");

  /* select_sort-v3 */
	for (j = 1;j < n * 3 - 2 ;j+=3) {

		for (i = j + 3;i < n * 3 - 2;i+=3) {
			if(array_s1[i+3] >= array_s1[i]) {
				array_s1[i+2] = array_s1[i-1];
				array_s1[i+3] = array_s1[i];
			}
		}

		if (array_s2[j] > array_s1[n*3-2]) {
			for (i = j + 3;i < n * 3 - 2;i+=3)
				if (array_s2[i] == array_s1[n*3-2])
					break;
			/* change letter */
			s = array_s2[j-1];
			array_s2[j-1] = array_s1[n*3-3];
			array_s2[i-1] = s;
			/* change number */
			s = array_s2[j];
			array_s2[j] = array_s1[n*3-2];
			array_s2[i] = s;
			for (i = j;i < n * 3;i+=3) {
				array_s1[i-1] = array_s2[i-1];
				array_s1[i] = array_s2[i];
			}
		} else {
			for (i = j + 3;i < n * 3 ;i+=3) {
				array_s1[i-1] = array_s2[i-1];
				array_s1[i] = array_s2[i];
			}
		}

	}
	
	for (i = 0;i < n * 3 - 1;i++) {
		if (i == n * 3 - 2)
			printf("%c\n",array_s2[i]);
		else printf("%c",array_s2[i]);
	}

  /* compare */
	for (i = 0;i < n * 3;i++) {
		if (array_s2[i] != array_b[i] ) {
			printf("Not stable\n");
			return 0;
		}
	}
	printf("Stable\n");
	return 0;
}
