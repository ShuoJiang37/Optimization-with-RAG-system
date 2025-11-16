#include <stdio.h>
#define N 37

typedef struct{
	char ch;
	int num;
} card;

card temp,output1[N],output2[N];
int n;

void bubble();
void select();

int main(void){
	int i,j,cnt = 0;
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++){
		scanf(" %c%d",&output1[i].ch,&output1[i].num);
		output2[i] = output1[i];
	}
	bubble();
	select();
	for(i = 0 ; i < n ; i++){
		if(output1[i].ch==output2[i].ch) cnt++;
	}
	for(i = 0 ; i < n ; i++){
		printf("%c%d",output1[i].ch,output1[i].num);
		if(i != n-1) printf(" ");
		if(i == n-1) printf("\n");
	}
	puts("Stable");
	for(i = 0 ; i < n ; i++){
		printf("%c%d",output2[i].ch,output2[i].num);
		if(i != n-1) printf(" ");
		if(i == n-1) printf("\n");
	}
	if(cnt == n)puts("Stable");
	else puts("Not stable");
    	return 0;
}

void bubble(){
	int i,j;
	for(i = 0 ; i < n ; i++){
		for(j = n-1 ; j > i ; j--){
			if(output1[j-1].num > output1[j].num){
				temp = output1[j-1];
				output1[j-1] = output1[j];
				output1[j] = temp;
			}
		}
	}
	return ;
}

void select(){
	int mini,i,j;
	for(i = 0 ; i < n ; i++){
		mini = i;
		for(j = i ; j < n ; j++){
			if(output2[j].num < output2[mini].num) mini = j;
		}
		temp = output2[i];
		output2[i] = output2[mini];
		output2[mini] = temp;
	}
	return ;
}

