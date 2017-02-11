//
// Created by Queen on 2017/2/11.
//

#ifndef INC_01_MERGE_SORT_MERGESORT_H
#define INC_01_MERGE_SORT_MERGESORT_H

#include "InsertionSort.h"

/*
 * 归并排序大致思路如下：
 *
 *  将数组二分，二分，直到分成只有一个元素的数组（可以简单的计算出层级其实就是log（N））
 *  然后对两个最小单位的数组进行合并操作
 *  直到完成全部的操作
 *
 *  这里再简单的说下Nlog（N）级别算法的简单思想其实就是：
 *      将序列分成log（N）的层级，再对每个层级进行O(N)级别的算法来处理
 * */



// 将 arr[l...mid] 和 arr[mid+1...r] 两部分进行归并
template <typename T>
void __mergeSort(T arr[], int l, int mid, int r)
{
    // 经测试，传递 aux数组的性能效果不好
    T aux[r-l+1];
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }

    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j-l];
            ++j;
        } else if (j > r) {
            arr[k] = aux[i-l];
            ++i;
        } else if (aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            ++i;
        } else {
            arr[k] = aux[j-l];
            ++j;
        }
    }
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int l, int r)
{
    if (l >= r) {
        return;
    }

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __mergeSort(arr, l, mid ,r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr, 0, n-1);
}


#endif //INC_01_MERGE_SORT_MERGESORT_H
