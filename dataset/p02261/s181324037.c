#include <stdio.h>
#define N 36

void bubbleSort(int V[N],char S[N],int n){
	
	int temp;
	char ctemp;
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			if( V[j] < V[j-1]){
				temp = V[j]; ctemp = S[j];
				V[j] = V[j-1]; S[j] = S[j-1];
				V[j-1] = temp; S[j-1] = ctemp;
			}
		}
	}
	
}

void selectionSort(int V[N],char S[N],int n){
	
	int temp,min;
	char ctemp;
	for( int i = 0; i < n; i++){
		min = i;
		for( int j = i; j < n; j++){
			if( V[j] < V[min] ) min = j;
		}
		if( min != i ){
			temp = V[i]; ctemp = S[i];
			V[i] = V[min]; S[i] = S[min];
			V[min] = temp; S[min] = ctemp;
		}
	}
	
}

int check_stable(int v[N], char s[N], int v1[N], char s1[N], int n){
	
	char unsorted[4], sorted[4];
	
	for(int i = 1; i < 10; i++){
		int unsorted_c = 0, sorted_c = 0;
		for(int j = 0; j < n; j++){
			if( v[j] == i ){
				unsorted[unsorted_c] = s[j];
				unsorted_c++;
			} 
			if( v1[j] == i ){
				sorted[sorted_c] = s1[j];
				sorted_c++;
			} 
		}
		for(int j = 0; j < unsorted_c; j++){
			if( unsorted[j] != sorted[j] ) {
				return -1;
			}
		}
	}
	
	return 1;
	
}

int main(void){
	
	int n;
	char suit[N],suit1[N],suit2[N];
	int value[N],value1[N],value2[N];
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf(" %c", &suit[i]);
		scanf("%d", &value[i]);
		suit1[i] = suit[i]; suit2[i] = suit[i];
		value1[i] = value[i]; value2[i] = value[i];
	}
	
	bubbleSort(value1, suit1, n);
	selectionSort(value2, suit2, n);
	for(int i = 0; i < n; i++){
		printf("%c", suit1[i]);
		printf("%d", value1[i]);
		if( i != n-1 ) printf(" ");
	}
	printf("\n");
	if( check_stable(value, suit, value1, suit1, n) == 1 ){
		printf("Stable\n");
	} else {
		printf("Not Stable\n");
	}
	for(int i = 0; i < n; i++){
		printf("%c", suit2[i]);
		printf("%d", value2[i]);
		if( i != n-1 ) printf(" ");
	}
	printf("\n");
	if( check_stable(value, suit, value2, suit2, n) == 1 ){
		printf("Stable\n");
	} else {
		printf("Not stable\n");
	}
	
}
