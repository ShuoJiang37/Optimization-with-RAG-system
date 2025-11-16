#include <stdio.h>
#include <string.h>
#define N 36

int main(){
    int i, j, stability = 1, num, mini_j;
    char array_bub[N][3], array_sec[N][3], tmp[3];

    //input area
    scanf("%d", &num);
    for (i = 0; i<num; i++){
	scanf("%s", array_bub[i]);
	strcpy(array_sec[i], array_bub[i]);
    }

    //bubble sort area
    for (i = 0; i < num; i++){
	for (j = num-1; j >= i+1; j--){
	    if (array_bub[j-1][1] > array_bub[j][1]){
		//exchange value
		strcpy(tmp, array_bub[j]);
		strcpy(array_bub[j], array_bub[j-1]);
		strcpy(array_bub[j-1], tmp);
	    }
	}
    }

    //selection sort area
    for (i = 0; i < num; i++){
	mini_j = i;
	//find smallest value
	for (j = i+1; j < num; j++){
	    if (array_sec[j][1] < array_sec[mini_j][1])
		mini_j = j;
	}
	//exchange the values
	if (mini_j != i){
	    strcpy(tmp, array_sec[i]);
	    strcpy(array_sec[i], array_sec[mini_j]);
	    strcpy(array_sec[mini_j], tmp);
	}
    }

    //compare the results of bubble-sort and selection-sort
    for (i = 0; i < num; i++){
	if (strcmp(array_sec[i], array_bub[i]) != 0)
	    stability = 0;
    }

    //-----display area-----
    //bubble sort
    for (i = 0; i < num; i++){
	printf("%s", array_bub[i]);
	if (i < num-1)
	    printf(" ");
    }
    printf("\nStable\n");

    //selection sort
    for (i = 0; i < num; i++){
	printf("%s", array_sec[i]);
	if (i < num-1)
	    printf(" ");
    }
    if (stability == 1)
	printf("\nStable\n");
    else
	printf("\nNot stable\n");

    return 0;
}

