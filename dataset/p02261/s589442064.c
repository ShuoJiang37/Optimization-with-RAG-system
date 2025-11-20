#include <stdio.h>

//問題文より、入力されるデータの最大個数
#define MAXCOUNT 36

//バブルソート
void bubble_sort(int card_num[MAXCOUNT], char card_mark[MAXCOUNT], int size);
//選択ソート
void selection_sort(int card_num[MAXCOUNT], char card_mark[MAXCOUNT], int size);
//ソートの結果が安定であるか確かめる
int check_stable(int card_num[MAXCOUNT], char card_mark[MAXCOUNT], int base_card_num[MAXCOUNT], char base_card_mark[MAXCOUNT], int size);

int main(void)
{
	int i, n;
	/*
	card_numにはカードの数字を、card_markにはカードのマークを格納
	また、変数の先頭にinputとつくものは入力されたデータを、
	bubbleとつくものはバブルソートの結果を、
	selectionとつくものは選択ソートの結果を格納
	*/
	int input_card_num[MAXCOUNT], bubble_card_num[MAXCOUNT], selection_card_num[MAXCOUNT];
	char input_card_mark[MAXCOUNT], bubble_card_mark[MAXCOUNT], selection_card_mark[MAXCOUNT];

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		//データを入力
		scanf("%*c%c%d", &input_card_mark[i], &input_card_num[i]);

		//各ソート用の配列にデータをコピーする
		bubble_card_mark[i] = selection_card_mark[i] = input_card_mark[i];
		bubble_card_num[i] = selection_card_num[i] = input_card_num[i];
	}

	bubble_sort(bubble_card_num, bubble_card_mark, n);
	//バブルソートの結果を表示
	for(i = 0; i < (n - 1); i++){
		printf("%c%d ", bubble_card_mark[i], bubble_card_num[i]);
	}
	printf("%c%d\n", bubble_card_mark[i], bubble_card_num[i]);

	//安定した出力であるか表示
	if(check_stable(bubble_card_num, bubble_card_mark, input_card_num, input_card_mark, n)){
		printf("Stable\n");
	}
	else{
		printf("Not stable\n");
	}

	selection_sort(selection_card_num, selection_card_mark, n);
	//選択ソートの結果を表示
	for(i = 0; i < (n - 1); i++){
		printf("%c%d ", selection_card_mark[i], selection_card_num[i]);
	}
	printf("%c%d\n", selection_card_mark[i], selection_card_num[i]);

	//安定した出力であるか表示
	if(check_stable(selection_card_num, selection_card_mark, input_card_num, input_card_mark, n)){
		printf("Stable\n");
	}
	else{
		printf("Not stable\n");
	}

	return 0;
}

void bubble_sort(int card_num[MAXCOUNT], char card_mark[MAXCOUNT], int size)
{
	//i,jは繰り返し変数、num_temp,mark_tempは交換用の変数
	int i, j, num_temp;
	char mark_temp;

	//配列の終端の一つ前まで走査
	for(i = 0; i < size; i++){
		//小さい値から確定していく
		for(j = (size - 1); j > i; j--){
			//昇順に並び替える
			if(card_num[j - 1] > card_num[j]){
				//数字
				num_temp = card_num[j - 1];
				card_num[j - 1] = card_num[j];
				card_num[j] = num_temp;

				//マーク
				mark_temp = card_mark[j - 1];
				card_mark[j - 1] = card_mark[j];
				card_mark[j] = mark_temp;
			}
		}
	}
}

void selection_sort(int card_num[MAXCOUNT], char card_mark[MAXCOUNT], int size)
{
	//i,jは繰り返し変数、min_indexは交換先のデータを表す添字、num_temp,mark_tempは交換用の変数
	int i, j, min_index, num_temp;
	char mark_temp;

	//配列の終端の一つ前まで走査
	for(i = 0; i < (size - 1); i++){
		min_index = i;
		//比較元の一つ後ろから比較開始
		for(j = (i + 1); j < size; j++){
			//小さい値から確定する
			if(card_num[j] < card_num[min_index]){
				min_index = j;
			}
		}
		//昇順に並び替える
		if(min_index != i){
			//数字
			num_temp = card_num[min_index];
			card_num[min_index] = card_num[i];
			card_num[i] = num_temp;

			//マーク
			mark_temp = card_mark[min_index];
			card_mark[min_index] = card_mark[i];
			card_mark[i] = mark_temp;
		}
	}
}

int check_stable(int card_num[MAXCOUNT], char card_mark[MAXCOUNT], int base_card_num[MAXCOUNT], char base_card_mark[MAXCOUNT], int size)
{
	//flagが1ならば安定した出力と返す
	int i, j, flag;

	flag = 1;
	for(i = 0; i < size; i++){
		//安定した出力でないと確定した場合はループから抜ける
		if(!flag){
			break;
		}

		for(j = 0; j < size; j++){
			//カードの数字が同じである添字を探す
			if(card_num[i] == base_card_num[j]){
				//ソート前後で出現順が一致している
				if(card_mark[i] == base_card_mark[j]){
					//同じ数字が続いていれば続きから走査する
					if(card_num[i] == card_num[i + 1]){
						i++;
					}
					else{
						break;
					}
				}
				//マークが不一致ならば出力が不安定
				else{
					flag = 0;
					break;
				}
			}
		}
	}

	return flag;
}
