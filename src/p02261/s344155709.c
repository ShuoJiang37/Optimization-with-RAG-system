#include <stdio.h>
#define s 36

typedef struct{
	int value;
	char key;
} jinde;

jinde temp;

BubbleSort(jinde *B, int N)
{
	int flag=1, j;
	while(flag){
		flag=0;
		for(j=N-1; j>0; j--){
			if(B[j].value<B[j-1].value){
				temp=B[j];
				B[j]=B[j-1];
				B[j-1]=temp;
				flag=1;
			}
		}
	}
}

SelectionSort(jinde *S, int N)
{
	int i, j, min;
	for(i=0; i<N-1; i++){
		min=i;
		for(j=i+1; j<N; j++){
			if(S[min].value>S[j].value) min=j;
		}
		temp=S[i];
		S[i]=S[min];
		S[min]=temp;
	}
}

int main()
{
	int n, i, no=0;
	jinde B[s], S[s];
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf(" %c%d", &B[i].key, &B[i].value);
		S[i]=B[i];
	}
	
	BubbleSort(B, n);
	for(i=0; i<n; i++){
		if(i==n-1) printf("%c%d\nStable\n", B[i].key, B[i].value);
		else printf("%c%d ", B[i].key, B[i].value);
	}
	SelectionSort(S, n);
	for(i=0; i<n; i++){
		if(i==n-1) printf("%c%d\n", S[i].key, S[i].value);
		else printf("%c%d ", S[i].key, S[i].value);
		if(B[i].key!=S[i].key) no=1; //Bのローマ字と一致するか,しなければno=1
	}
	
	if(no) printf("Not stable\n"); //一致しなかったら(no=1なら)Not stable
	else printf("Stable\n");
	
	return 0;
}
