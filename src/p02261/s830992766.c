#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#define scan(x) scanf("%d",&x)
#define scanc(x) scanf("%s",x)

#define print(x) printf("%d",x)
#define printn(x) printf("%d\n",x)
#define printc(x) printf("%s ",x)
#define repd(i,n,m) for(int i = n; i > m; i--)
#define rep(i,n,m) for(int i = n; i < m; i++)

void BubbleSort(char C[][3], int N){
	char box[3];
	rep(i,0,N){
		repd(j,N-1,i){
			if(C[j][1] < C[j-1][1]){
				strcpy(box,C[j]);
				strcpy(C[j],C[j-1]);
				strcpy(C[j-1],box);				
			}
		}
	}
}

void SelectionSort(char C[][3], int N){
	char box[3];
	int minj;
	rep(i,0,N){
		minj = i;
		rep(j,i,N){
			if(C[minj][1] > C[j][1]){
				minj = j;			
			}
		}
		strcpy(box,C[minj]);
		strcpy(C[minj],C[i]);
		strcpy(C[i],box);	
	}
}

int isStable(char in[][3],char out[][3],int N){
	rep(i,0,N){
		if(strcmp(in[i],out[i])!=0) return 0;
	}
	return 1;
}
int main(void){
	char C[36][3];
	char Bubble[36][3];
	char Selection[36][3];
	int N;
	scan(N);
	rep(i,0,N){
		scanc(C[i]);
		strcpy(Bubble[i],C[i]);
		strcpy(Selection[i],C[i]);
	}
	BubbleSort(Bubble,N);
	SelectionSort(Selection,N);
	rep(i,0,N-1){
		printc(Bubble[i]);
	}
	printf("%s",Bubble[N-1]);
	printf("\n");
	printf("Stable\n");
	rep(i,0,N-1){
		printc(Selection[i]);
	}
	printf("%s",Selection[N-1]);
	printf("\n");
	if(isStable(Bubble,Selection,N)) printf("Stable\n");
	else printf("Not stable\n");

	return 0;
}
