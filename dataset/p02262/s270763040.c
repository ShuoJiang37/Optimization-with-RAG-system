#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int32_t sSwapCnt = 0;

void InsertionSortForShellSort(int32_t arr[], int32_t len, int32_t g) {
	for (int32_t i = g; i < len; i++) {
		int32_t target = arr[i];
		int32_t j = i - g;
		for (; j >= 0 && arr[j] > target; j -= g) {
			arr[j+g] = arr[j];
			sSwapCnt++;
		}
		arr[j+g] = target;
	}
}

void ShellSort(int32_t arr[], int32_t len) {
	// Gを生成
	int32_t g[20] = {0};	// int32_tの最大値2147483647を考慮
	int32_t sum = 1;
	int32_t i = 0;
	while (sum <= len && i < 20) {
		g[i] = sum;
		sum = sum * 3 + 1;
		i++;
	}

	// Gの個数・内容を出力
	printf("%d\n", i);

	int32_t lastI = i - 1;
	printf("%d", g[lastI]);
	for (int32_t j = lastI - 1; j >= 0; j--) {
		printf(" %d", g[j]);
	}
	putchar('\n');

	// Gを用いてソート
	for (int32_t j = lastI; j >= 0; j--) {
		InsertionSortForShellSort(arr, len, g[j]);
	}
	printf("%d\n", sSwapCnt);
}

int main() {
	int32_t dataNum;
	scanf("%d", &dataNum);

	int32_t *data = (int32_t *)calloc(dataNum, sizeof(int32_t));
	if (!data) return 1;

	for (int32_t i = 0; i < dataNum; i++) {
		scanf("%d", &data[i]);
	}
	
	ShellSort(data, dataNum);

	for (int32_t i = 0; i < dataNum; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}

