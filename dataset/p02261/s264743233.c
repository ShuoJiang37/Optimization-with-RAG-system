#include <stdio.h>

int main(void){
	int N;
	int num[36];
	int num_b[36];
	int num_s[36];
	int key_i;
	
	char num_name[36];
	char num_name_b[36];
	char num_name_s[36];
	char key_c;

	int i,j,k,l = 0;
	
	int mini;
	
	char judge[5];
	char judge_bc[5];
	char judge_sc[5];
	int judge_b = 0;
	int judge_s = 0;
	
	//Input Cards
	scanf("%d",&N);
	
	for(i = 0;i < N;i++){
		scanf("%c",&num_name[i]);
		if(num_name[i] != '\n'&&num_name[i] != ' '){
			scanf("%d",&num[i]);
		}else{
			i--;
		}
	}
	
	//Copy Cards
	for(i = 0;i < N;i++){
		num_b[i] = num[i];
		num_s[i] = num[i];
		num_name_b[i] = num_name[i];
		num_name_s[i] = num_name[i];
	}
	
	//BubbleSort
	for(i = 0;i < N;i++){
		for(j = N-1;j > i;j--){
			if(num_b[j] < num_b[j-1]){
				key_i = num_b[j];
				key_c = num_name_b[j];
				num_b[j] = num_b[j-1];
				num_name_b[j] = num_name_b[j-1];
				num_b[j-1] = key_i;
				num_name_b[j-1] = key_c;
			}
		}
	}
	
	//Selection Sort
	for(i = 0;i < N;i++){
		mini = i;
		for(j = i;j < N;j++){
			if(num_s[j] < num_s[mini]){
				mini = j;
			}
		}
		key_i = num_s[i];
		key_c = num_name_s[i];
		num_s[i] = num_s[mini];
		num_name_s[i] = num_name_s[mini];
		num_s[mini] = key_i;
		num_name_s[mini] = key_c;
	}
	
	//Judge Stable or Not Stable
	for(i = 1;i < 10;i++){
		k = 0;
		for(j = 0;(j < N&&k < 4);j++){
			if(num[j] == i){
				judge[k] = num_name[j];
				k++;
			}
		}

		l = 0;
		
		if(judge_b == 0){
			for(j = 0;(j < N&&l < k);j++){
				if(num_b[j] == i){
					judge_bc[l] = num_name_b[j];
					l++;
				}
			}
			
			for(j = 0;j < k;j++){
				if(judge_bc[j] != judge[j])judge_b = 1;
			}
		}
		
		
		l = 0;
		
		if(judge_s == 0){
			
			for(j = 0;(j < N&&l < k);j++){
				if(num_s[j] == i){
					judge_sc[l] = num_name_s[j];
					l++;
				}
			}
			
			for(j = 0;j < k;j++){
				if(judge_sc[j] != judge[j])judge_s = 1;
			}
		}
	}
	
	
	//Display
	for(i = 0;i < N;i++){
		if(i == N -1){
			printf("%c%d",num_name_b[i],num_b[i]);
		}else{
			printf("%c%d ",num_name_b[i],num_b[i]);
		}
	}
	
	printf("\n");	
	
	if(judge_b == 0){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	
	for(i = 0;i < N;i++){
		if(i == N -1){
			printf("%c%d",num_name_s[i],num_s[i]);
		}else{
			printf("%c%d ",num_name_s[i],num_s[i]);
		}
	}
	
	printf("\n");
	
	if(judge_s == 0){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	return 0;
}