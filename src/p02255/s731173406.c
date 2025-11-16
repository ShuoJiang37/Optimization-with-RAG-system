#include<stdio.h>

int main(){
	int N;	//要素数
	
	scanf("%d",&N);
	
	int A[N];
	
	for(int i = 0;i < N;i++){
		scanf("%d",&A[i]);
	}
	
	//最初の出力（未ソートの状態）
	for(int i = 0;i < N;i++){
		//最後の数字は後ろにスペースなしで出力
		if(i == (N - 1)){
			printf("%d",A[i]);
		}
		//それ以外はスペースあり
		else{
			printf("%d ",A[i]);
		}
	}
	//改行
	printf("\n");
	
	for(int i = 1;i < N;i++){
		int v = A[i];
		int j = i - 1;
		
		while(j >= 0 && A[j] > v){
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = v;
		
		//ソートされた状態の出力
		for(int i = 0;i < N;i++){
			//最後の数字は後ろにスペースなしで出力
			if(i == (N - 1)){
				printf("%d",A[i]);
			}
			//それ以外はスペースあり
			else{
				printf("%d ",A[i]);
			}
		}
		//改行
		printf("\n");
	}
	
	return 0;
}

