#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
5
H4 C9 S4 D2 C3
*/

#define S 0
#define H 1
#define C 2
#define D 3

void BubbleSort(int **A,int N){
	int tmp;
	for(int i=0;i<N-1;i++){
		for(int j=(N-1);j>i;j--){
			if(A[j][1]<A[j-1][1]){
				tmp=A[j][0];
				A[j][0]=A[j-1][0];
				A[j-1][0]=tmp;
				tmp=A[j][1];
				A[j][1]=A[j-1][1];
				A[j-1][1]=tmp;
			}
		}
	}
}

void SelectionSort(int **A,int N){
	int tmp;
	int min;
	for(int i=0;i<N-1;i++){
		min=i;
		for(int j=i+1;j<N;j++){
			if(A[j][1]<A[min][1]){
				min=j;
			}
		}
		tmp=A[i][0];
		A[i][0]=A[min][0];
		A[min][0]=tmp;
		tmp=A[i][1];
		A[i][1]=A[min][1];
		A[min][1]=tmp;
	}
}

char convert(int a){
	switch(a){
	case S:
		return 'S';
		break;
	case H:
		return 'H';
		break;
	case C:
		return 'C';
		break;
	case D:
		return 'D';
		break;
	}
}

int convert_to_int(char x){
	switch(x){
	case 'S':
		return S;
	case 'H':
		return H;
		break;
	case 'C':
		return C;
		break;
	default:
		return D;
		break;
	}
}

char *check_Stable(int N,int **B,int B3[10][4],int B_count[10]){
	int count=0;
	for(int i=1;i<10;i++){
		for(int j=0;j<B_count[i];j++){
			if(B[count][0]!=B3[i][j]){
				return "Not stable";
			}
			count++;
		}
	}

	return "Stable";
}

void show(int **A,int N){
	for(int i=0;i<N;i++){
		printf("%c%d",convert(A[i][0]),A[i][1]);
		if(i!=N-1){
			printf(" ");
		}
	}printf("\n");
}

int main(){
	int N;
	char **A;
	int **B,**B2;
	int t0;
	int B3[10][4];
	int B_count[10];

	scanf("%d",&N);

	for(int i=0;i<10;i++){
		B_count[i]=0;
	}
	
	A=(char**)malloc(N*sizeof(char*));
	B=(int**)malloc(N*sizeof(int*));
	B2=(int**)malloc(N*sizeof(int*));
	for(int i=0;i<N;i++){
		A[i]=(char*)malloc(3*sizeof(char));
		B[i]=(int*)malloc(2*sizeof(int));
		B2[i]=(int*)malloc(2*sizeof(int));
		scanf("%s",A[i]);
		switch(A[i][0]){
		case 'S':
			t0=S;
			break;
		case 'H':
			t0=H;
			break;
		case 'C':
			t0=C;
			break;
		case 'D':
			t0=D;
			break;
		}
		B[i][0]=t0;
		B[i][1]=A[i][1]-'0';
		B2[i][0]=B[i][0];
		B2[i][1]=B[i][1];
		t0=(A[i][1]-'0');
		B3[t0][B_count[t0]]=convert_to_int(A[i][0]);
		B_count[t0]++;
	}
	

	BubbleSort(B,N);
	show(B,N);
	printf("%s\n",check_Stable(N,B,B3,B_count));
	SelectionSort(B2,N);
	show(B2,N);
	printf("%s\n",check_Stable(N,B2,B3,B_count));

	return 0;
}
