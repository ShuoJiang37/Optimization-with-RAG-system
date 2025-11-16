#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 13
#define pi M_PI

int main(){
    int n;
    scanf("%d",&n);
    int card[100];
    for(int i=0;i<n;i++){
        scanf("%d",&card[i]);
        if(i) printf(" ");
        printf("%d",card[i]); 
    }
        printf("\n");
    for(int i=1;i<n;i++){
        int v=card[i];
        int j=i-1;
        while(j>=0&&card[j]>v){
            card[j+1]=card[j];
            j--;
        }
        card[j+1]=v;
        for(int k=0;k<n;k++){
            if(k) printf(" ");
            printf("%d",card[k]);
        }
        printf("\n");
    }
   return 0;
}
