//
// Created by Queen on 2017/2/11.
//

#ifndef INC_01_MERGE_SORT_INSERTIONSORT_H
#define INC_01_MERGE_SORT_INSERTIONSORT_H

template <typename T>
void insertion_sort(T arr[], int n)
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


#endif //INC_01_MERGE_SORT_INSERTIONSORT_H
