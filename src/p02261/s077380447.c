#include <stdio.h>



typedef struct {
	char moji;
	int num;
	int id;
}Card;

void Bubblesort(Card tramp[], int N);
void Selectionsort(Card tramp[], int N);
void Trampprintf(Card tramp[], int N);
void Stablehantei(Card tramp[], int N);

int main(void) {
	int N, i;

	Card tramp1[36]; //tramp1がBubblesort用。tramp2がselectionsort用。
	Card tramp2[36];

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf(" %c", &tramp1[i].moji);
		scanf(" %d",  &tramp1[i].num);
		tramp1[i].id = i;
		tramp2[i] = tramp1[i];
	}

	Bubblesort(tramp1, N);
	Trampprintf(tramp1, N);
	Stablehantei(tramp1, N);

	Selectionsort(tramp2, N);
	Trampprintf(tramp2, N);
	Stablehantei(tramp2, N);

		return 0;
}

void Stablehantei(Card tramp[], int N) {
	int i;
	int hantei=1;
	for (i = 1; i<N; i++) {
		if (tramp[i].num == tramp[i + 1].num&&tramp[i].id>tramp[i + 1].id) {
			hantei = 0;
		}
	}
	if (hantei == 0) {
		printf("Not stable\n");
	}else printf("Stable\n");
}



void Bubblesort(Card tramp[], int N){
	int i;
	Card tmp;
	int flag = 1;

	while (flag) {
		flag = 0;
		for (i = 1; i<N; i++) {
			if (tramp[i].num>tramp[i + 1].num) {
				tmp= tramp[i];
				tramp[i] = tramp[i + 1];
				tramp[i + 1] = tmp;
				
				flag = 1;
			}
		}
	}

}


void Selectionsort(Card tramp[], int N) {
	int i, m, min, ichi;
	Card tmp;


	for (m = 1; m<N; m++) {
		min = m; //最小値を最初は先頭にする。最小値が入っている配列の番号を記憶。
		for (i = m + 1; i <= N; i++) {
			if (tramp[i].num<tramp[min].num) {
				min = i; //最小値があった場所を更新
			}
		}
		tmp = tramp[m];
		tramp[m]= tramp[min];
		tramp[min]= tmp;
	}

}

void Trampprintf(Card tramp[], int N) {
	int i;
	for (i = 1; i <= N; i++) {
		if (i != N) {
			printf("%c%d ", tramp[i].moji, tramp[i].num);
		}
		else {
			printf("%c%d\n", tramp[i].moji, tramp[i].num);
		}

	}
}
