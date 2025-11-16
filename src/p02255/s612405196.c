// 
#include<stdio.h>

#define Num 1000

static void outputdisp(int A[], int n);

int main(){
	int n;			/* 入力文字数			*/
	int i;          /* ループ用変数1		*/
	int j;          /* ループ用変数2		*/
	int v;          /* 退避用変数			*/
	int A[Num+1];   /* 数列格納配列			*/

	/* 入力処理 */
	/* 文字数を読み込む */
	scanf("%d", &n);

	/* 数列を読み込む */
	for ( i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	/* 読み込んだ数列を表示 */
	outputdisp(A, n);

	/* ソート処理 */
	for( i = 1; i < n; i++ ){
		v = A[i];
		j = i-1;
		
		while( ( j >= 0 ) && ( A[j] > v ) ){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		
		/* 出力処理 */
		outputdisp(A, n);
	}


  return 0;
}

void outputdisp(int A[], int n){
	int i;		/* ループ用変数 */ 

	/* 配列Aの数列を出力 */
	for( i = 0; i < n; i++ ){
		if ( i > 0 ){
			printf(" ");
		}
		else{
			/* 処理なし */	
		}

		printf("%d", A[i]);
  	}
  	printf("\n");
}

