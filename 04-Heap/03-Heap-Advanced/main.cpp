#include <iostream>
#include "HeapSort.h"
#include "SortTestHelper.h"

int main(void)
{
    int n = 1000;
    int * arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = SortTestHelper::copyIntArray(arr1, n);
    int * arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("heap Sort1", heapSort1, arr1, n);
    SortTestHelper::testSort("heap Sort2", heapSort2, arr2, n);
    SortTestHelper::testSort("heap Sort3", heapSort3, arr3, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


    return 0;
}