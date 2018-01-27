#include <stdio.h>
#include <string.h>

#define LIMIT 200  // ナップサックの重量制限値
#define N 10       // 品物の種類

struct Body
{
    char name[80];   // 品名
    int size;      // 重さ
    int price;     // 価格
};

struct Body a[N] = {
    { "1",  100, 610 },
    { "2",  31, 89 },
    { "3",  15, 32 },
    { "4",  41, 47 },
    { "5",  16, 18 },
    { "6",  39, 42 },
    { "7",  13, 12 },
    { "8",  68, 45 },
    { "9",  15,  5 },
    { "10", 10,  2 },
};

int b[N], max_b[N];
int max_value;

void knapsack(int i, int size, int value)
{
    if (size > LIMIT){
      return;
    }
    else if (i < N)
    {
        b[i] = 1;
        knapsack(i + 1, size + a[i].size, value + a[i].price);  //i番目の品の重さは a[i].size、価格はa[i].price
        b[i] = 0;
        knapsack(i + 1, size, value);
    }
    else
    {
        if (value > max_value)
        {
            max_value = value;
            for (int i = 0; i < N; i++)
            {
              max_b[i] = b[i];
            }
        }
    }
}

int main(void)
{
    knapsack(0, 0, 0);
    printf("品物：");
    for (int i = 0; i < N; i++)
        if (max_b[i])
        {
          printf("%s ", a[i].name);
        }
        printf("\n");
        printf("価格：%d\n", max_value);
        return 0;
}
