//
// Created by Queen on 2017/2/16.
//

#ifndef INC_02_HEAPIFY_HEAPSORT_H
#define INC_02_HEAPIFY_HEAPSORT_H

#include "MaxHeap.h"

template <typename T>
void heapSort(T arr[], int n)
{
    MaxHeap<T> maxHeap = MaxHeap<T>(n+1);
    for (int i = 0; i < n; ++i) {
        maxHeap.insertItem(arr[i]);
    }

    for (int j = n-1; j >= 0; --j) {
        arr[j] = maxHeap.extractMax();
    }
}


#endif //INC_02_HEAPIFY_HEAPSORT_H
