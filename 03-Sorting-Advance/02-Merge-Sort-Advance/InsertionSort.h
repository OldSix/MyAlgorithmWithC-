//
// Created by Queen on 2017/2/12.
//

#ifndef INC_02_MERGE_SORT_ADVANCE_INSERTIONSORT_H
#define INC_02_MERGE_SORT_ADVANCE_INSERTIONSORT_H

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
    for (int i = l; i <= r; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif //INC_02_MERGE_SORT_ADVANCE_INSERTIONSORT_H
