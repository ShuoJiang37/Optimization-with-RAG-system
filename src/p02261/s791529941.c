#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    char name;
    int Val;
    int index;
}Dat;
/*
 * 
 */
int main(int argc, char** argv) {
    
    int Num;
    scanf("%d",&Num);
    Dat Card[Num];
    Dat Card2[Num];
    
    for(int a = 0; a < Num; a++){
        Card[a].index = a;
        scanf(" %c%d",&Card[a].name,&Card[a].Val);
        Card2[a].name = Card[a].name;
        Card2[a].Val = Card[a].Val;
        Card2[a].index = Card[a].index;
    }
    
    int swap = 0;
    Dat temp;
    for(int i = 0; i < Num - 1; i++){
       for(int j = 0; j <  Num - i - 1 ; j++){
          if(Card[j].Val > Card[j+1].Val){
              swap++;
              temp = Card[j+1];
              Card[j+1] = Card[j];
              Card[j] = temp;
              
          } 
       }   
    }
    
    
    for(int a = 0; a < Num; a++){
        
            printf("%c%d",Card[a].name,Card[a].Val);
            if(a < Num - 1){
                printf(" ");
            } 
    }
    
    int stable = 1;
    for(int a = 0; a < Num - 1; a++){
        if(stable == 0)break;
        if(Card[a].Val == Card[a + 1].Val){
           if(Card[a].index > Card[a + 1].index)stable = 0;
        }
    }
    
    if(stable == 1)printf("\nStable\n");
    if(stable == 0)printf("\nNot stable\n");
    
    Dat temp1;
    int min, k, exe;
    
    for(int i = 0; i < Num - 1; i++){
        min = i;
        exe = i;
       for(int j = i + 1; j <  Num; j++){
              if(Card2[exe].Val > Card2[j].Val){
                  exe = j;
              }
       }
        if(Card2[i].Val > Card2[exe].Val){
           temp1 = Card2[i];
           Card2[i] = Card2[exe];
           Card2[exe] = temp1;
        }
    }
    
    for(int a = 0; a < Num; a++){
        
            printf("%c%d",Card2[a].name,Card2[a].Val);
            if(a < Num - 1){
                printf(" ");
            } 
    }
    
    int stable2 = 1;
    for(int a = 0; a < Num - 1; a++){
        if(stable2 == 0)break;
        if(Card2[a].Val == Card2[a + 1].Val){
           if(Card2[a].index > Card2[a + 1].index)stable2 = 0;
        }
    }
    
    if(stable2 == 1)printf("\nStable\n");
    if(stable2 == 0)printf("\nNot stable\n");
    return (0);
}

