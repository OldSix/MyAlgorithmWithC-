//
// Created by Queen on 2017/2/14.
//

#ifndef INC_03_QUICKSORT_QUICKSORT3_H
#define INC_03_QUICKSORT_QUICKSORT3_H

#include "InsertionSort.h"
#include <iostream>
#include <algorithm>
#include <ctime>

template <typename T>
void __quickSort3(T arr[], int l, int r)
{
    if (r-l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // partition
    std::swap(arr[l], arr[rand() % (r-l+1)+l]);
    T v = arr[l];

    int lt = l;// arr[l+1, lt] < v
    int gt = r+1;// arr[gt, r] > v
    int i = l+1;// arr[lt+1, i) == v

    while (i < gt) {
        if (arr[i] < v) {
            std::swap(arr[i], arr[lt+1]);
            i++;
            lt++;
        } else if (arr[i] > v) {
            std::swap(arr[i], arr[gt-1]);
            gt--;
        } else {
            i++;
        }
    }

    std::swap(arr[l], arr[lt]);

    __quickSort3(arr, l, lt-1);
    __quickSort3(arr, gt, r);
}

template <typename T>
void quickSort3(T arr[], int n)
{
    srand((unsigned int)time(NULL));
    __quickSort3(arr, 0, n-1);
}


#endif //INC_03_QUICKSORT_QUICKSORT3_H
