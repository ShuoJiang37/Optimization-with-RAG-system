#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int num;
    char sign;
}Card;
void selctionSort( int n, Card *a);
void bubblesort(int number, Card card[number]);
void printArray(Card *card, int number);
int main(int argc, char** argv) {
    int number;
    int readScan = scanf("%d", &number);
    Card card[number];
    for(int i = 0; i< number; i++)
    {
        {
            int reaScan = scanf( " %c%d", &card[i].sign, &card[i].num);
        }
    }
    Card card2[number];
    for(int i=0; i< number; i++)
    {
        card2[i].num = card[i].num;
        card2[i].sign = card[i].sign;
    }
    
    
    bubblesort(number, card);
    printArray(card, number);
    printf("Stable\n");
    selctionSort( number, card2);  
    printArray(card2, number);
    int right=0;
    for(int i=0; i<number;i++)
    {
        if(card[i].sign != card2[i].sign)
        {
            right =1;
        }
    }
    if(right == 0)
    {
        printf("Stable\n");
    }
    
    if(right == 1)
    {
        printf("Not stable\n");
    }
    return (EXIT_SUCCESS);
}

void bubblesort(int number, Card *card)
{
    int c;
    char mark0;
    for (int i = 0; i < number; i++)
    {
	for (int j = 0; j < number-i-1; j++)
	{
        if (card[j].num>card[j+1].num)
	{
            c = card[j].num ;
            mark0 = card[j].sign;
            card[j].num = card[j+1].num;
            card[j].sign = card[j+1].sign;
            card[j+1].num =c;
            card[j+1].sign = mark0;			
        }
	}
    }
}

void selctionSort( int n, Card *a)
{
    int b;
    char mark;
    int min ;
    for (int i = 0; i < n-1; i++)
    {   
        min = i;
        for (int j = i+1; j < n; j++)
	{
            if (a[j].num < a[min].num)
            { 
                min = j;
            }   
        }  
        b= a[i].num;
        mark = a[i].sign;
        a[i].num=a[min].num;
        a[i].sign = a[min].sign;
        a[min].num=b;
        a[min].sign=mark;
       
    }
}

void printArray(Card *card, int number)
{
     for(int i= 0; i< number; i++)
    {    
        if(i<number-1)
        {
            printf("%c%d ", card[i].sign,card[i].num);
        }
        if(i==number-1)
        {
            printf("%c%d\n", card[i].sign,card[i].num);
        }
    }
}
