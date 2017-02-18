//
// Created by Queen on 2017/2/18.
//

#ifndef INC_04_INDEXMAXHEAP_HEAPSORTUSINGMAXHEAP_H
#define INC_04_INDEXMAXHEAP_HEAPSORTUSINGMAXHEAP_H

template <typename T>
void heapSort2(T arr[], int n)
{
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

    for (int i = n-1; i >= 0; --i) {
        arr[i] = maxHeap.extractMax();
    }
}


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
void __shiftDown(T arr[], int n, int k)
{
    while (2*k+1 < n) {
        int i = 2*k+1;
        if (i+1 < n && arr[i+1] > arr[i])
            i += 1;
        if (arr[k] >= arr[i])
            break;
        std::swap(arr[k], arr[i]);
        k = i;
    }
}

template <typename T>
void heapSort3(T arr[], int n)
{
    for (int i = n/2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }
    for (int j = n-1; j > 0; --j) {
        std::swap(arr[0], arr[j]);
        __shiftDown(arr, j, 0);
    }
}

#endif //INC_04_INDEXMAXHEAP_HEAPSORTUSINGMAXHEAP_H
