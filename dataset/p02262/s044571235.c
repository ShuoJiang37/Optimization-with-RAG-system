#include <stdio.h>

//insertionSort(A,n,g)
//	for i = g to n-1
//		v = A[i]
//		j = i - g
//		while j >= 0 && A[j] > v
//			A[j+g] = A[j]
//			j = j - g
//			cnt++
//		A[j+g] = v

//ShellSort(A, n)
//	cnt = 0
//	m = ?
//	G[] = {?, ?, ..., ?}
//	for i = 0 to m-1
//		insertionSort(A, n, G[i])

int insertionSort ( int *Arr, int last_point, int begin_point );
int ShellSort ( int *Arr, int length );

int main(void)
{
	int length = 0;
	int Arr[1000000] = {};
	int i = 0;
	
	scanf("%d\n", &length);
	
	for ( i = 0; i < length; i++ ) {
		scanf("%d\n", &Arr[i]);
	}
	
	ShellSort ( Arr, length );
	
	for ( i = 0; i < length; i++ ) {
		printf("%d\n", Arr[i]);
	}
}

//insertionSort(A,n,g)
int insertionSort ( int *Arr, int last_point, int v )
{
	int i = 0;			/* ループ 				  */
	int j = 0;			/* ループ 				  */
	int tmp = 0;		/* 入れ替えのためのダミー */
	static int cnt = 0;	/* カウント */

	for ( i = v; i < last_point; i++ ) {
		tmp = Arr[ i ];
		j = i - v;
		while ( j >= 0 && Arr[ j ] > tmp ) {
			Arr[ j + v ] = Arr[ j ];
			j = j - v;
			cnt++;
		}
		Arr[ j + v] = tmp;
	}
	
	return cnt;
}
//ShellSort(A, n)
int ShellSort ( int *Arr, int length )
{
//	cnt = 0
	int cnt = 0;
	int m = 0;
	int i = 0;
	int G[13] = {
		797161 ,
		265720 ,
		88573  ,
		29524  ,
		9841   ,
		3280   ,
		1093   ,
		364    ,
		121    ,
		40     ,
		13     ,
		4      ,
		1
	};
	
	for ( m = 12; m >= 0; m-- ) {
		if ( G[m] > length ) {
			break;
		}
	}
	
	printf( "%d\n", 12 - m );
	
	for ( i = m+1; i < 12; i++ ) {
		
		printf( "%d ", G[i] );
	}
	
	printf("1\n");
	
	for ( i = m+1; i < 13; i++ ) {
		cnt = insertionSort(Arr, length, G[i]);
	}
	printf("%d\n", cnt);
	
	return 0;
}
