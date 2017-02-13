#include <iostream>
#include "MergeSort.h"
#include "ShellSort.h"
#include "SortTestHelper.h"


int main(void)
{
//    int arr[] = {10,9,8,7,6,5,4,3,2,1};
//    SortTestHelper::printArray(arr, 10);

    int n = 1000000;
    // n = 100万量级时，程序之间挂掉，因为 Process finished with exit code -1073741571 (0xC00000FD)
    // 因为mergesort使用了递归操作，100万量级造成了栈空间的异常

    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);
    int * arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Shell Sort", shellSort, arr1, n);
    SortTestHelper::testSort("merge Sort", mergeSort, arr2, n);
//    SortTestHelper::testSort("insertion Sort", insertionSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}