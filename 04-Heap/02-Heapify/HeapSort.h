//
// Created by Queen on 2017/2/16.
//

#ifndef INC_02_HEAPIFY_HEAPSORT_H
#define INC_02_HEAPIFY_HEAPSORT_H

#include "MaxHeap.h"

template <typename T>
void heapSort(T arr[], int n)
{
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        maxHeap.insertItem(arr[i]);
    }

    for (int j = n-1; j >= 0; --j) {
        arr[j] = maxHeap.extractMax();
    }
}


template <typename T>
void heapSort2(T arr[], int n)
{
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

    for (int i = n-1; i >= 0; --i) {
        arr[i] = maxHeap.extractMax();
    }
}

template <typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2*k+1 < n) {
        int j = 2*k+1;
        if (j+1 < n && arr[j+1] > arr[j]) {
            j += 1;
        }

        if (arr[k] >= arr[j]) break;
        std::swap(arr[k], arr[j]);
        k = j;
    }
}

// 原地排序
template <typename T>
void heapSort3(T arr[], int n)
{
    // heapify
    for (int i = (n-1-1)/2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }

    for (int j = n-1; j > 0; --j) {
        std::swap(arr[0], arr[j]);
        __shiftDown(arr, j, 0);
    }
}



#endif //INC_02_HEAPIFY_HEAPSORT_H
