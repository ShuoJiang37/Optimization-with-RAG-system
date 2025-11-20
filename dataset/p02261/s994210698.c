#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 36

int main() {

	int i, j, n,flag = 0;
	int minj;
	char C[N][3],S[N][3],tmp[3];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", C[i]);
		strcpy(S[i], C[i]);
	}

	//BubleSort//

  for(i=0;i<n-1;i++){
   for(j=n-1;j>0;j--){
	 if(atoi(&C[j][1]) < atoi(&C[j-1][1])){
		 strcpy(tmp, C[j]);
	     strcpy(C[j],C[j-1]);
		 strcpy(C[j - 1], tmp);
	 }
   }
 }
 
  for (i = 0; i < n; i++) {
	  printf("%s", C[i]);
	  if (i != n - 1) printf(" "); 
	 }
	printf("\n");
	printf("Stable\n");

//SelectionSort

	for (i = 0; i < n - 1; i++) {
		minj = i;
		for (j = i; j < n ; j++) {
			if (atoi(&S[j][1]) < atoi(&S[minj][1])) {
				minj = j;
			}
		}
		strcpy(tmp, S[i]);
		strcpy(S[i], S[minj]);
		strcpy(S[minj], tmp);	
	}

	for (i = 0; i < n; i++) {
		printf("%s", S[i]);
		if (strcmp(S[i],C[i]) != 0) flag = 1;
		if (i != n - 1) printf(" ");
	}
	printf("\n");

	if (flag == 1) printf("Not stable\n");
	else printf("Stable\n");
}




