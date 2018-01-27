#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH  7

void quick_sort(int*,int);
void quick_sort_part(int*,int,int);
void swap(int*,int,int);
void showData(int*,int);

int main(void){
    int array[MAX_LENGTH] = { 4,2,5,6,1,9,3 };
    quick_sort(array,MAX_LENGTH);

    return 0;
}


//  クイックソート
void quick_sort(int* pArray,int size)
{
    quick_sort_part(pArray,0,size - 1);
}

//  部分クイックソート
void quick_sort_part(int* pArray,int left,int right){
    int i,j,pivot;
    // leftがright以上なら、処理終了
    if(left >= right){
        return;
    }
    pivot = pArray[left];   //  左端を軸に設定
    i = left;
    j = right;
    while(1){
        while(pArray[i] < pivot){
            i++;
        }
        while(pArray[j] > pivot){
            j--;
        }
        //  探索が終わったら、ループから抜ける
        if(i >= j){
            break;
        }
        //  入れ替え処理
        swap(pArray,j,i);
    }
    //  配列の表示
    showData(pArray,MAX_LENGTH);
    if (left < i - 1){
        //  基準値の左に 2 以上要素があれば左の配列を再帰的にソートする
        quick_sort_part(pArray, left, i - 1);
    }
    if (j + 1 <  right){
        // 基準値の右に 2 以上要素があれば右の配列を再帰的にソートする
        quick_sort_part(pArray, j + 1, right);
    }
}
//  値の入れ替え
void swap(int* pArray,int i,int j)
{
    int tmp = pArray[i];
    pArray[i] = pArray[j];
    pArray[j] = tmp;
}
//  配列の表示
void showData(int* array,int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
