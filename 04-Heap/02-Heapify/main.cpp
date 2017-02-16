#include <iostream>
#include "SortTestHelper.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSortThreeWays.h"
#include "InsertionSort.h"
#include "HeapSort.h"


int main(void)
{
    int n = 1000000;

    std::cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<std::endl;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);
    int * arr3 = SortTestHelper::copyIntArray(arr1, n);
    int * arr4 = SortTestHelper::copyIntArray(arr1, n);
    int * arr5 = SortTestHelper::copyIntArray(arr1, n);

//    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr4, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    std::cout << std::endl;

    //
    int swapTimes = 100;
    std::cout << "Test for Random Nearly Ordered Array, size = " << n << ", swapTimes = " << swapTimes << std::endl;
    arr1 = SortTestHelper::generateRandomNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr4, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr5, n);

    std::cout << std::endl;

    //
    std::cout << "Test for Random Massive Repeatedly Array, size = " << n << "random range [ 0, 10 ]" << std::endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);

//    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr4, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr5, n);

    std::cout << std::endl;

    return 0;
}