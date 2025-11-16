#include <stdio.h>
#include <string.h>

#define CARD_NUM_MIN 1
#define CARD_NUM_MAX 36

typedef struct card_info
{
    char value;
    char mark;
}CARD;

void selection_sort(CARD *p_card, int size);
void bubble_sort(CARD *p_card, int size);
void swap(CARD *px, CARD *py);
void put_card_info(CARD *p_card, int size);
int get_card_info(CARD *p_card, int size);
int judge_mark(char ch);
int judge_card_number(char ch);
int get_int(int *p_num, int min, int max);
int judge_constraint(int test_num, int min, int max);

int main(void)
{
    int card_num;
    CARD card[CARD_NUM_MAX];
    CARD cpy[CARD_NUM_MAX];
    
    if(get_int(&card_num, CARD_NUM_MIN, CARD_NUM_MAX) == -1)
    {
        return -1;
    }    
    
    get_card_info(&card[0], card_num);
    
    memcpy(&cpy[0], &card[0], sizeof(CARD) * card_num);
    
    bubble_sort(&card[0], card_num);
    put_card_info(&card[0], card_num);
    printf("Stable\n");
    
    selection_sort(&cpy[0], card_num);
    put_card_info(&cpy[0], card_num);
    
    if(memcmp(&cpy[0], &card[0], sizeof(CARD) * card_num) != 0)
    {
        printf("Not stable\n");
    }
    else
    {
        printf("Stable\n");
    }
    
    return 0;
}

void bubble_sort(CARD *p_card, int size)
{
    int i;
    int j;
    
    for(i = 0; i < size; i++)
    {
        for(j = size - 1; j > i; j--)
        {
            if(p_card[j].value < p_card[j - 1].value)
            {
                swap(&p_card[j], &p_card[j - 1]);
            }
        }
    }
    
    return;
}

void selection_sort(CARD *p_card, int size)
{
    int i;
    int j;
    int min_idx;
    
    for(i = 0; i < size; i++)
    {
        min_idx = i;
        for(j = i + 1; j < size; j++)
        {
            if(p_card[j].value < p_card[min_idx].value)
            {
                min_idx = j;
            }
        }
        swap(&p_card[i], &p_card[min_idx]);
    }
    
    return;
}
void swap(CARD *px, CARD *py)
{
    CARD tmp = *px;
    *px = *py;
    *py = tmp;
     
    return;
}

void put_card_info(CARD *p_card, int size)
{
    int i;
    
    for(i = 0; i < size - 1; i++)
    {
        printf("%c%c ", p_card[i].mark, p_card[i].value);
    }
    printf("%c%c\n", p_card[size- 1].mark, p_card[size - 1].value);
}

int get_card_info(CARD *p_card, int size)
{
    int i = 0;
    int current;
    char ch;
    
    while((ch = getchar()) != '\n')
    {
        current = i % 3;
        switch(current)
        {
        case 0:
            if(judge_mark(ch) != -1)
            {
                p_card[i / 3].mark = ch;
            }
            else
            {
                return -1;
            }
            break;
        case 1:
            if(judge_card_number(ch) != -1)
            {
                p_card[i / 3].value = ch;
            }
            else
            {
                return -1;
            }
            break;
        case 2:
            if(ch != ' ')
            {
                return -1;
            }
            break;
        }
        
        i++;
        if(i / 3 >= size)
        {
            return -1;
        }
    }
    
    return 0;
}

int judge_mark(char ch)
{
    if((ch == 'S') || (ch == 'H') || (ch == 'C') || (ch == 'D'))
    {
        return 0;
    }
    
    return -1;
}


int judge_card_number(char ch)
{
    if((ch < '1') || (ch > '9'))
    {
        return -1;
    }
    
    return 0;
}
 
int get_int(int *p_num, int min, int max)
{
    scanf("%d%*c", p_num);
     
    if(judge_constraint(*p_num, min, max) == -1)
    {
        return -1;
    }
     
    return 0;
}
int judge_constraint(int test_num, int min, int max)
{
    if(test_num < min || test_num > max)
    {
        return -1;
    }
     
    return 0;
}