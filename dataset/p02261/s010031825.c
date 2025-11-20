#include <stdio.h>
#include <string.h>


typedef struct{
	char gara;
	int num;
}CARD_T;

int main()
{
	char in_str[120];
	int N;
	int bk;
	char bk_c, *tp;
	CARD_T box[36], box2[36], bk_box;
	int min_pos, flag;
	int i, j;


	fgets(in_str, sizeof(in_str), stdin);
	sscanf(in_str, "%d", &N);

	fgets(in_str, sizeof(in_str), stdin);
	tp = strtok(in_str, " ");
	i = 0;
	sscanf(tp, "%c%d", &bk_c, &bk);
	box[i].gara = box2[i].gara = bk_c;
	box[i].num = box2[i].num = bk;
	while( tp = strtok(NULL, " ") ){
		i++;
		sscanf(tp, "%c%d", &bk_c, &bk );
		box[i].gara = box2[i].gara = bk_c;
		box[i].num = box2[i].num = bk;
	}

	// バブルソート
	for(i = 0; i < N - 1; i++){
		for(j = N - 1; j > i; j--){
			if(box[j - 1].num > box[j].num){
				bk_box = box[j - 1];
				box[j - 1] = box[j];
				box[j] = bk_box;
			}
		}
	}

	for(i = 0; i < N; i++){
		printf("%c%d", box[i].gara, box[i].num);
		if(i != N - 1)
			printf(" ");
		else
			printf("\n");
	}
	printf("Stable\n");


	// 選択ソート
	for(i = 0; i < N - 1; i++){
		min_pos = i;
		for(j = i + 1; j < N; j++){
			if(box2[j].num < box2[min_pos].num)
				min_pos = j;
		}
		if(i != min_pos){
			bk_box = box2[min_pos];
			box2[min_pos] = box2[i];
			box2[i] = bk_box;
		}
	}

	flag = 1;
	for(i = 0; i < N; i++){
		printf("%c%d", box2[i].gara, box2[i].num);
		if(flag == 1 && box[i].gara != box2[i].gara)
			flag = 0;
		if(i != N - 1)
			printf(" ");
		else
			printf("\n");
	}

	if(flag == 1)
		printf("Stable\n");
	else
		printf("Not stable\n");

	return 0;
}
