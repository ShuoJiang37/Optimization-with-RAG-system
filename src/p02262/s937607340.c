#include <stdio.h>
int B[9900000];
long cnt=0;
void shellSort(int n);
void insertionSort(int n,int g);
void Answer(int n,int G[30],int m);
int main(void){
	int i,n,m;
	char str[1000];

	fgets(str,sizeof(str),stdin);
	sscanf(str,"%d",&n);
	for(i=0;i<n;i++){
		fgets(str,sizeof(str),stdin);
		sscanf(str,"%d",&m);
		B[i]=m;		
	}
	shellSort(n);
	return 0;
}

void shellSort(int n){
	int i,m,G[1000];
	int tmp=0;
	for(m=0; ;m++){
		if(n>=3*tmp+1) G[m]=3*tmp+1;
		else break;
		tmp=3*tmp+1;
	}
	for(i=m-1;i>=0;i--)
		insertionSort(n,G[i]);
	Answer(n,G,m);
}
void insertionSort(int n,int g){
	int i,j,v;
	for(i=g;i<n;i++){
		v = B[i];
		j = i - g;
		while(j>=0 && B[j]>v){
			B[j+g] = B[j];
			j = j - g;
			cnt++;
			B[j+g] = v;
		}
	}
}
void Answer(int n,int G[1000],int m){
	int i;
	printf("%d\n",m);
	for(i=m-1;i>=0;i--){
		if(i!=m-1) printf(" ");
		printf("%d",G[i]);
	}
	printf("\n%d\n",cnt);
	for(i=0;i<n;i++){
		printf("%d\n",B[i]);
	}	
}