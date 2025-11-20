#include<stdio.h>
#include<string.h>

//構造体の宣言
typedef struct Card{
	char mark;	//絵柄
	int value;	//数字
}Card;

int main(){
	int N;	//カードの枚数
	int flag = 1;		//フラグ
	int stbflag = 1;	//安定な出力か調べるためのフラグ
	Card s;				//ソート用変数
	int index = 0;		//未ソート部分の先頭インデックス
	int minj;			//最小値の位置（選択ソート用）
	
	//要素数の入力
	scanf("%d%*c",&N);
	
	Card Ab[N];	//バブルソート用の配列
	Card As[N];	//選択ソート用の配列
	
	//まずはバブルソート用の配列へ入力
	for(int i = 0;i < N;i++){
		scanf("%c%d%*c",&Ab[i].mark,&Ab[i].value);
	}
	
	//それを選択ソート用の配列へコピー
	memcpy(As,Ab,sizeof(Ab));
	
	//バブルソート
	while(flag){
		flag = 0;
		for(int j = N - 1;j >= index + 1;j--){
			
			if(Ab[j].value < Ab[j - 1].value){
				//交換
				s = Ab[j];
				Ab[j] = Ab[j - 1];
				Ab[j - 1] = s;
				//フラグ処理
				flag = 1;
			}
		}
		//インデックスを後ろにずらす
		index++;
	}
	
	//配列の出力
	for(int i = 0;i < N;i++){
		if(i == N - 1){
			printf("%c%d\n",Ab[i].mark,Ab[i].value);
		}
		else{
			printf("%c%d ",Ab[i].mark,Ab[i].value);
		}
	}
	
	printf("Stable\n");
	
	//選択ソート
	for(int i = 0;i < N;i++){
		//最小値の位置を初期化
		minj = i;
		
		//minjから最後までの最小値の位置を求める
		for(int j = i;j < N;j++){
			if(As[j].value < As[minj].value){
				minj = j;
			}
		}
		//交換が行われるとき
		if(minj != i){
			//交換
			s = As[i];
			As[i] = As[minj];
			As[minj] = s;
		}
	}
	
	//配列の出力
	for(int i = 0;i < N;i++){
		if(i == N - 1){
			printf("%c%d\n",As[i].mark,As[i].value);
		}
		else{
			printf("%c%d ",As[i].mark,As[i].value);
		}
		
		//バブルソートと照合する
		if(!(Ab[i].mark == As[i].mark && Ab[i].value == As[i].value)){
			stbflag = 0;
		}
	}
	
	//安定な出力だった場合
	if(stbflag){
		printf("Stable\n");
	}
	//そうでなかった場合
	else{
		printf("Not stable\n");
	}
	
	return 0;
}

