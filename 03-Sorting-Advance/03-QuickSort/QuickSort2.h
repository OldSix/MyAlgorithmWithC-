//
// Created by Queen on 2017/2/13.
//

#ifndef INC_03_QUICKSORT_QUICKSORT2_H
#define INC_03_QUICKSORT_QUICKSORT2_H

// 对 arr[l...r] 部分进行 partion 操作
template <typename T>
int __partition2(T arr[], int l, int r)
{
    std::swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    // 初始化的条件：
    // 要保证最开始的区域范围内是没有值的，因为考察数据还没有开始。。
    // 比如：arr[l+1...i) <= v
    // 那么 i 的值为 l + 1 可以保证区域内初值为 0
    // 还有就是 i + 1， 区域也要随着变大，所以 i 的值肯定不能是 l
    // 再比如在第一个版本中：
    // j 的初始值为 l，因为 j 此时所保证的区间是 arr[l+1, j] < v
    // 所以 j 的初始值为 l+1 的话，那么区域内已经有一个值，就是 l+1 本身

    int i = l+1;// arr[l+1...i) <= v
    int j = r;// arr(j...r] >= v

    while (true) {
        while (i <= r && arr[i] < v) ++i;
        while (j >= l+1 && arr[j] > v) --j;
        if (i > j) break;
        std::swap(arr[i], arr[j]);
        ++i;
        --j;
    }
    // 循环结束时，应该满足这么几个条件：
    // 1. i > j
    // i : i 索引的位置是从前往后看，第一个 >= v 的值
    // j : j 索引的位置是从后往前看，最后一个 <= v 的值

    // l 的值为什么要跟 j 交换呢？
    // 其实跟 i 和 j 的大小关系都没有关系
    // 因为 l 的值是 v ，而且要被交换过来的值放置的区域是一个小于等于的区域，所以 显然 交换 j 过来要更合理，因为 i 此时下标的值 已经 >= v 了
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
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n)
{
    srand((unsigned int)time(NULL));

    __quickSort2(arr, 0, n-1);
}



#endif //INC_03_QUICKSORT_QUICKSORT2_H
