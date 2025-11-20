#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int selectionSort(char A[50][3], int N)
{
	int minj;
	int i,j;
	char tmp[3];
	for(i=0;i<N;i++){
		minj=i;
		
		for(j=i+1;j<N;j++){
			if(A[j][1]<A[minj][1]){
				minj=j;
			}
		}
		if(i!=minj){
			strcpy(tmp,A[i]);//tmp = A[i];
			strcpy(A[i],A[minj]);//A[i]=A[minj];
			strcpy(A[minj],tmp);//A[minj]=tmp;
			//cnt++;
		}
	}
	//printf("%s %s %s\n",A[0],A[1],tmp);
	return 0;
}

static int cnt;
int bubbleSort(char A[50][3], int N)
{
	int flag=1;
	int i;
	char tmp[3];
	while(flag){
		flag = 0;
		
		for(i=N-1;i>0;i--){
			if(A[i][1]<A[i-1][1]){
				strcpy(tmp,A[i]);//tmp = A[i];
				strcpy(A[i],A[i-1]);//A[i]=A[i-1];
				strcpy(A[i-1],tmp);//A[i-1]=tmp;
				flag=1;
				//cnt++;
			}
		}
	}
	return 0;
}

int 
main(){
	int N;
	char B[50][3];char C[50][3];
	int s_stable=0;
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++){
		scanf("%s",B[i]);
		strcpy(C[i],B[i]);
	}
	//////////////////////////////////////
	bubbleSort(C,N);
	s_stable=0;
		for(i=0;i<N;i++){
	    if(i<N-1)printf("%s ",C[i]);
	    else printf("%s\n",C[i]);
		
	}
	printf("%s\n",(s_stable>0? "Not stable":"Stable")); 
///////////////////////////////////////	
	selectionSort(B,N);


	for(i=0;i<N;i++){
	    if(i<N-1)printf("%s ",B[i]);
	    else printf("%s\n",B[i]);
		
		if(B[i][0]!=C[i][0]) s_stable++;
	}
	printf("%s\n",(s_stable>0? "Not stable":"Stable")); 


 return 0;
}
