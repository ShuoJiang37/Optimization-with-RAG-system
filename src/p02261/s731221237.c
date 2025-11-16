
#include <stdio.h>
#include <string.h>

struct card{
	int num;
	char suit;
};

void bubbleSort(struct card *c, int n);
void selectionSort(struct card *c, int n);
int isStable(struct card *chg, char suitOrder[10][5], int len);
void showRes(struct card *chg, int len, int resStable);

int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	struct card a[n];
	char suits[10][5];
	memset(suits, '\0', 10 * 5 * sizeof(char));
	for(i = 0; i < n; i++){
		//scanf(" %[HCDS]", &a[i].suit);
		//scanf("%d", &a[i].num);
		scanf(" %[HCDS]%d", &a[i].suit, &a[i].num);
		//printf("%c ", a[i].suit);
		//printf("%d ", a[i].num);
		sprintf(suits[a[i].num], "%s%c", suits[a[i].num], a[i].suit);
		//printf("%s\n", suits[a[i].num]);
	}

	struct card a2[n], a3[n];
	memcpy(a2, a, sizeof(a));
	memcpy(a3, a, sizeof(a));

	//printf("kakikuke\n");
	bubbleSort(a2, n);
	int resStable = isStable(a2, suits, n);
	//printf("aiue\n");
	showRes(a2, n, resStable);
	
	selectionSort(a3, n);
	showRes(a3, n, isStable(a3, suits, n));

	return 0;
}

void bubbleSort(struct card *c, int n)
{
	//printf("bubble\n");
	int i, j;
	struct card buf;
	for(i = 0; i <= n - 1; i++){
		for(j = n - 1; j >= i + 1; j--){
			if(c[j].num < c[j - 1].num){
				buf = c[j];
				c[j] = c[j - 1];
				c[j - 1] = buf;
			}
		}
	}
	//printf("bubble_e\n");
}

void selectionSort(struct card *c, int n)
{
	int i, minj, j;
	struct card buf;
	for(i = 0; i <= n - 1; i++){
		minj = i;
		for(j = i; j <= n - 1; j++){
			if(c[j].num < c[minj].num){
				minj = j;
			}
		}
		if(i != minj){
			buf = c[i];
			c[i] = c[minj];
			c[minj] = buf;
		}
	}
}

int isStable(struct card *chg, char suitOrder[10][5], int len)
{
	char st[5] = "\0";
	int i;
	for(i = 0; i < len; i++){
		if((i > 0) && (chg[i].num != chg[i - 1].num)){
			memset(st, '\0', sizeof(st));
		}
		sprintf(st, "%s%c", st, chg[i].suit);
		if((i == len - 1) || ((i < len - 1) && (chg[i].num != chg[i + 1].num))){
			if(strcmp(st, suitOrder[chg[i].num]) != 0){
				return 0;
			}
		}
	}
	return 1;
}

void showRes(struct card *chg, int len, int resStable)
{
	int i;
	for(i = 0; i < len - 1; i++){
		printf("%c%d ", chg[i].suit, chg[i].num);
	}
	printf("%c%d\n", chg[len - 1].suit, chg[len - 1].num);
	if(resStable){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
}


