#include<stdio.h>

int main(){
	int N;			//要素数
	int count = 0;	//交換回数
	int s;			//ソート用変数
	int minj;		//未ソート部分の最小値の位置
	
	//要素数の入力
	scanf("%d",&N);
	
	int A[N];	//配列
	
	//配列の入力
	for(int i = 0;i < N;i++){
		scanf("%d",&A[i]);
	}
	
	for(int i = 0;i < N;i++){
		//最小値の位置を初期化
		minj = i;
		
		//minjから最後までの最小値の位置を求める
		for(int j = i;j < N;j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		//交換が行われるとき
		if(minj != i){
			//交換
			s = A[i];
			A[i] = A[minj];
			A[minj] = s;
			//交換をカウント
			count++;
		}
	}
	
	//配列の出力
	for(int i = 0;i < N;i++){
		if(i == N - 1){
			printf("%d\n",A[i]);
		}
		else{
			printf("%d ",A[i]);
		}
	}
	
	//交換回数の出力
	printf("%d\n",count);
	
	return 0;
}

