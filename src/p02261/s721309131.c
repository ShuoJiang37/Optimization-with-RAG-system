#include <stdio.h>

struct CARD {
    char suits;
    int values;
};

int bubbleSort(int N, struct CARD *CB);
int selectionSort(int N, struct CARD *CS);
void judge(int flg);

int main() {                                    // main
    int N, flg;
    scanf("%d", &N);
    struct CARD CB[N], CS[N];
    
    
    for (int i=0; i<N; i++) {
        scanf("%*c%c%d", &CB[i].suits, &CB[i].values);
        CS[i].suits = CB[i].suits;
        CS[i].values = CB[i].values;
    }
    
    judge(bubbleSort(N, CB));
    judge(selectionSort(N, CS));
    
    return 0;
}

int bubbleSort(int N, struct CARD *CB) {        // bubble sort
    struct CARD DB[N];
    for (int x=0; x<N; x++) {
        DB[x] = CB[x];
    }
    
    for (int i=0; i<N; i++) {
        for (int j=N-1; j>i; j--) {
            if (CB[j].values < CB[j-1].values) {
                int tempInt = CB[j].values;      // values
                CB[j].values = CB[j-1].values;
                CB[j-1].values = tempInt;
                
                char tempChar = CB[j].suits;     // suits
                CB[j].suits = CB[j-1].suits;
                CB[j-1].suits = tempChar;
            }
        }
    }
    
    for (int k=0; k<N; k++) {                   // output
        printf("%c%d", CB[k].suits, CB[k].values);
        if (k == N - 1) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
    
    int t = 0, flg = 1;
    for (int s=0; s<N-1; s++) {                 // stable judge
        if (CB[s].values == CB[s+1].values) {
            while (t < N) {
                if (DB[t].values == CB[s].values) {
                    if (DB[t].suits == CB[s].suits) {
                        t++;
                        break;
                    } else {
                        flg = 0;
                        return flg;
                    }
                } else {
                    t++;
                }
            }
        } else {
            t = 0;
        }
    }
    return flg;
}

int selectionSort(int N, struct CARD *CS) {      // selection sort
    struct CARD DS[N];
    for (int x=0; x<N; x++) {
        DS[x] = CS[x];
    }
    
    for (int i=0; i<N; i++) {
        int min = i;
        for (int j=i; j<N; j++) {
            if (CS[j].values < CS[min].values) {min = j;}
        }
        
        int tempInt = CS[i].values;              // values
        CS[i].values = CS[min].values;
        CS[min].values = tempInt;
        
        char tempchar = CS[i].suits;             // suits
        CS[i].suits = CS[min].suits;
        CS[min].suits = tempchar;
    }
    
    for (int k=0; k<N; k++) {                   // output
        printf("%c%d", CS[k].suits, CS[k].values);
        if (k == N - 1) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
    
    int t = 0, flg = 1;
    for (int s=0; s<N-1; s++) {                 // stable judge
        if (CS[s].values == CS[s+1].values) {
            while (t < N) {
                if (DS[t].values == CS[s].values) {
                    if (DS[t].suits == CS[s].suits) {
                        t++;
                        break;
                    } else {
                        flg = 0;
                        return flg;
                    }
                } else {
                    t++;
                }
            }
        } else {
            t = 0;
        }
    }
    return flg;
}

void judge(int flg) {                       // stable judge output
    if (flg == 1) {printf("Stable\n");}
    else {printf("Not stable\n");}
    return;
}

