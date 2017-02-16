//
// Created by Queen on 2017/2/16.
//

#ifndef INC_02_HEAPIFY_QUICKSORTTHREEWAYS_H
#define INC_02_HEAPIFY_QUICKSORTTHREEWAYS_H

#include <algorithm>
#include <ctime>
#include <iostream>

template <typename T>
void __quickSort(T arr[], int l, int r)
{
    if (r-l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // partition
    std::swap(arr[l], arr[rand() % (r-l+1)+l]);
    T v = arr[l];

    int lt = l; // arr[l+1...lt] < v
    int gt = r+1; // arr[gt...r] > v
    int i = l+1; // arr[lt+1...i) == v

    while(i < gt) {
        if (arr[i] < v) {
            std::swap(arr[i], arr[lt+1]);
            ++lt;
            ++i;
        } else if (arr[i] > v) {
            std::swap(arr[i], arr[gt-1]);
            --gt;
        } else { // arr[i] == v
            ++i;
        }
    }

    std::swap(arr[l], arr[lt]);

    __quickSort(arr, l, lt-1);
    __quickSort(arr, gt, r);

}

template <typename T>
void quickSort(T arr[], int n)
{
    srand((unsigned int)time(NULL));
    __quickSort(arr, 0, n-1);
}


#endif //INC_02_HEAPIFY_QUICKSORTTHREEWAYS_H
