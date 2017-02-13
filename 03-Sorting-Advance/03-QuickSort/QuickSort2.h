//
// Created by Queen on 2017/2/13.
//

#ifndef INC_03_QUICKSORT_QUICKSORT2_H
#define INC_03_QUICKSORT_QUICKSORT2_H

// 对 arr[l...r] 部分进行 partion 操作
// 对 arr[l+1...i) <= v ; arr(j...r] >= v
template <typename T>
int __partition2(T arr[], int l, int r)
{
    std::swap(arr[l], arr[rand()%(r-l+1)+l]);
    T e = arr[l];

    int i = l;
    int j = r+1;

    while (true) {
        while (i <= r && arr[i] < e) ++i;
        while (j >= l+1 && arr[j] > e) --j;
        if (i > j) break;
        std::swap(arr[i], arr[j]);
        ++i;
        --j;
    }

    std::swap(arr[l], arr[j]);

    return j;
}

template <typename T>
void __quickSort2(T arr[], int l, int r)
{
    if (r-l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort(arr, l, p);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n)
{
    srand((unsigned int)time(NULL));

    __quickSort2(arr, 0, n-1);
}



#endif //INC_03_QUICKSORT_QUICKSORT2_H
