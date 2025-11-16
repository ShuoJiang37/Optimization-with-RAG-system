#include <stdio.h>

#define MAXCOUNT 1000000
#define MAXINTERVAL 100

//一定の間隔の要素を並び替える
int insertion_sort(int array[MAXCOUNT], int size, int interval);

int main(void)
{
	//sizeは入力されるデータの個数、order_countはソートで計算した回数、interval_countはinsertion_sortを呼び出す回数
	int i, size, order_count, interval_count;
	//intervalは並び替える要素の間隔を格納
	int interval[MAXINTERVAL];
	static int array[MAXCOUNT];

	scanf("%d", &size);

	interval_count = 0;
	//最終的に間隔は1となる
	interval[0] = 1;
	//データの入力と間隔を設定
	for(i = 0; i < size; i++){
		scanf("%d", &array[i]);

		if(((3 * interval[interval_count] + 1) <= size)){
			interval[interval_count + 1] = 3 * interval[interval_count] + 1;
			interval_count++;
		}
	}

	//挿入ソートを呼び出し要素を並び替える
	order_count = 0;
	for(i = interval_count; i >= 0; i--){
		order_count += insertion_sort(array, size, interval[i]);
	}

	//挿入ソートを呼び出した回数を表示
	printf("%d\n", interval_count + 1);
	//並び替えた要素の間隔を表示
	for(i = interval_count; i > 0; i--){
		printf("%d ", interval[i]);
	}
	printf("%d\n", interval[i]);

	//計算した回数を表示
	printf("%d\n", order_count);

	//並び替えた結果を表示
	for(i = 0; i < size; i++){
		printf("%d\n", array[i]);
	}

	return 0;
}

int insertion_sort(int array[MAXCOUNT], int size, int interval)
{
	//i、jは繰り返し変数、countは計算回数を、tempは挿入するデータを格納
	int i, j, count, temp;

	count = 0;
	for(i = interval; i < size; i++){
		//コピーを取る
		temp = array[i];
		j = i - interval;
		while(j >= 0 && array[j] > temp){
			//データをずらす
			array[j + interval] = array[j];
			j -= interval;
			count++;
		}
		array[j + interval] = temp;
	}

	return count;
}
