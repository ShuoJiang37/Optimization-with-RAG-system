#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char marknumber[10];
	int value;
}trump;

void BubbleSort(trump *C,int n);
void SelectionSort(trump *C2,int n);
int isStable(trump *in,trump *out,int n);

int main(void){
	
	int n,i,check;
	trump C[36],C1[36],C2[36];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){						//マークと数字を読み込み
		scanf("%s",C[i].marknumber);
		C[i].value=(int)(C[i].marknumber[1])-48;
		strcpy(C1[i].marknumber,C[i].marknumber);
		C1[i].value=C[i].value;
		strcpy(C2[i].marknumber,C[i].marknumber);
		C2[i].value=C[i].value;
	}
	
	BubbleSort(C1,n);////////////////
	
	for(i=0;i<n;i++){
		printf("%s",C1[i].marknumber);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
	
	check=isStable(C,C1,n);
	
	if(check==2){
		printf("Not stable\n");
	}
	else if(check==1){
		printf("Stable\n");
	}
	
	SelectionSort(C2,n);/////////
	
	for(i=0;i<n;i++){
		printf("%s",C2[i].marknumber);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
	
	check=isStable(C,C2,n);
	
	if(check==2){
		printf("Not stable\n");
	}
	else if(check==1){
		printf("Stable\n");
	}
	
	return 0;
}  

void BubbleSort(trump *C1,int n){
	
	int i,j,tmp1;
	char tmp2[10];
	
	for(i=0;i<n;i++){
		for(j=n-1;j>=i+1;j--){
			if(C1[j].value<C1[j-1].value){
				tmp1=C1[j].value;
				C1[j].value=C1[j-1].value;
				C1[j-1].value=tmp1;
				strcpy(tmp2,C1[j].marknumber);
				strcpy(C1[j].marknumber,C1[j-1].marknumber);
				strcpy(C1[j-1].marknumber,tmp2);
			}
		}
	}
}

void SelectionSort(trump *C2,int n){
	
	int i,j,minj,tmp1;
	char tmp2[10];
	
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(C2[j].value<C2[minj].value){
				minj=j;
			}
		}
		tmp1=C2[i].value;
		C2[i].value=C2[minj].value;
		C2[minj].value=tmp1;
		strcpy(tmp2,C2[i].marknumber);
		strcpy(C2[i].marknumber,C2[minj].marknumber);
		strcpy(C2[minj].marknumber,tmp2);
	}
}

int isStable(trump *in,trump *out,int n){
	
	int i,j,a,b;
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(a=0;a<n;a++){
				for(b=a+1;b<n;b++){
					if(in[i].value==in[j].value && strcmp(in[i].marknumber,out[b].marknumber)==0 && strcmp(in[j].marknumber,out[a].marknumber)==0){
						return 2;
					}
				}
			}
		}
	}
	
	return 1;
}
