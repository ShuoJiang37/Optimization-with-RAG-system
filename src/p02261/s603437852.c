#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p,n) {p = malloc((n)*sizeof(*p));if ((p)==NULL) {printf("not enough memory?\n"); exit(1);};}

typedef struct {
	int key;
	char suits;
}obj;

obj *readObj(int *num){
	int i;
	obj *A;
	scanf("%d",num);
	mymalloc(A,*num);
	for(i=0;i<*num;i++){
		scanf(" %c%d ",&A[i].suits,&A[i].key); //scanf???????§????????????\???????????¨????????????
	}
	return A;
}

void printObj(obj *A,int num){
	int i;
	for(i=0;i<num;i++){
		printf("%c%d",A[i].suits,A[i].key);
		if(i<num-1){printf(" ");}
	}
	printf("\n");
}

obj *duplicate(obj *A,int num){
	int i;
	obj *B;
	mymalloc(B,num);
	for(i=0;i<num;i++){
		B[i]=A[i];
	}
	return B;
}

void swapIJ(obj *a, obj *b){
	obj temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(obj *A,int num){
	int i,j;
	for(i=0;i<num;i++){
		for(j=num-1;j>i;j--){
			if(A[j].key<A[j-1].key){
				swapIJ(&A[j],&A[j-1]);
			}
		}
	}
}

int selecSort(obj *A,int num){
	int i,j,k,mini,idx,frag;
	char seq[10][4];
	int count[10];
	for(i=1;i<10;i++){
		count[i]=0;
		for(j=0;j<4;j++){
			seq[i][j]='a';
		}
	}
	for(i=0;i<num;i++){
		mini=i;
		for(j=i+1;j<num;j++){
			if(A[j].key<A[mini].key){mini=j;}
			if(A[j].key==A[i].key&&count[A[j].key]!=-1){
				idx=A[j].key;
				if(count[idx]==0){seq[idx][0]=A[i].suits;count[idx]++;}
				seq[idx][count[idx]]=A[j].suits;count[idx]++;
			}
		}
		for(j=0;j<10;j++){
			if(count[j]>0){count[j]=-1;}
		}
		if(i!=mini){
			swapIJ(&A[i],&A[mini]);
		}
	}
	
	frag=0;
	for(i=1;i<10;i++){
		if(count[i]==-1){
			j=0;k=0;
			while(A[j].key!=i&&j<num){
				j++;
			}
			while(seq[i][k]!='a'&&k<4){
				if(seq[i][k]!=A[j+k].suits){
					frag=1;break;
				}
				k++;
			}
		}
		if(frag==1){break;}
	}
	return frag;
}

main(){
	obj *A,*B;
	int i,j,k,num,frag;
	A=readObj(&num);
	B=duplicate(A,num);
	
	bubbleSort(A,num);
	printObj(A,num);
	printf("Stable\n");
	
	frag=selecSort(B,num);
	printObj(B,num);
	if(frag==0){
		printf("Stable\n");
	}
	else{
		printf("Not stable\n");
	}
	
	return 0;
}