//
// Created by Queen on 2017/2/9.
//

#ifndef INC_03_INSERTION_SORT_SELECTIONSORT_H
#define INC_03_INSERTION_SORT_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

#endif //INC_03_INSERTION_SORT_SELECTIONSORT_H
