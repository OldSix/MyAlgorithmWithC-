#include <iostream>
#include "IndexMaxHeap.h"
#include "MaxHeap.h"
#include "HeapSortUsingMaxHeap.h"

template <typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n)
{
    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        indexMaxHeap.insert(i, arr[i]);
    }

    for (int j = n-1; j >= 0; --j) {
        arr[j] = indexMaxHeap.extractMax();
    }
}


int main(void)
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};

//    heapSortUsingIndexMaxHeap(arr, 10);
    heapSort3(arr, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}