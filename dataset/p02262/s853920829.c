#include <stdio.h>


int main()
{
	int n, m;
	int h, h_bk;;
	int *box;
	int count;
	int i, j;


	scanf("%d", &n);

	box = (int *)malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
		scanf("%d", &box[i]);

	m = 0;
	for(h = 1; h <= n; h = h * 3 + 1)
		m++;
	h_bk = h / 3;

	count = 0;
	for(; h >= 1; h /= 3){
		for(i = h; i < n; i++){
			j = i;
			while(j >= h && box[j - h] > box[j]){
				box[j - h] ^= box[j];
				box[j] ^= box[j - h];
				box[j - h] ^= box[j];
				j -= h;
				count++;
			}
		}
	}


	printf("%d\n", m);

	// 間隔の数列を表示
	for(i = h_bk; i >= 1; i /= 3){
		printf("%d", i);
		if(i != 1)
			printf(" ");
		else
			printf("\n");
	}

	// 交換回数の表示
	printf("%d\n", count);;

	// 整列結果
	for(i = 0; i < n; i++){
		printf("%d\n", box[i]);
/*		if(i != n - 1)
			printf(" ");
		else
			printf("\n");
*/
	}
	
	return 0;
}
