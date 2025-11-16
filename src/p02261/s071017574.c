#include <stdio.h>
#include <string.h>
typedef struct{
	char mark;
	int num;
}card;
card A[36],B[36],C[36];
void BubbleSort(int n,card B[36]);
void SelectionSort(int n,card B[36]);
int Stable(int n,card A[36],card B[36]);
int main(void){
	int i,n,m;
	char str[5000],*line,c;

	fgets(str,sizeof(str),stdin);
	sscanf(str,"%d",&n);
	fgets(str,sizeof(str),stdin);
	line = strtok(str," ");
	sscanf(line,"%c%d",&c,&m);
	C[0].mark=c; C[0].num=m;
	A[0]=C[0]; B[0]=C[0];
	for(i=1;i<n;i++){
		line = strtok(NULL," ");
		sscanf(line,"%c%d",&c,&m);
		C[i].mark=c; C[i].num=m;
		A[i]=C[i]; B[i]=C[i];	
	}
	BubbleSort(n,C);
	for(i=0;i<n;i++){
		if(i) printf(" ");
		printf("%c%d",C[i].mark,C[i].num);
	}
	printf("\nStable\n");
	SelectionSort(n,A);
	for(i=0;i<n;i++){
		if(i) printf(" ");
		printf("%c%d",A[i].mark,A[i].num);
	}
	if(Stable(n,A,B)) printf("\nStable\n");
	else		  printf("\nNot stable\n");
	return 0;
}

void BubbleSort(int n,card B[36]){
	int i,j;
	card tmp;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){	
			if(B[j].num < B[j-1].num){
				tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
			}
		}
	}	
}
void SelectionSort(int n,card B[36]){
	int z,i,j;
	card tmp,min;
	for(j=0;j<n-1;j++){
		min.num = B[j].num;
		z = j;	
		for(i=j+1;i<n;i++){	
			if(B[i].num < min.num){
				min.num = B[i].num;
				z = i;
			}
		}
		if(B[j].num != B[z].num){
			tmp = B[j];
			B[j] = B[z];
			B[z] = tmp;
		}
	}
}
int Stable(int n,card A[36],card B[36]){
	int i,j,a,b;
    for(i=0;i<n;i++){
    	for(j=i+1;j<n;j++){
    		for(a=0;a<n;a++){
				for(b=a+1;b<n;b++){
					if(B[i].num==B[j].num && B[i].mark==A[b].mark &&
						B[j].mark==A[a].mark && B[i].num==A[b].num && 
						 B[j].num==A[a].num)
						return 0;
				}
    		}
    	}
    }
	return 1;
}