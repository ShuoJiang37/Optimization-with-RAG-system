#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct trm{
	char name[10];
	int value;
} tramp;

int BubbleSort(tramp val[36],int n){
	for(int i = 0; i < n; i++){
		for(int u = n - 1; u > i; u--){
			if(val[u].value < val[u - 1].value){
				tramp flag = val[u - 1];
				val[u - 1] = val[u];
				val[u] = flag;
			}
		}
	}
}

int SelectionSort(tramp val[36],int n){
	for(int i = 0; i < n; i++){
		int min = i;
		for(int u = i; u < n; u++){
			if(val[u].value < val[min].value){
				min = u;
			}
		}
		if(min > i){
			tramp t = val[i];
			val[i] = val[min];
			val[min] = t;
		}
	}
}
int isStable(tramp be_val[36],tramp af_val[36],int n){
	int lastNo = 0;
	int lastval = 0;
	for(int i = 0; i < n; i++){
		if(lastNo != af_val[i].value){
			lastNo = af_val[i].value;
			lastval = 0;
		}
//		printf("lastNo = %d , af_val[%d].value = %d\n",lastNo,i,af_val[i].value);
		int u = lastval;
		for(; u < n;u++){
			if(strcmp(af_val[i].name, be_val[u].name) == 0){
				lastval = u + 1;
				u = 1000;
			}
		}
		if(u < 1000){
			return 0; //false
		}
	}
	return 1; //true
}

int main(){
	int n;
	tramp val[36];
	int changecount = 0;

	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%s",&val[i].name);
		val[i].value = val[i].name[1] - 48;
	}
	tramp BSval[36],SSval[36];
	memcpy(BSval, val, sizeof(val));
	memcpy(SSval, val, sizeof(val));
	
	BubbleSort(BSval,n);
	SelectionSort(SSval,n);
	
	//
	printf("%s",BSval[0].name);
	for(int i = 1; i < n; i++){
		printf(" %s",BSval[i].name);
	}
	printf("\n");
	
	//あとは安定かどうかを調べるだけ
	//（順番に上からチェック？）
	if(isStable(val,BSval,n)){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	printf("%s",SSval[0].name);
	for(int i = 1; i < n; i++){
		printf(" %s",SSval[i].name);
	}
	
	printf("\n");

	if(isStable(val,SSval,n)){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	return 0;

}
