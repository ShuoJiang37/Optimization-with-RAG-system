#include <stdio.h>
int cnt=0,B[101];
void BubbleSort(int n);
int main(void){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	BubbleSort(n);
	for(i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",B[i]);
	}
	printf("\n%d\n",cnt);
	return 0;
}

void BubbleSort(int n){
	int i,j,tmp;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){	
			if(B[j] < B[j-1]){
				tmp = B[j-1];
				B[j-1] = B[j];
				B[j] = tmp;
				cnt++;
			}
		}
	}	
}