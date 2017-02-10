//
// Created by Queen on 2017/2/10.
//

#ifndef INC_04_BUBBLE_SORT_BUBBLESORT_H
#define INC_04_BUBBLE_SORT_BUBBLESORT_H

template <typename T>
void bubbleSort(T arr[], int n)
{
    bool swapped;

    do {
        swapped = false;

        for (int i = 1; i < n; ++i) {
            if (arr[i-1] > arr[i]) {// 如果前一个数比后一个数大，那么交换两个数的位置，因为升序排列，前小后大
                std::swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }
        n--;
    } while(swapped);
}


#endif //INC_04_BUBBLE_SORT_BUBBLESORT_H
