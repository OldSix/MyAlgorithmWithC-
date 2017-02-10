#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

template <typename T>
void bubbleSort(T arr[], int n)
{
    bool swapped;

    do {
        swapped = false;

        for (int i = 1; i < n; ++i) {
            if (arr[i-1] > arr[i]) {// 如果前一个数比后一个数大，那么交换两个数的位置，因为升序排列，前小后大
                std::swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }
        n--;
    } while(swapped);
}


int main(void)
{
    int n = 100000;

    // Test for Random Array
    std::cout << "Test Random Array size =" << n << ", random range [0, " << n << "]" << std::endl;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);
    int * arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    std::cout << std::endl;

    // Test for Random
    int swapTimes = 100;

    std::cout << "Test for Random Nearly Ordered Array, size =" << n << ", swap time =" << swapTimes << std::endl;

    arr1 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr2 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr3 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


    return 0;
}