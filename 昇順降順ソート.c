/*
 * C言語のサンプルプログラム - Webkaru
 * - 配列に格納した数値を昇順ソート -
 */
#include <stdio.h>

int main(void)
{

  int i, j, tmp;

  /* 数値を格納する配列 */
  int number[100];

  /* 数値の総数を入力 */
  int total;
  printf("入力する数値の総数 = ");
  scanf("%d", &total);

  /* 配列に格納する数値を入力 */
  printf("%d個の数値を入力 \n", total);
  for (i=0; i<total; ++i)
  {
    scanf("%d", &number[i]);  //要素0から順に入力
  }

  /* 数値を昇順にソート */
  for (i=0; i<total; ++i)
   {
    for (j=i+1; j<total; ++j)
    {
      if (number[i] > number[j]) //０番目の数字が１番目よりも大きければ
       {
        tmp =  number[i];  //tmpに０番目の数字を一時的に置き換える
        number[i] = number[j];  //１番目の数字を０番目に持ってくる
        number[j] = tmp;  //１番目の数字を０番目の数字に持ってくる
      }
    }
  }

  /* 昇順ソートした数値を出力 */
  printf("\n");
  printf("昇順ソートした数値\n");
  for (i=0; i<total-1; ++i)
  {
    printf("%d<", number[i]);
  }
  printf("%d\n", number[total-1]);




  /* 数値を降順にソート */
  for (i=0; i<total; ++i) {
    for (j=i+1; j<total; ++j) {
      if (number[i] < number[j]) {
        tmp =  number[i];
        number[i] = number[j];
        number[j] = tmp;
      }
    }
  }

  /* 降順ソートした数値を出力 */
  printf("\n");
  printf("降順ソートした数値\n");
  for (i=0; i<total-1; ++i)
  {
    printf("%d>", number[i]);
  }
  printf("%d\n", number[total-1]);

}
