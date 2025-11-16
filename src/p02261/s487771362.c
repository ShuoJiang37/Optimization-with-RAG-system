#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SWAP(type, a, b)    do { type t = a; a = b; b = t; } while(0)

typedef struct {
    char suit;
    int number;
} Card;

bool isDlmChar(char c, char dlm);
int split(char** des, int desNum, char* src, char dlm);
void selectionSort(Card *array, int n);
void bubbleSort(Card *array, int n);
void copyCardArray(Card *des, Card *src, int n);
bool isEqualCardArray(Card *des, Card *src, int n);
bool isStableSort(Card *des, Card *src, int n);
void printCardArray(Card *array, int n);

bool isDlmChar(char c, char dlm) {
    return c == dlm || c == '\0';
}

int split(char** des, int desNum, char* src, char dlm) {
    int cnt = 0;
    int src_len = strlen(src);

    for(int i = 0; i < src_len && cnt < desNum; i++) {
        des[cnt++] = &src[i];
        while(!isDlmChar(src[i], dlm)) {
            i++;
        }
        src[i] = '\0';
    }

    return cnt;
}

void selectionSort(Card *array, int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(array[j].number < array[minIdx].number) {
                minIdx = j;
            }
        }
        SWAP(Card, array[i], array[minIdx]);
    }
}

void bubbleSort(Card *array, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(array[j].number > array[j + 1].number) {
                SWAP(Card, array[j], array[j + 1]);
            }
        }
    }
}

void copyCardArray(Card *des, Card *src, int n) {
    for(int i = 0; i < n; i++) {
        des[i] = src[i];
    }
}

bool isEqualCardArray(Card *des, Card *src, int n) {
    for(int i = 0; i < n; i++) {
        if(des[i].suit != src[i].suit) {
            return false;
        } if(des[i].number != src[i].number) {
            return false;
        }
    }

    return true;
}

bool isStableSort(Card *des, Card *src, int n) {
    Card *copySrc = malloc(n * sizeof(Card));

    if(copySrc == NULL) {
        return false;
    }

    copyCardArray(copySrc, src, n);

    bubbleSort(copySrc, n);

    bool ret = isEqualCardArray(copySrc, des, n);

    free(copySrc);
    return ret;
}

void printCardArray(Card *array, int n) {
    for(int i = 0; i < n;) {
        printf("%c%d", array[i].suit, array[i].number);
        i++;
        if(i < n) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    char buf[128];
    int n;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    Card *src = malloc(n * sizeof(Card));
    if(src == NULL) {
        return 1;
    }

    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf) - 1] = '\0';
    
    char **ptr;
    if((ptr = malloc(n * sizeof(char*))) == NULL) {
        return 1;
    }

    split(ptr, n, buf, ' ');
    for(int i = 0; i < n; i++) {
        sscanf(ptr[i], "%c%d", &src[i].suit, &src[i].number);
    }

    Card *copy = malloc(n * sizeof(Card));
    if(copy == NULL) {
        return 1;
    }

    copyCardArray(copy, src, n);
    bubbleSort(copy, n);
    printCardArray(copy, n);
    puts(isStableSort(copy, src, n) ? "Stable" : "Not stable");

    copyCardArray(copy, src, n);
    selectionSort(copy, n);
    printCardArray(copy, n);
    puts(isStableSort(copy, src, n) ? "Stable" : "Not stable");

    free(src);
    free(copy);
    free(ptr);
    return 0;
}
