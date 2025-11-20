#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, n, mini, stable=1;
    
    scanf("%d", &n);
    
    char s[n][2], t[n][2], tempA, tempC;
    
    for(i=0; i<n; i++){
        scanf("%s", s[i]);
        for(j=0; j<2; j++)
        	t[i][j] = s[i][j];
    }
    //bubble 
    for (i=0; i<n-1; i++){
        for (j = n-1; j>=i+1; j--){
        	if (s[j][1]<s[j-1][1]){
				tempA = s[j][1];
            	s[j][1] = s[j-1][1];
            	s[j-1][1] = tempA;
            	
            	tempC = s[j][0];
            	s[j][0] = s[j-1][0];
            	s[j-1][0] = tempC;
        	}
    	}
    }
    //selection
    for (i=0; i<n-1; i++){
    	mini = i;
        for (j = i; j<n; j++){
        	if (t[j][1]<t[mini][1]){
				mini = j;
        	}
    	}
    	//swap
    	if (mini!=i){
    		tempA = t[i][1];
        	t[i][1] = t[mini][1];
        	t[mini][1] = tempA;

			tempC = t[i][0];
            t[i][0] = t[mini][0];
            t[mini][0] = tempC;
    	}
    }
    
    for(i=0; i<n; i++){
    	printf("%c%c", s[i][0], s[i][1]);
    	if(i<n-1)
    		printf(" ");
    	else 
    		printf("\n");
    }
    printf("Stable\n");
	
	for(i=0; i<n; i++){
    	printf("%c%c", t[i][0], t[i][1]);
    	if(i<n-1)
    		printf(" ");
    	else 
    		printf("\n");
    }
    
    for (i=0; i<n; i++){
		if (s[i][0]!=t[i][0])
			stable = 0;
    }
    
    if(stable)
    	printf("Stable\n");
    else printf("Not stable\n");
    
    return 0;
}


