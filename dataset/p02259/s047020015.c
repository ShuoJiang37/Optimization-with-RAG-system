#include<stdio.h>

int main(){
	int N;	//要素数
	int count = 0;	//入れ替えがあった回数
	int flag = 1;	//フラグ
	int s;			//ソート用変数
	int index = 0;	//未ソート部分の先頭インデックス
	
	//要素数の入力
	scanf("%d",&N);
	
	int A[N];	//配列
	
	for(int i = 0;i < N;i++){
		scanf("%d",&A[i]);
	}
	
	while(flag){
		flag = 0;
		for(int j = N - 1;j >= index + 1;j--){
			if(A[j] < A[j - 1]){
				s = A[j];
				A[j] = A[j - 1];
				A[j - 1] = s;
				
				flag = 1;
				count++;
			}
		}
		//インデックスを後ろにずらす
		index++;
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

