//
// Created by Queen on 2017/2/10.
//

#ifndef INC_04_BUBBLE_SORT_SELECTIONSORT_H
#define INC_04_BUBBLE_SORT_SELECTIONSORT_H

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}


#endif //INC_04_BUBBLE_SORT_SELECTIONSORT_H
