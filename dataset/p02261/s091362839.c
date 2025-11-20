/* トランプのカードをソートするプログラム
   4つの絵柄(S,H,C,D)と1-9までの数字を組み合わせた36枚の
   カードを使う。

   N枚のカードを昇順に並び替える。
   その際、バブルソートと選択ソートのアルゴリズム2つを使う。
   更にそれらのソートの出力が安定的であるかどうか出力する。

   入力：
   一行目にカードの枚数N
   二行目に絵柄と数字与えられる。隣り合うカードはひとつの空白が与えられる。

   出力：
   一行目にバブルソートの結果
   二行目に出力が安定であるかどうか出力(Stable か Not stable)
   三行目に選択ソートの結果
   四行目に出力が安定的であるかどうか出力
*/

#include <stdio.h>
#include <stdbool.h> 

//カードの型
struct card {
   char suit;
   int  num;
};

//安定的であるかどうかの判定
bool isStable(struct card* in, struct card* out, int n)
{
   for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
         for (int a = 0; a < n; a++)
            for (int b = a+1; b < n; b++)
               //入力されているカードの数字が同じ場合 かつ
               //出力においてそのカードの数字の要素が昇順でない場合
               if (in[i].num == in[j].num && in[i].suit == out[b].suit && in[i].num == out[b].num
                   &&  in[j].suit == out[a].suit && in[j].num == out[a].num)
                  return false;

   return true;
}

//バブルソート
void Bubble(struct card* p, int n)
{
   struct card tmp;

   for (int i = 0; i < n; i++) {
      for (int j = n-1; j >= i+1; j--) {
         //隣り合うカードが昇順でない場合に、並び替える
         if (p[j].num < p[j-1].num) {
            tmp = p[j];
            p[j] = p[j-1];
            p[j-1] = tmp;
         }
      }
   }

   return;
}

//選択ソート
void Selection(struct card* p, int n)
{
   int minj;
   struct card tmp;

   for (int i = 0; i < n; i++) {
      minj = i;

      for (int j = i ; j < n; j++) {
         //最小値の要素を更新
         if (p[j].num < p[minj].num)
            minj = j;
      }
      tmp = p[i];
      p[i] = p[minj];
      p[minj] = tmp;
   }

   return;
}

int main()
{
   int n;
   scanf("%d", &n);

   struct card card[n];

   //改行文字を読み飛ばし
   getchar();

   //入力設定
   for (int i = 0; i < n; i++) {
      scanf("%c%d", &card[i].suit, &card[i].num);

      //スペース読み飛ばし
      getchar();
   }

   bool isstable;

   struct card bubble[n];
   struct card selection[n];

   //入力されたカードをそれぞれソートする入力値へ設定
   for (int i = 0; i < n; i++) {
      bubble[i] = card[i];
      selection[i] = card[i];
   }

   //バブルソートの実行
   Bubble(bubble, n);

   //安定的かどうかの判定
   isstable = isStable(card, bubble, n);

   //出力
   for (int i = 0; i < n; i++) {
      printf("%c%d", bubble[i].suit, bubble[i].num);
      if (i == n-1)
         printf("\n");
      else 
         printf(" ");
   }
   if (isstable == false)
      printf("Not stable\n");
   else if (isstable == true)
      printf("Stable\n");

   //選択ソートの実行
   Selection(selection, n);
   isstable = isStable(card, selection, n);

   //出力
   for (int i = 0; i < n; i++) {
      printf("%c%d", selection[i].suit, selection[i].num);
      if (i == n-1)
         printf("\n");
      else 
         printf(" ");
   }
   if (isstable == false)
      printf("Not stable\n");
   else if (isstable == true)
      printf("Stable\n");

   return 0;
}
