#include <stdio.h>
void BubbleSort(int);
void SelectionSort(int);
 int n, c1[36], c2[36];
    char s1[36], s2[36];
int main(void){
   
   int i, flag = 0;
   char c;
    scanf("%d",&n);
    for (i = 0; i < n; i++){
         scanf("%c",&c);
        scanf("%c",&s1[i]);
        scanf("%d",&c1[i]);
        s2[i] = s1[i];
        c2[i] = c1[i];
    }
   
    BubbleSort(n);
    printf("Stable\n");
    SelectionSort(n);
    for(i=0;i<n;i++){
        if(s1[i] != s2[i]){
            flag = 1;
            break;
        }
     }
     if(flag == 1){
         printf("Not stable\n");
     }
     else printf("Stable\n");
    return 0;
}

void BubbleSort (int N){
    int i, j,tmp;
    char tmpc;
    for(i = 0; i < N-1; i++){
        for(j = N-1; j >= i+1; j--){
            if(c1[j] < c1[j-1]){
                tmp = c1[j];
                c1[j] = c1[j-1];
                c1[j-1] = tmp;
                tmpc = s1[j];
                s1[j] = s1[j-1];
                s1[j-1] = tmpc;
            }
        }
    }
    for(i = 0; i < n-1; i++){
    printf("%c%d ",s1[i],c1[i]);
    }
    printf("%c%d\n",s1[i],c1[i]);
}

void SelectionSort(int N){
    int i, minj,tmp,j;
    char tmpc;
    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(c2[j] < c2[minj]){
                minj = j;
            }
        }
                tmp = c2[i];
                c2[i] = c2[minj];
                c2[minj] = tmp;
                tmpc = s2[i];
                s2[i] = s2[minj];
                s2[minj] = tmpc;
            
        
    }
    for(i = 0; i < n-1; i++){
    printf("%c%d ",s2[i],c2[i]);
    }
    printf("%c%d\n",s2[i],c2[i]);
}