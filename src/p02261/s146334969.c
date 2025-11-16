#include<stdio.h>
#include<string.h>
struct Card{
	char suit;
	int value;
};

void bubble(struct Card b[], int n);
void selection(struct Card s[], int n);
	
int main(void){
	int n,v, i, j;
	struct Card a[100], b[100], c[100];
	int aa, bb;
	int d[100];
	char s[10];
	char change[10];
	int stable=1;
	
	
	scanf("%d", &n);
	for(i = 0;i<n;i++){
		scanf("%s",s);
		//strcpy(b[i].suit, a[i].suit);
		
		a[i].suit =b[i].suit=c[i].suit= s[0];
		a[i].value =b[i].value =c[i].value = s[1]-'0';
	}
	
		
	bubble(b, n);
	
	

	
	for(i = 0;i<n-1;i++){
		
		printf("%c%d ", b[i].suit, b[i].value);
	}
	printf("%c%d\n", b[n-1].suit, b[n-1].value);

	
		printf("Stable\n");
	
	
	selection(c, n);
	stable =1;
	for(i = 0;i<n;i++){
		
			if(b[i].value != c[i].value || b[i].suit != c[i].suit ){
			stable =0;

		}
		
		
	}
	
	
	for(i = 0;i<n-1;i++){
		
		printf("%c%d ", c[i].suit, c[i].value);
	}
	printf("%c%d\n", c[i].suit, c[i].value);
	
	
	if(stable == 1){
		printf("Stable\n");
	}
	else {printf("Not stable\n");}
	
	//printf("%c %d\n", b[n-1].suit, b[i].value);
	
	return 0;
	
}




void bubble(struct Card b[], int n){
	int i, j, x;
	char y;
	for(i = 0;i<n;i++){
		for(j = n-1;j>i;j--){
			if(b[j].value<b[j-1].value){
				x = b[j-1].value;
				y = b[j-1].suit;
				b[j-1].value = b[j].value;
				b[j-1].suit = b[j].suit;
				b[j].value = x;
				b[j].suit = y;
				
				
			}
		}
	}
	
}


void selection(struct Card s[], int n){
	int i, j, min, x;
	char y;
	for(i = 0;i<n;i++){
		min =i;
		for(j =i;j<n;j++){
			if(s[min].value > s[j].value){
				min =j;
			}
		}
		if(min != i){
		x = s[i].value;
		y = s[i].suit;
		s[i].value = s[min].value;
		s[i].suit = s[min].suit;
		s[min].value = x;
		s[min].suit = y;
		}
	}
}


