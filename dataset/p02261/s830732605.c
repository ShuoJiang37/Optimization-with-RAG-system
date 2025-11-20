
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef 
struct {
  size_t index;
  char suit;
  int num;
} card;

void swap(card* p, size_t n, size_t m) {
  card t = {p[n].index,
    p[n].suit,
    p[n].num};

  p[n].index = p[m].index;
  p[n].suit = p[m].suit;
  p[n].num = p[m].num;

  p[m].index = t.index;
  p[m].suit = t.suit;
  p[m].num = t.num;
}


void bubble_sort(card* inout_arr, size_t n) {
  for (int p = 0; p < n; p++) {
    for (int q = n - 1; p < q; q--) {
      if (inout_arr[q].num < inout_arr[q - 1].num) {
        swap(inout_arr, q, q - 1);
      }
    }
  }
}

void selection_sort(card* p, size_t n) {
  for (int m = 0; m < n; m++) {
    int minj = m;

    for (int k = m; k < n; k++) {
      if (p[k].num < p[minj].num) {
        minj = k;
      }
    }

    swap(p, minj, m);
  }
}

void show_cards(card* in_arr, size_t n) {
  for (size_t m = 0; m < n - 1; m++) {
    printf("%c%d ", in_arr[m].suit, in_arr[m].num);
  }

  printf("%c%d\n", in_arr[n - 1].suit, in_arr[n - 1].num);
}

int stablep(card* in_arr, size_t n) {
  int rv = 1;
  
  for (int p = 1; p < n; p++) {
    if (in_arr[p - 1].num == in_arr[p].num) {
      if (in_arr[p].index < in_arr[p - 1].index) {
        rv = 0;
      }
    }
  }

  return rv;
}

void answer(card* in_p, size_t n) {
  show_cards(in_p, n);
  printf("%s\n", stablep(in_p, n) ? "Stable" : "Not stable");
}

int main() {
  int n = 0;

  scanf("%d\n", &n);

  card *p_cards = calloc(n, sizeof(card));
  card *p_bsort = calloc(n, sizeof(card));
  card *p_ssort = calloc(n, sizeof(card));
 
  for (int m = 0 ; m < n; m++) {
    char c;
    int k;
    
    scanf("%c%d ", &c, &k);
    p_cards[m].index = m;
    p_cards[m].suit = c;
    p_cards[m].num = k;
  }

  memmove(p_bsort, p_cards, n * sizeof(card));
  memmove(p_ssort, p_cards, n * sizeof(card));

  bubble_sort(p_bsort, n);
  answer(p_bsort, n);

  selection_sort(p_ssort, n);
  answer(p_ssort, n);

  free(p_ssort); p_ssort = NULL;
  free(p_bsort); p_bsort = NULL;
  free(p_cards); p_cards = NULL;

  return 0;
}

