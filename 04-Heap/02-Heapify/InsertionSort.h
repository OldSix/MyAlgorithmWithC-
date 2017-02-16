//
// Created by Queen on 2017/2/16.
//

#ifndef INC_02_HEAPIFY_INSERTIONSORT_H
#define INC_02_HEAPIFY_INSERTIONSORT_H

template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; --j) {
            arr[j] = arr[j-1];
        }

        arr[j] = e;
    }
}


template <typename T>
void insertionSort(T arr[], int l, int r)
{
    for (int i = l+1; i <= r; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e ; --j) {
            arr[j-1] = arr[j];
        }

        arr[j] = e;
    }
}


#endif //INC_02_HEAPIFY_INSERTIONSORT_H
