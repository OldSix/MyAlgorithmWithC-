#include <iostream>
#include "InsertionSort.h"
#include "SortTestHelper.h"
#include "MergeSort.h"

int main(void)
{
    int n = 10000;

    // Test Random Array
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertion_sort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);

    delete[] arr1;
    delete[] arr2;


    // Test Random Nearly Ordered Array
    int swaptimes = 100;
    arr1 = SortTestHelper::generateRandomNearlyOrderedArray(n, swaptimes);
    delete[] arr1;

    return 0;
}