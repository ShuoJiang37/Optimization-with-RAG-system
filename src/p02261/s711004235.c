#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct Card
{
    char suit, value;
};

void bublleSort(struct Card a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j].value < a[j - 1].value)
            {
                struct Card v = a[j];
                a[j] = a[j - 1];
                a[j - 1] = v;
            }
        }
    }
}

void selectionSort(struct Card a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minj = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j].value < a[minj].value)
            {
                minj = j;
            }       
        }
        struct Card v = a[i];
        a[i] = a[minj];
        a[minj] = v;
    }
}

bool isStable(struct Card card1[], struct Card card2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (card1[i].suit != card2[i].suit)
        {
            return false;
        }
    }
    return true;
}

void print(struct Card card[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%c%c", card[i].suit, card[i].value);
    }
    printf("\n");
}

int main()
{
    struct Card card1[100], card2[100];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &card1[i].suit);
        scanf(" %c", &card1[i].value);
    }

    for (int i = 0; i < n; i++)
    {
        card2[i].suit = card1[i].suit;
        card2[i].value = card1[i].value;
    }
    
    bublleSort(card1, n);
    selectionSort(card2, n);

    print(card1, n);
    printf("Stable\n");
    print(card2, n);
    
    if (isStable(card1, card2, n))
    {
        printf("Stable\n");
    } else
    {
        printf("Not stable\n");
    }

    return 0;
}
