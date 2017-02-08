#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        // 寻找元素 arr[i] 合适的插入位置

    }
}

int main(void)
{
    int n = 10000;
    std::cout << "Test for Random Array, size = " << n << ", random range[0, " << n << "]" << std::endl;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    std::cout << std::endl;

    return 0;
}