//
// Created by Queen on 2017/2/10.
//

#ifndef INC_04_BUBBLE_SORT_SHELLSORT_H
#define INC_04_BUBBLE_SORT_SHELLSORT_H

/*
 * 简单地说：
 *
 *  插入排序每次都和相邻的元素作比较，希尔排序则每次隔一段距离作比较
 *  这段距离不断缩小，最后也变成1（也就是和相邻元素作比较）
 *  这样做让整个数组的有序性越来越强
 *  间隔化之后，数组有序化的可能性会增大，因为间隔化之后数量减少明显
 *  最大化的利用插入排序对近乎有序数组排序非常快的性质
 *
 * */

template <typename T>
void shellSort(T arr[], int n)
{
    int h = 1;
    while (h < n/3) {
        h = 3 * h + 1;
    }
    // 计算 increment sequence：1，4，13，40，121，364，1093...

    while (h >= 1) {

        // h-sort the array
        for (int i = h; i < n; ++i) {

            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]...使用插入排序
            T e = arr[i];
            int j;
            for (j = i; j >= h && arr[j-h] > e ; j -= h) {
                arr[j] = arr[j-h];
            }
            arr[j] = e;
        }

        h /= 3;
    }
}


#endif //INC_04_BUBBLE_SORT_SHELLSORT_H
