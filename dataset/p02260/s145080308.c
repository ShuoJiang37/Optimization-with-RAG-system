#include <stdio.h>
int B[101],cnt=0;
void SelectionSort(int n);
int main(void){
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	SelectionSort(n);
	for(i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",B[i]);
	}
	printf("\n%d\n",cnt);
	return 0;
}

void SelectionSort(int n){
	int min,z,tmp,i,j;
	for(j=0;j<n-1;j++){
		min = B[j];
		z = j;	
		for(i=j+1;i<n;i++){	
			if(B[i] < min){
				min = B[i];
				z = i;
			}
		}
		if(B[j] != B[z]){
			tmp = B[j];
			B[j] = B[z];
			B[z] = tmp;
			cnt++;
		}
	}
}