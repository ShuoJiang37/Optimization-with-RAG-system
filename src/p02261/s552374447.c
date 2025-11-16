#include<stdio.h>
#define N 36

typedef struct{
	char mark;
	int num;
}card_t;

void copy_cards(card_t* copy, card_t* original,int n){
	for(int i=0;i<n;i++){
		copy[i].mark=original[i].mark;
		copy[i].num=original[i].num;
	}
}

void card_change(card_t* a,card_t* b){
	char tmp_m;
	int tmp_n;
	
	tmp_m=a->mark;
	a->mark=b->mark;
	b->mark=tmp_m;
	
	tmp_n=a->num;
	a->num=b->num;
	b->num=tmp_n;
}

void card_print(card_t* card,int n){
	for(int i=0;i<n;i++){
		printf("%c",card[i].mark);
		printf("%d",card[i].num);
		if(i!=n-1)printf(" ");
	}
	printf("\n");
}

int main(void){
	int n;
	int c_num[10]={};
	
	scanf("%d ",&n);
	
	card_t original[N];
	card_t bubble[N];
	card_t selection[N];
	
	for(int i=0;i<n;i++){
		scanf("%c",&original[i].mark);
		scanf("%d ",&original[i].num);
	}
	copy_cards(bubble,original,n);
	copy_cards(selection,original,n);
	
	int flag=1;
	
	while(flag){
		flag=0;
		for(int j=n-1;j>=1;j--){
			if(bubble[j].num<bubble[j-1].num){
				card_change(bubble+j,bubble+j-1);
				flag=1;
			}
		}
	}
	
	card_print(bubble,n);
	
	int aim,stable_flag=1;
	for(int i=0;i<n;i++){
		aim=original[i].num;
		for(int j=0;j<n;j++){
			if(bubble[j].num==aim){
				if(bubble[j+c_num[aim]].mark==original[i].mark){
					c_num[aim]++;//ok
				}else{
					stable_flag=0;
				}
				break;
			}
		}
	}
	
	if(stable_flag){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	//選択ソート
	int minj;
	
	for(int i=0;i<n;i++){
        minj=i;
        for(int j=i;j<n;j++){
            if(selection[j].num<selection[minj].num){
                minj=j;
            }
        }
		card_change(selection+i,selection+minj);
    	
    }
	
	card_print(selection,n);
	
	for(int i=0;i<10;i++)c_num[i]=0;
	
	stable_flag=1;
	for(int i=0;i<n;i++){
		aim=original[i].num;
		for(int j=0;j<n;j++){
			if(selection[j].num==aim){
				if(selection[j+c_num[aim]].mark==original[i].mark){
					c_num[aim]++;//ok
				}else{
					stable_flag=0;
				}
				break;
			}
		}
	}
	
	if(stable_flag){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	return 0;
}
