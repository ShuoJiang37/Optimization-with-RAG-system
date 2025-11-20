#include <stdio.h>

int Check(int n, int a[][2], int d[][36]){
	int dc[36] = {}, i;
	for(i = 0; n > i; i++){
		if(d[a[i][0]][dc[a[i][0]]] != a[i][1]) return -1;
		dc[a[i][0]]++;
	}
	return 0;
}

void  SelectSort(int n, int a[][2]){
    int f = 1, i, j = 0;
     
    for(j = 0; n-1 > j; j++){
        int minp, min = 101;
        for(i = j; n > i; i++){
            if(a[i][0] < min){
                min = a[i][0];
                minp = i;
            }
        }
        if(j != minp){
        int buf = a[j][0];
        a[j][0] = a[minp][0];
        a[minp][0] = buf;
        buf = a[j][1];
        a[j][1] = a[minp][1];
        a[minp][1] = buf;
        }
    }
} 
void  BubbleSort(int n, int a[][2]){
    int f = 1, i;
     
    while(f){
        f = 0;
        for(i = 0; n-1 > i; i++){
            if(a[i][0] > a[i+1][0]){
                int buf = a[i+1][0];
                a[i+1][0] = a[i][0];
                a[i][0] = buf;
                buf = a[i+1][1];
                a[i+1][1] = a[i][1];
                a[i][1] = buf;
                f = 1;
            }
        }
    }
}
int main(void) {
	int n, i, a[36][2], b[36][2], d[37][36], dc[37] = {};
	scanf("%d%*c", &n);
	for(i = 0; n > i; i++){
		scanf("%c%d%*c", &a[i][1], &a[i][0]);
		d[a[i][0]][dc[a[i][0]]] = a[i][1];
		dc[a[i][0]]++;
	}
	
	memcpy(b, a, sizeof(a));
	BubbleSort(n, a);
	for(i = 0; n > i; i++){
		printf("%c%d", a[i][1], a[i][0]);
		if(i < n-1) printf(" ");
	}
	printf("\n");
	if(Check(n, a, d) == -1) printf("Not stable\n");
	else printf("Stable\n");

	memcpy(a, b, sizeof(a));
	SelectSort(n,a);
	for(i = 0; n > i; i++){
		printf("%c%d", a[i][1], a[i][0]);
		if(i < n-1) printf(" ");
	}
	printf("\n");
	if(Check(n, a, d) == -1) printf("Not stable\n");
	else printf("Stable\n");
	return 0;
}