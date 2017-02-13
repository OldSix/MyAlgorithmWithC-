//
// Created by Queen on 2017/2/13.
//

#ifndef INC_03_QUICKSORT_QUICKSORT_H
#define INC_03_QUICKSORT_QUICKSORT_H

#include "InsertionSort.h"

// 对 arr[l...r] 部分进行 partion 操作
// 对 arr[l+1...j] < v ; arr[j+1...i-1] > v
template <typename T>
int __partition(T arr[], int l, int r)
{
    std::swap(arr[l], arr[rand()%(r-l+1)+l]);
    T e = arr[l];

    int j = l;
    for (int i = l+1; i <= r; ++i) {
        if (arr[i] < e) {
            std::swap(arr[i], arr[j+1]);
            ++j;
        }
    }

    std::swap(arr[l], arr[j]);

    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r)
{
    if (r-l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    srand((unsigned int)time(NULL));

    __quickSort(arr, 0, n-1);
}


#endif //INC_03_QUICKSORT_QUICKSORT_H
