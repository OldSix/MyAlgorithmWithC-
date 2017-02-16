#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "Heap.h"

using namespace std;


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


int main(void)
{

    return 0;
}