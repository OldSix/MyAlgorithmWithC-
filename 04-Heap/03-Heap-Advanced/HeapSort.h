//
// Created by Queen on 2017/2/16.
//

#ifndef INC_03_HEAP_ADVANCED_HEAPSORT_H
#define INC_03_HEAP_ADVANCED_HEAPSORT_H

#include "MaxHeap.h"

template <typename T>
void heapSort1(T arr[], int n)
{
    MaxHeap<int> maxHeap = MaxHeap<int>(n);
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
    MaxHeap<int> maxHeap = MaxHeap<int>(arr, n);

    for (int i = n-1; i >= 0; --i) {
        arr[i] = maxHeap.extractMax();
    }
}


template <typename T>
void __shiftDown3(T arr[], int n, int k)
{
    // 下标从 0 开始
    while (2*k+1 < n) {
        int i = 2*k+1;
        if (i+1 < n && arr[i+1] > arr[i]) {
            i += 1;
        }
        if (arr[k] >= arr[i]) break;
        std::swap(arr[k], arr[i]);

        k = i;
    }
}

template <typename T>
void heapSort3(T arr[], int n)
{
    // 成最大堆
    for (int i = (n-1-1)/2; i >= 0; --i) {
        __shiftDown3(arr, n, i);
    }

    // 每轮循环的过程：
    // 将最大堆的根节点（最大值，索引 0 的位置）与 数组的最后位置的元素 交换值
    // 此时最大值放在了数组的最后，此时[0...n-2] 又不是最大堆了，需要对索引 0 的位置进行 shiftDown 操作
    // 再次形成一个最大堆
    for (int j = n-1; j >= 0; --j) {
        std::swap(arr[0], arr[j]);
        __shiftDown3(arr, j, 0);
    }

}


#endif //INC_03_HEAP_ADVANCED_HEAPSORT_H
