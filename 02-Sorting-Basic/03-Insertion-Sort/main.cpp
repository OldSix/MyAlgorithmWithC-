#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

int main(void)
{
    int n = 10000;

    // 测试1 一般测试
    std::cout << "Test for Random Array, size = " << n << ", random range[0, " << n << "]" << std::endl;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    std::cout << std::endl;

    // 测试2 有序性更强的测试
    std::cout << "Test for More Ordered Random Array, size = " << n << ", random range[0, 3]" << std::endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    std::cout << std::endl;

    // 测试3 测试近乎有序的数组
    int swaptime = 100;
    std::cout << "Test for Nearly Ordered Random Array, size = " << n << ", swap time = " << swaptime << std::endl;
    arr1 = SortTestHelper::generateNearlyOrderArray(n, swaptime);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    std::cout << std::endl;

    return 0;
}