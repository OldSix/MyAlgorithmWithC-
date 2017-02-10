#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"

int main(void)
{
    int n = 100000;

    // Test for Random Array
    std::cout << "Test Random Array size =" << n << ", random range [0, " << n << "]" << std::endl;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);
    int * arr3 = SortTestHelper::copyIntArray(arr1, n);
    int * arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    std::cout << std::endl;

    // Test for Random
    int swapTimes = 100;

    std::cout << "Test for Random Nearly Ordered Array, size =" << n << ", swap time =" << swapTimes << std::endl;

    arr1 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr2 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr3 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr4 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;


    return 0;
}