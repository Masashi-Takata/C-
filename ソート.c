#include <stdio.h>
#include <string.h>
#include <math.h>  //pow関数
#include <stdlib.h>  //qsort関数

void showData(int array[],int length);
void resetData(int array[], int array_tmp[], int length);
void bubble_sort(int array[],int length);
void select_sort(int array[],int length);
void insertion_sort(int array[],int length);
void shell_sort(int array[],int length);
void RadixSort(int x[ ], int n, int r);
void MergeSort(int x[ ], int left, int right);
void heap_sort(int a[ ], int n);
void DownHeap(int a[ ],  int top, int bottom);  //ヒープソート用
void Swap(int a[ ], int i, int j);  //ヒープソート用
void showData_heap_sort(int a[ ], int n);  //ヒープソート用
int compare(const void*,const void*);  //クイックソート用用

/* 数値を格納する配列 */
int array[100],array_tmp[100];
int max,digit=0,r; //基数ソート用
int a;
/* 数値の総数を入力 */
int total;

int main(void)
{
  printf("入力する数値の総数 = ");
  scanf("%d", &total);

  /* 配列に格納する数値を入力 */
  printf("%d個の数値を入力 = ", total);
  for (a=0; a<total; ++a)
  {
    scanf("%d", &array[a]);  //要素0から順に入力
    array_tmp[a] = array[a];
  }

//バブルソート実行
  bubble_sort(array,total);
//配列リセット
  resetData(array,array_tmp,total);

//選択ソート実行
  select_sort(array,total);
//配列リセット
  resetData(array,array_tmp,total);


//挿入ソート実行
  insertion_sort(array,total);
//配列リセット
  resetData(array,array_tmp,total);

//シェルソート実行
  shell_sort(array,total);
//配列リセット
  resetData(array,array_tmp,total);

//基数ソート実行
max = array[0];
for(a = 1; a < total; a++)
{
if (array[a] > max){
  max = array[a];
}
}
/* 桁数を計算 */
  while(max!=0){
    max = max / 10;
    ++digit;
  }
  digit = digit - 1;
  r = pow(10, digit);  /* ソートするデータから取り出す基数の上限 */

RadixSort(array, total, r);

//配列リセット
  resetData(array,array_tmp,total);

//マージソート実行
  printf("\n");
  printf("ーーーーーマージソートーーーーー\n");
  printf("ソート前：");
  showData(array,total);

  MergeSort(array, 0, total - 1);
for (a = 0; a < total; a++)
{
    printf("%d ", array[a]);
  }

  printf("\n");


//配列リセット
resetData(array,array_tmp,total);
//クイックソート実行
//マージソート実行
  printf("\n");
  printf("ーーーーークイックソートーーーーー\n");
  printf("ソート前：");
  showData(array,total);
qsort(array,total,sizeof(int),compare);
showData(array,total);


  return 0;
}

