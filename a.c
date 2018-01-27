/*
 * C言語のサンプルプログラム - Webkaru
 * - 入力した数値の桁数を表示 -
 */
#include <stdio.h>

int main(void)
{
  /* 変数の宣言 */
  int number;
  int digit = 0;

  /* 数値の入力 */
  printf("数値 = ");
  scanf("%d", &number);

  /* 桁数を計算 */
  while(number!=0){
    number = number / 10;
    ++digit;
  }

  /* 数値の桁数を表示 */
  printf("桁数 = %d\n", digit);

  return 0;
}
