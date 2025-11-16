#include <stdio.h>

typedef struct {
	char sign;
	int value;
} card_t;

void BubbleSort(card_t A[], int n);
void SelectionSort(card_t A[], int n);
int isStable(card_t A[], card_t B[], int n);

int main( void ){
	int i, n;
	scanf("%d", &n);
	card_t A[n], B[n];	//B[n]には元のカード列を保存しておく
	for(i = 0; i < n; i++){
        scanf(" %c", &A[i].sign);
		scanf("%d", &A[i].value);
		B[i] = A[i];
    }

	BubbleSort(A, n);
	for(i = 0; i < n; i++){
		printf("%c%d", A[i].sign, A[i].value);
		if(i < n - 1){
			printf(" ");
		}
	}
	printf("\n");
	if(isStable(A, B, n) == 2){
		printf("Not stable\n");
	}
	else{
		printf("Stable\n");
	}
	for(i = 0; i < n; i++){
		A[i] = B[i];
	}

	SelectionSort(A, n);
	for(i = 0; i < n; i++){
        printf("%c%d", A[i].sign, A[i].value);
        if(i < n - 1){
            printf(" ");
        }
    }
    printf("\n");
	if(isStable(A, B, n) == 2){
		printf("Not stable\n");
	}
	else{
		printf("Stable\n");
	}

	return 0;
}

void BubbleSort(card_t A[], int n){
    int i, j, flag;
	card_t m;
	flag = 1;
    i = 0;
    while(flag == 1){
        flag = 0;
        for(j = n - 1; j >= i + 1; j--){
            if(A[j].value < A[j - 1].value){
                m = A[j];
                A[j] = A[j - 1];
                A[j - 1] = m;
                flag = 1;
            }
        }
        i++;
    }
}

void SelectionSort(card_t A[], int n){
	int i, j, minj;
	card_t m;	//mは交換に使う変数
	for(i = 0; i < n; i++){
		minj = i;
		for(j = i; j < n; j++){
			if(A[j].value < A[minj].value){
				minj = j;
			}
		}
		m = A[i];
		A[i] = A[minj];
		A[minj] = m;
	}
}

int isStable(card_t A[], card_t B[], int n){
	int i,j,a,b;
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			for(a = 0; a < n; a++){
				for(b = a + 1; b < n; b++){
					if(B[i].value == B[j].value && B[i].value == A[b].value && B[i].sign == A[b].sign && B[j].sign == A[a].sign && B[j].value == A[a].value){
						return 2;
					}
				}
			}
		}
	}
	return 1;
}

