#include <stdio.h>
#include <string.h>
/* 返り値 1=>stable 0=>notstable */
int SelectionSort(int N, int row, int A[row][N]);
int BubbleSort(int N, int row, int A[row][N]);
int CheckStable(int N, int row, int bbs[row][N], int sls[row][N]);
int main(){
  char line[100000];
  int total;
  int i;
  char card;
  char *str_ptr;
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &total);
  int bfs[2][total];		/* ソート前のデータ */
  int bbs[2][total];			/* バブルソート */
  int sls[2][total];			/* 選択ソート */
  //カードの読み込み
  fgets(line, sizeof(line), stdin);
  str_ptr=strtok(line, " ");
  for(i=0; i<total; ++i){
	bbs[0][i]=*str_ptr;
	bfs[0][i]=*str_ptr;
	sls[0][i]=*str_ptr;
	++str_ptr;
	bbs[1][i]=(*str_ptr-'0');
	bfs[1][i]=(*str_ptr-'0');
	sls[1][i]=(*str_ptr-'0');
	str_ptr=strtok(NULL, " ");
	if(str_ptr==NULL)
	  break;
  }
  //sort
  SelectionSort(total, 2, sls);
  BubbleSort(total, 2, bbs);
  //

  //バブルソートの結果の出力
  for(i=0; i<total; ++i){
  	printf("%c%d", bbs[0][i], bbs[1][i]);
  	if(i<(total-1))
  	  printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  //選択ソートの結果の出力
  for(i=0; i<total; ++i){
  	printf("%c%d", sls[0][i], sls[1][i]);
  	if(i<(total-1))
  	  printf(" ");
  }
  printf("\n");
  int flag;
  flag=CheckStable(total, 2, bbs, sls);
  if(flag==0)
	printf("Stable\n");
  else
	printf("Not stable\n");
  return 0;
}
int SelectionSort(int N, int row, int A[row][N]){
  int i, j;
  int tmp, min;
  int index;
  int count;
  char ch;
  for(i=0; i<(N-1); ++i){
	min=A[1][i];
	tmp=A[1][i];
	ch=A[0][i];
	for(j=(i+1); j<N; ++j){
	  if(min>A[1][j]){
		min=A[1][j];
		index=j;
		
	  }
	}
	if(tmp!=min){
	  A[1][i]=min;
	  A[1][index]=tmp;
	  A[0][i]=A[0][index];
	  A[0][index]=ch;
	  ++count;
	}
  }
  return 1;
}
int BubbleSort(int N, int r, int A[r][N]){
  int i, j;
  char tmp_ch;
  int tmp_int;
  for(i=0; i<(N-1); ++i){
	for(j=(N-1); j>i; --j){
	  if(A[1][j]<A[1][j-1]){
		tmp_ch=A[0][j];
		tmp_int=A[1][j];
		A[0][j]=A[0][j-1];
		A[1][j]=A[1][j-1];
		A[0][j-1]=tmp_ch;
		A[1][j-1]=tmp_int;
	  }
		
	}
  }
  return 1;
}
/* 安定<==>1  不安定<==>0 */
int CheckStable(int N, int row, int bbs[row][N], int sls[row][N]){
  int i;
  int flag=0;
  for(i=0; i<N; ++i){
	if((bbs[0][i]==sls[0][i])&&(bbs[1][i]==sls[1][i]));
	else
	  ++flag;

}
  return flag;
}

