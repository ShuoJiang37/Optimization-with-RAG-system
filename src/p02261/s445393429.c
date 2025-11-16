#include<stdio.h>
#include<string.h>
#define N 36
int main(){
	int i,j,k,n,min,flag;
	char a[N][2],b[N][2],hoge[2];
	scanf("%d",&n);
	for ( i = 0; i < n; i++){
		scanf("%s",a[i]);
		for(j = 0; j < 2; j++) b[i][j] = a[i][j];
	}
	//Bubble
	for( i = 0; i < n; i++){
		for( j = n - 1; j > i; j--){
			if(a[j][1] < a[j - 1][1]){
				for(k = 0; k < 2; k++) hoge[k] = a[j][k];
				for(k = 0; k < 2; k++) a[j][k] = a[j - 1][k];
				for(k = 0; k < 2; k++) a[j - 1][k] = hoge[k];
			}
		}
	}
	for ( i = 0; i < n; i++) {
		printf("%c%c",a[i][0],a[i][1]);
		if(i != (n-1)) printf(" ");
		else printf("\nStable\n");
	}

	//Selection
	for(i = 0; i < n; i++){
		min = i;
		for( j = i; j < n; j++){
			if(b[j][1] < b[min][1]){
				min = j;
			}
		}
		for(k = 0; k < 2; k++) hoge[k] = b[i][k];
		for(k = 0; k < 2; k++) b[i][k] = b[min][k];
		for(k = 0; k < 2; k++) b[min][k] = hoge[k];
	}
	flag = 0;
	for(i = 0; i < n; i++){
		for( j = 0; j < n; j++){
			if(a[i][j] != b[i][j]) flag++;
		}
	}
	for ( i = 0; i < n; i++) {
		printf("%c%c",b[i][0],b[i][1]);
		if(i != (n-1)) printf(" ");
		else if(flag == 0){
			printf("\nStable\n");
		}else{
			printf("\nNot stable\n");
		}
	}
	return 0;
}

