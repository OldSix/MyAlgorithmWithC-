//
// Created by Queen on 2017/2/13.
//

#ifndef INC_03_QUICKSORT_MERGESORT_H
#define INC_03_QUICKSORT_MERGESORT_H

#include "InsertionSort.h"

template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
    T * aux = new T[r-l+1];
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }

    int i = l, j = mid+1;
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

    delete[] aux;
}

template <typename T>
void __mergeSort(T arr[], int l, int r)
{
    if (r-l<=15) {
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr, 0, n-1);
}

template <typename T>
void mergeSortBU(T arr[], int n)
{
//    for (int sz = 1; sz <= n; sz += sz) {
//        // 对 arr[i...i+sz-1] 和 arr[i+sz...i+sz+sz-1] 进行 merge 操作
//        for (int i = 0; i +sz < n; i += sz+sz) {
//            __merge(arr, i, i+sz-1, std::min(i+sz+sz-1, n-1));
//        }
//    }

    for( int i = 0 ; i < n ; i += 16 ) {
        insertionSort(arr, i, std::min(i + 15, n - 1));
    }

    for( int sz = 16; sz <= n ; sz += sz ) {
        for (int i = 0; i < n - sz; i += sz + sz) {
            if (arr[i + sz - 1] > arr[i + sz]) {
                __merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
            }
        }
    }
}



#endif //INC_03_QUICKSORT_MERGESORT_H