//  配列の表示
void showData(int array[],int length)
{
    int i;
    for(i = 0; i < length; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

//配列の初期化
void resetData(int array[], int array_tmp[], int length)
{
  int i;

  for (i=0; i<length; ++i)
    {
      array[i] = array_tmp[i];
    }
}



//バブルソート
void bubble_sort(int array[],int length)
{
  int i,j,tmp;
  printf("\n");
  printf("ーーーーーバブルソートーーーーー\n");
  printf("ソート前：");
  showData(array,length);
  for(i = 0;i < length-1 ; i++)
  {

      for(j = i+1; j < length ; j++)
      {
          if(array[i] < array[j])  //0番目の数字より一番目の数字の方が大きければ
          {
              //  値の入れ替え
              tmp = array[i];
              array[i] = array[j];
              array[j] = tmp;
              showData(array,length);
          }
      }
  }
}

//選択ソート
void select_sort(int array[],int length)
{
  int i,j,tmp,max_index;
  printf("\n");
  printf("ーーーーー選択ソートーーーーー\n");
  printf("ソート前：");
  showData(array,length);
  //  先頭の要素のループ
  for(i = 0;i < length-1 ; i++)
  {
      max_index = i;
      //  現在の状況で、最大の値の入っているインデックスの位置を探す
      for(j = i+1; j < length ; j++)
      {
          if(array[max_index] < array[j])
          {
              max_index = j;
          }
      }
      //  先頭要素より、大きい値があれば、入れ替える。
      if(max_index != i)
      {
              //  値の入れ替え
              tmp = array[i];
              array[i] = array[max_index];
              array[max_index] = tmp;
              //  配列の表示
              showData(array,length);
      }
  }
}

//挿入ソート
void insertion_sort(int array[],int length)
{
int i,j,tmp;
printf("\n");
printf("ーーーーー挿入ソートーーーーー\n");
printf("ソート前：");
showData(array,length);
for(i = 1; i < length; i++){
    j = i;
    //  定められた範囲内で、順序の入れ替えが必要な場合の処理
    while(j >= 1 && array[j-1] < array[j]){
        //  値の入れ替え
        tmp = array[j];
        array[j]  = array[j-1];
        array[j - 1] = tmp;
        j--;
    }
    showData(array,length);
  }
}

//シェルソート
void shell_sort(int array[],int length)
{
  printf("\n");
  printf("ーーーーーシェルソートーーーーー\n");
  printf("ソート前：");
  showData(array,length);
//  飛ばしていく数を設定
int i, j, step, tmp;
step = length / 2;
while (step > 0)
{
    //  途中結果の表示
    showData(array,length);
    for(i=0; i < length; i++)
    {
        j = i;
        tmp = array[i];
        //  順序が適切でなければ、並べ替えを行う
        while (j >= step && array[j - step] < tmp){
            array[j] = array[j - step];
            j -= step;
        }
        array[j] = tmp;
    }
    step /= 2;
}
//  最後にもう一度結果表示
showData(array,length);
}

//基数ソート
void RadixSort(int x[ ], int n, int r)  /* x[ ]：ソートするデータ */
{
  printf("\n");
  printf("ーーーーー基数ソートーーーーー\n");
  printf("ソート前：");
  showData(x,n);
  int i, j, k;                        /* r：基数を取り出す最大値 */
  int rad[100];    /* 基数をしまう配列  */
  static int y[100];      /* 作業用配列 */
  int m = 1;                          /* 基数を取り出す桁 */

  while (m <= r) {
      for (i = 0; i < n; i++)
          rad[i] = (x[i] / m) % 10;   /* 基数を取り出し rad[i] に保存 */

      k = 0;                          /* 配列の添字として使う */
      for (i = 9; i >= 0; i--)        /* 基数は 0 から 9 */
      //(i = 0; i <= 9; i++)に変えれば逆順にソートされる
          for (j = 0; j < n; j++)
              if (rad[j] == i)        /* 基数の大きいものから */
                  y[k++] = x[j];      /* y[ ] にコピー */

      for (i = 0; i < n; i++)
          x[i] = y[i];                /* x[ ] にコピーし直す */

        /*  途中経過を表示  */
      showData(x, n);

      m *= 10;                        /*  基数を取り出す桁を一つ上げる */
  }
}

//マージソート
/* 配列 x[ ] の left から right の要素のマージソートを行う */
void MergeSort(int x[ ], int left, int right)
{
  int mid, i, j, k;
  int temp[100];  /* 最小でも配列と同じサイズの領域が必要 */

  if (left >= right)              /* 配列の要素がひとつなら */
      return;                     /* 何もしないで戻る */

                                  /* ここでは分割しているだけ */
  mid = (left + right) / 2;       /* 中央の値より */
  MergeSort(x, left, mid);        /* 左を再帰呼び出し */
  MergeSort(x, mid + 1, right);   /* 右を再帰呼び出し */

    /* x[left] から x[mid] を作業領域にコピー */
  for (i = left; i <= mid; i++)
      temp[i] = x[i];

    /* x[mid + 1] から x[right] は逆順にコピー */
  for (i = mid + 1, j = right; i <= right; i++, j--)
      temp[i] = x[j];

  i = left;         /* i とj は作業領域のデーターを */
  j = right;        /* k は配列の要素を指している */

  for (k = left; k <= right; k++)    /* 小さい方から配列に戻す */
      if (temp[i] <= temp[j])        /* ここでソートされる */
          x[k] = temp[j--];  //ここをx[k] = temp[i++];に入れ替えたら逆順にソートされる
      else
      x[k] = temp[i++];

}

/* ヒープソート */
void heap_sort(int a[ ], int n)
{
  int leaf, root;

  leaf = n;                   /* 初期値は末尾の要素 */
  root = n/2;                 /* 初期値はその親 */

  while (root > 0 ) {         /* 半順序木を構成 */
      DownHeap(a, leaf, root);
      root--;
  }
  //printf("半順序木を構成:\n");
  //showData_heap_sort(a, NUM_DATA);      /* できあがった半順序木を表示 */

  while(leaf > 0) {
      Swap(a, 1, leaf);       /* 半順序木の根と末尾の要素を交換 */
      leaf--;                 /* 末尾の要素を半順序木から外す */
      DownHeap(a, leaf, 1);   /* 半順序木を再構成する */
  }
}

/* 半順序木 ( ヒープ ) を構成する */
void DownHeap(int a[ ],  int leaf, int root)
{
  int i;

  i = root * 2;
  while (i <= leaf) {
      if (i < leaf && a[i + 1] > a[i])  /* a[i] と a[i + 1]  の大きい方と */
          i++;
      if (a[root] >= a[i])              /* a[root] と比較 */
          break;                        /* 子の方が大きければ */
      Swap(a, root, i);                 /* 交換 */

      root = i;                         /* 更にその子についても調べる */
      i = root * 2;
  }
}

/* 配列の要素を交換する */
void Swap(int a[ ], int i, int j)
{
  int temp;

  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

/* 配列の要素を表示する */
void showData_heap_sort(int a[ ], int n)
{
  int i;

  for (i = 1; i <= n; i++) {
      printf("a[%2d] = %2d   ", i, a[i]);
      if(!(i % 5))  /* 要素を５つ表示したら改行 */
          printf("\n");
  }
  printf("\n");
}

//クイックソート
//  比較関数の実装
int compare(const void* n1,const void* n2)
{
    int y = *((int*)n1);  //xとyを入れ替えれば逆順にソート
    int x = *((int*)n2);
    if(x > y){
        return 1;
    }else if(x < y){
        return -1;
    }else{
        return 0;
    }
}
