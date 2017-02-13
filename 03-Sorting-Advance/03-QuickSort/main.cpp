#include <iostream>
#include "InsertionSort.h"
#include "ShellSort.h"
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "QuickSort3.h"


int main(void)
{
    int n = 100000;

    // test random array
    std::cout << "test random array size : " << n << ", random range [ " << "0, " << n << " ]" << std::endl;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);
    int * arr3 = SortTestHelper::copyIntArray(arr1, n);
    int * arr4 = SortTestHelper::copyIntArray(arr1, n);
    int * arr5 = SortTestHelper::copyIntArray(arr1, n);
    int * arr6 = SortTestHelper::copyIntArray(arr1, n);
    int * arr7 = SortTestHelper::copyIntArray(arr1, n);

//    SortTestHelper::testSort("insertion sort", insertionSort, arr1, n);
    SortTestHelper::testSort("shell sort", shellSort, arr2, n);
    SortTestHelper::testSort("merge sort", mergeSort, arr3, n);
    SortTestHelper::testSort("merge sortBU", mergeSortBU, arr4, n);
    SortTestHelper::testSort("quick sort", quickSort, arr5, n);
    SortTestHelper::testSort("quick sort2", quickSort2, arr6, n);
    SortTestHelper::testSort("quick sort3", quickSort3, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;


    // test nearly ordered random array
    int swapTimes = 100;
    std::cout << "\ntest nearly ordered random array size : " << n << ", swapTimes is " <<  swapTimes << std::endl;

    arr1 = SortTestHelper::generateRandomNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("insertion sort", insertionSort, arr1, n);
    SortTestHelper::testSort("shell sort", shellSort, arr2, n);
    SortTestHelper::testSort("merge sort", mergeSort, arr3, n);
    SortTestHelper::testSort("merge sortBU", mergeSortBU, arr4, n);
    SortTestHelper::testSort("quick sort", quickSort, arr5, n);
    SortTestHelper::testSort("quick sort2", quickSort2, arr6, n);
    SortTestHelper::testSort("quick sort3", quickSort3, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;


    // test massive repeatedly random array
    std::cout << "\ntest massive repeatedly random array size : " << n << ", random range [ " << "0, 10 ]" << std::endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

//    SortTestHelper::testSort("insertion sort", insertionSort, arr1, n);
    SortTestHelper::testSort("shell sort", shellSort, arr2, n);
    SortTestHelper::testSort("merge sort", mergeSort, arr3, n);
    SortTestHelper::testSort("merge sortBU", mergeSortBU, arr4, n);
    SortTestHelper::testSort("quick sort", quickSort, arr5, n);
    SortTestHelper::testSort("quick sort2", quickSort2, arr6, n);
    SortTestHelper::testSort("quick sort3", quickSort3, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;


    return 0;
}